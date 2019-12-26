%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int lab_num = -1;
  FILE *output;
  int vars_to_inc[100];
  int var_num_to_inc = 0;
  int case_var;
  int case_lit[100];
  int case_num = 0;
  int lvl = 0;

%}

%union {
  int i;
  char *s;
}

%token <i> _TYPE
%token _IF
%token _ELSE
%token _RETURN
%token <s> _ID
%token <s> _INT_NUMBER
%token <s> _UINT_NUMBER
%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _ASSIGN
%token _SEMICOLON
%token <i> _AROP
%token <i> _MDROP
%token <i> _RELOP
%token _PLUSPLUS
%token _QMARK
%token _COLON
%token _FOR
%token _SWITCH _CASE _DEFAULT _BREAK
%token _WHILE
%token _DO
%token _TO _DOWNTO _STEP _NEXT
%token _ITERATE
%token _INRANGE
%token _COMMA

%type <i> num_exp exp literal
%type <i> function_call argument rel_exp if_part conditional_operator stmt direction maybe_step maybe_lit

%nonassoc ONLY_IF
%nonassoc _ELSE

%left _AROP
%left _MDROP

%%

program
  : global_variables function_list
      {
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
  ;

global_variables
  : /**/
  | global_variables global_vars
  ;

global_vars
  : _TYPE _ID _SEMICOLON
      {
        int idx = lookup_symbol($2, GLOB);
        if (idx == NO_INDEX)
          {
            insert_symbol($2, GLOB, $1, NO_ATR, NO_ATR);
          }
        else
          {
            err("redefinition of global variable");
          }

        code("\n%s:", $2);
        code("\t\tWORD\t1");
      }
  ;

function_list
  : function
  | function_list function
  ;

function
  : _TYPE _ID
      {
        fun_idx = lookup_symbol($2, FUN|GLOB);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR);
        else
          err("redefinition of function '%s'", $2);

        code("\n%s:", $2);
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
    _LPAREN parameter _RPAREN body
      {
        clear_symbols(fun_idx + 1);
        var_num = 0;

        code("\n@%s_exit:", $2);
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
  ;

parameter
  : /* empty */
      { set_atr1(fun_idx, 0); }

  | _TYPE _ID
      {
        insert_symbol($2, PAR, $1, 1, NO_ATR);
        set_atr1(fun_idx, 1);
        set_atr2(fun_idx, $1);
      }
  ;

body
  : _LBRACKET variable_list
      {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      }
    statement_list _RBRACKET
  ;

variable_list
  : /* empty */
  | variable_list variable
  ;

variable
  : _TYPE _ID _SEMICOLON
      {
        if(lookup_symbol($2, VAR|PAR) == NO_INDEX)
           insert_symbol($2, VAR, $1, ++var_num, NO_ATR);
        else
           err("redefinition of '%s'", $2);
      }
  ;

statement_list
  : /* empty */
  | statement_list statement
  ;

statement
  : compound_statement
  | assignment_statement
  | if_statement
  | return_statement
  | postincrement_statement
  | for_statement
  | case_statement
  | while_statement
  | do_while_statement
  | basic_for
  | iterating_statement
  | for_with_def
  | for_in_range
  ;

compound_statement
  : _LBRACKET statement_list _RBRACKET
  ;

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($1, VAR|PAR|GLOB);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", $1);
        else
          if(get_type(idx) != get_type($3))
            err("incompatible types in assignment");

        for (int i = 0; i < var_num_to_inc; i++) {
          int idx = vars_to_inc[i];
          code("\n\t\t%s ", ar_instructions[ADD + (get_type(idx) - 1) * AROP_NUMBER]);
          gen_sym_name(idx);
          code(", $1, ");
          gen_sym_name(idx);
        }
        var_num_to_inc = 0;
        gen_mov($3, idx);
      }
  ;

iterating_statement
  : _ITERATE _ID
    {
      int idx = lookup_symbol($2, VAR|PAR|GLOB);
      if (idx == NO_INDEX)
        err("'%s' undeclared", $2);
      code("\n\t\tMOV $1, ");
      gen_sym_name(idx);

      lab_num++;
      code("\n@iterate%d:", lab_num);
      $<i>$ = lab_num;
    }

  _STEP literal _TO literal
    {

      int idx = lookup_symbol($2, VAR|PAR|GLOB);
      if (get_type(idx) != get_type($5) || get_type(idx) != get_type($7))
        err("incompatible types");
      if (get_type(idx) == INT)
        code("\n\t\tCMPS\t");
      else
        code("\n\t\tCMPU\t");
      gen_sym_name(idx);
      code(", ");
      gen_sym_name($7);
      code("\n\t\tJGTS @iterateexit%d", $<i>3);
    }

  statement
    {

      int idx = lookup_symbol($2, VAR|PAR|GLOB);
      if(get_type(idx) == INT)
        code("\n\t\tADDS\t");
      else
        code("\n\t\tADDU\t");
      gen_sym_name(idx);
      code(", $%d, ", atoi(get_name($7)));
      gen_sym_name(idx);
      code("\n\t\tJMP @iterate%d", $<i>3);

      code("\n@iterateexit%d:", $<i>3);

    }
  ;

for_in_range
  : _FOR _ID
      {
        int idx = lookup_symbol($2,VAR|PAR|GLOB);
        if (idx == NO_INDEX)
          err("'%s' undeclared", $2);

      }

  _INRANGE _LPAREN literal _COMMA literal
    {
      int idx = lookup_symbol($2,VAR|PAR|GLOB);
      if (get_type($6) != get_type(idx) || get_type($8) != get_type(idx))
        err("incompatible types in for in range");
      gen_mov($6, idx);
      lab_num++;
      code("\n@for_in_range%d:", lab_num);
      if(get_type(idx) == INT)
          code("\n\t\tCMPS\t");
      else
          code("\n\t\tCMPU\t");
      gen_sym_name($8);
      code(", ");
      gen_sym_name(idx);

      if(atoi(get_name($6)) < atoi(get_name($8)))
        code("\n\t\tJGTS @for_in_range_exit%d", lab_num);
      else
        code("\n\t\tJLTS @for_in_range_exit%d", lab_num);

      $<i>$ = lab_num;
    }

  maybe_lit _RPAREN statement

    {

      int idx = lookup_symbol($2,VAR|PAR|GLOB);
      if(get_type(idx) == INT)
        {
          if($10 == -1)
          {
            if (atoi(get_name($6)) < atoi(get_name($8)))
              {
                code("\n\t\t%s\t", ar_instructions[ADD + (get_type(idx) - 1) * AROP_NUMBER]);
                gen_sym_name(idx);
                code(", $1, ");
                gen_sym_name(idx);
              }
              else
              {
                code("\n\t\t%s\t", ar_instructions[SUB + (get_type(idx) - 1) * AROP_NUMBER]);
                gen_sym_name(idx);
                code(", $1, ");
                gen_sym_name(idx);
              }
          }
          else
          {
          if (atoi(get_name($6)) < atoi(get_name($8)))
            {
              code("\n\t\t%s\t", ar_instructions[ADD + (get_type(idx) - 1) * AROP_NUMBER]);
              gen_sym_name(idx);
              code(", $%d, ", atoi(get_name($10)));
              gen_sym_name(idx);
            }
            else
            {
              code("\n\t\t%s\t", ar_instructions[SUB + (get_type(idx) - 1) * AROP_NUMBER]);
              gen_sym_name(idx);
              code(", $%d, ", atoi(get_name($10)));
              gen_sym_name(idx);
            }
          }
        }
      code("\n\t\tJMP @for_in_range%d", $<i>9);
      code("\n@for_in_range_exit%d:", $<i>9);
    }
  ;

maybe_lit
  : /**/
      {
        $$ = -1;
      }
  | _COMMA literal
      {
        $$ = atoi(get_name($2));
      }
  ;
postincrement_statement
  : _ID _PLUSPLUS _SEMICOLON
    {
        int idx = lookup_symbol($1, VAR|PAR|GLOB);
        if(idx == NO_INDEX)
          {
            err("undefined %s", $1);
          }
        else
          {
            code("\n\t\t%s\t", ar_instructions[ADD + (get_type(idx) - 1)*AROP_NUMBER]);
            gen_sym_name(idx);
            code(",$1,");
            gen_sym_name(idx);
          }
    }
  ;

num_exp
  : exp

  | num_exp _AROP num_exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: arithmetic operation");
        int t1 = get_type($1);
        code("\n\t\t%s\t", ar_instructions[$2 + (t1 - 1) * AROP_NUMBER]);
        gen_sym_name($1);
        code(",");
        gen_sym_name($3);
        code(",");
        free_if_reg($3);
        free_if_reg($1);
        $$ = take_reg();
        gen_sym_name($$);
        set_type($$, t1);
      }
  | num_exp _MDROP num_exp
     {
     {
       if (get_type($1) != get_type($3))
          {
            err("invalid operands : Arithmetic operation");
          }
          int type = get_type($1);

          code("\n\t\t%s\t", ar_instructions[$2 + (type - 1) * AROP_NUMBER]);
          gen_sym_name($1);
          code(",");
          gen_sym_name($3);
          code(",");
          free_if_reg($3);
          free_if_reg($1);
          $$ = take_reg();
          gen_sym_name($$);
          set_type($$, type);

     }
     }
  ;

exp
  : literal

  | _ID
      {
        $$ = lookup_symbol($1, VAR|PAR|GLOB);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
      }

  | function_call
      {
        $$ = take_reg();
        gen_mov(FUN_REG, $$);
      }

  | _LPAREN num_exp _RPAREN
      { $$ = $2; }
  | _ID _PLUSPLUS
     {
      $$ = lookup_symbol($1, VAR|PAR|GLOB);
      if ($$ == NO_INDEX)
        err("'%s' undeclared", $1);

      vars_to_inc[var_num_to_inc++] = $$;

     }
  | conditional_operator
  ;

basic_for
  : _FOR _ID _ASSIGN
    {
      int idx = lookup_symbol($2, VAR|PAR|GLOB);

      if (idx == NO_INDEX)
        err("'%s' undefined", $2);

    }
  literal direction literal
    {
      int idx = lookup_symbol($2, VAR|PAR|GLOB);
      if (get_type(idx) != get_type($5) && get_type($5) != get_type($7))
          err("incompatible types in basic for statement");
      if ($6 == 1)
        {
          if(atoi(get_name($5)) > atoi(get_name($7)))
            {
              err("wrong direction");
            }
        }
        else {
          if(atoi(get_name($5)) < atoi(get_name($7)))
            {
              err("wrong direction");
            }
        }
        ++lab_num;
        code("\n@basicfor%d:", lab_num);
        $<i>$ = lab_num;
        gen_mov($5, idx);
    }

  maybe_step
    {
      code("\n@forstmt%d:", $<i>8);
    }

  statement _NEXT
    {
      int idx = lookup_symbol($2, VAR|PAR|GLOB);
      if ($6 == 1)

      {
        code("\n\t\t%s\t", ar_instructions[ADD + (get_type(idx) - 1) * AROP_NUMBER]);
        gen_sym_name(idx);
        code(", $%d, ", $9);
        gen_sym_name(idx);

        if (get_type(idx) == INT) {
          code("\n\t\tCMPS\t");
          gen_sym_name(idx);
          code(", ");
          gen_sym_name($7);
          code("\n\t\tJLES @forstmt%d", $<i>8);

        }
        else
          {
          code("\n\t\tCMPU\t");
          gen_sym_name(idx);
          code(", ");
          gen_sym_name($7);
          code("\n\t\tJLES @forstmt%d", $<i>8);
          }
      }
      else
      {

        code("\n\t\t%s\t", ar_instructions[SUB + (get_type(idx) - 1) * AROP_NUMBER]);
        gen_sym_name(idx);
        code(", $%d, ", $9);
        gen_sym_name(idx);

        if (get_type(idx) == INT) {
          code("\n\t\tCMPS\t");
          gen_sym_name(idx);
          code(", ");
          gen_sym_name($7);
          code("\n\t\tJGES @forstmt%d", $<i>8);

        }
        else
          {
          code("\n\t\tCMPU\t");
          gen_sym_name(idx);
          code(", ");
          gen_sym_name($7);
          code("\n\t\tJGES @forstmt%d", $<i>8);
          }
      }
    }
    _SEMICOLON
      {
        code("\n@forbasicexit%d:", $<i>8);
      }
  ;

direction
  : _TO
    {
      $$ = 1;
    }
  | _DOWNTO
    {
      $$ = 2;
    }
  ;

maybe_step
  : /**/
    {
      $$ = 1;
    }
  | _STEP literal
    {
      $$ = atoi(get_name($2));
    }
  ;

literal
  : _INT_NUMBER
      { $$ = insert_literal($1, INT); }

  | _UINT_NUMBER
      { $$ = insert_literal($1, UINT); }
  ;

for_with_def
  : _FOR _LPAREN _TYPE _ID _ASSIGN literal
    {
      int idx = lookup_symbol($4, VAR|PAR|GLOB);
      if ($3 != get_type($6))
        err("incompatible types in for with def");
      lvl++;
      if (idx == NO_INDEX)
        {
          idx = insert_symbol($4, VAR, $3, ++var_num, lvl);
        }
      else if(get_atr2(idx) != lvl)
        idx = insert_symbol($4, VAR, $3, ++var_num, lvl);
      else
        {
        err("already defined");
        lvl = 0;
        }
        $<i>$ = idx;
        gen_mov($6, idx);
        code("\n@fordef%d:", idx);

    }

   _SEMICOLON rel_exp
      {
        code("\n\t\t%s @fordefexit%d", opp_jumps[$9], $<i>7);
      }

    _SEMICOLON _ID _PLUSPLUS _RPAREN
      {
        int idx1 = lookup_symbol($12, VAR|PAR|GLOB);
        int idx2 = lookup_symbol($4, VAR|PAR|GLOB);
        if (idx1 != idx2)
          err("not the same variable");

        code("\n\t\t%s\t", ar_instructions[ADD + (get_type(idx1) - 1) * AROP_NUMBER]);
        gen_sym_name(idx1);
        code(", $1, ");
        gen_sym_name(idx1);

      }
    statement
    {
      code("\n\t\tJMP @fordef%d", $<i>7);

      code("\n@fordefexit%d:", $<i>7);
      clear_symbols($<i>7);
    }
  ;

function_call
  : _ID
      {
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", $1);
      }
    _LPAREN argument _RPAREN
      {
      for (int i = 0; i < var_num_to_inc; i++) {
        int idx = vars_to_inc[i];
        code("\n\t\t%s ", ar_instructions[ADD + (get_type(idx) - 1) * AROP_NUMBER]);
        gen_sym_name(idx);
        code(", $1, ");
        gen_sym_name(idx);
      }
      var_num_to_inc = 0;

        if(get_atr1(fcall_idx) != $4)
          err("wrong number of arguments");
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if($4 > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", $4 * 4);


        set_type(FUN_REG, get_type(fcall_idx));
        $$ = FUN_REG;
      }
  ;

argument
  : /* empty */
    { $$ = 0; }

  | num_exp
    {
      if(get_atr2(fcall_idx) != get_type($1))
        err("incompatible type for argument");
      free_if_reg($1);
      code("\n\t\t\tPUSH\t");
      gen_sym_name($1);
      $$ = 1;
    }
  ;

do_while_statement
  : _DO
    {
      lab_num++;
      $<i>$ = lab_num;
      code("\n@dowhile%d:", lab_num);
    }
   statement _WHILE _LPAREN rel_exp _RPAREN _SEMICOLON
   {
    code("\n\t\t%s\t@dowhileexit%d", opp_jumps[$6], $<i>2);
    code("\n\t\tJMP @dowhile%d", $<i>2);
    code("\n@dowhileexit%d:", $<i>2);
   }
  ;

while_statement
  : _WHILE
    {
      lab_num++;
      code("\n@while%d:", lab_num);
      $<i>$ = lab_num;
    }
  _LPAREN rel_exp
    {

      code("\n\t\t%s @whilexit%d", opp_jumps[$4], $<i>2);

    }
  _RPAREN statement
    {
      code("\n\t\t JMP @while%d", $<i>2);
      code("\n@whilexit%d:", $<i>2);
    }
  ;

conditional_operator
  : _LPAREN rel_exp _RPAREN _QMARK stmt _COLON stmt
    {
      if(get_type($5) != get_type($7))
        err("incompatible types");

      ++lab_num;
      code("\n\t\t%s @false%d", opp_jumps[$2], lab_num);
      int reg = take_reg();
      gen_mov($5, reg);
      code("\n\t\tJMP @exit%d", lab_num);
      code("\n@false%d:", lab_num);
      gen_mov($7, reg);
      code("\n@exit%d:", lab_num);
      $$ = reg;
      set_type($$, get_type($5));
    }
  ;

stmt
  : _ID
    {
    int idx = lookup_symbol($1, VAR|PAR|GLOB);
    if(idx == NO_INDEX)
      err("'%s' undeclared");

    $$ = idx;
    }
  | literal
  ;

for_statement
  : _FOR _LPAREN _ID _ASSIGN literal _SEMICOLON

    {
      int idx = lookup_symbol($3, VAR|PAR|GLOB);
      if (idx == NO_INDEX)
        err("'%s' undeclared", $3);
      ++lab_num;

      $<i>$ = lab_num;
      if (get_type($5) != get_type(idx))
        err("incompatible types in for statement");

      gen_mov($5, idx);

      code("\n@for%d:", lab_num);

    }

  rel_exp _SEMICOLON _ID _PLUSPLUS _RPAREN
    {
      int idx = lookup_symbol($10, VAR|PAR|GLOB);
      if (idx == NO_INDEX)
        err("'%s' undeclared", $10);
      else if(idx != lookup_symbol($3, VAR|PAR|GLOB))
        err("not the same variable in for statement");
      code("\n\t\t%s @forexit%d", opp_jumps[$8], $<i>7);

    }

statement
    {
      int idx = lookup_symbol($10, VAR|PAR|GLOB);

      code("\n\t\t%s", ar_instructions[ADD + (get_type(idx) - 1) * AROP_NUMBER]);

      gen_sym_name(idx);
      code(", $1, ");
      gen_sym_name(idx);


      code("\n\t\tJMP @for%d", $<i>7);

      code("\n@forexit%d:", $<i>7);
    }
  ;
if_statement
  : if_part %prec ONLY_IF
      { code("\n@exit%d:", $1); }

  | if_part _ELSE statement
      { code("\n@exit%d:", $1); }
  ;

if_part
  : _IF _LPAREN
      {
        $<i>$ = ++lab_num;
        code("\n@if%d:", lab_num);
      }
    rel_exp
      {
        code("\n\t\t%s\t@false%d", opp_jumps[$4], $<i>3);
        code("\n@true%d:", $<i>3);
        for (int i = 0; i < var_num_to_inc; i++) {
          int idx = vars_to_inc[i];
          code("\n\t\t%s ", ar_instructions[ADD + (get_type(idx) - 1) * AROP_NUMBER]);
          gen_sym_name(idx);
          code(", $1, ");
          gen_sym_name(idx);
        }
        var_num_to_inc = 0;
      }
    _RPAREN statement
      {
        code("\n\t\tJMP \t@exit%d", $<i>3);
        code("\n@false%d:", $<i>3);
        $$ = $<i>3;
      }
  ;

case_statement
  : _SWITCH _LPAREN _ID
      {
        int idx = lookup_symbol($3, VAR|PAR|GLOB);
        if (idx == NO_INDEX)
          err("'%s' undeclared", $3);
        case_var = idx;
        lab_num++;
        code("\n\t\tJMP @switch%d", lab_num);
      }
    _RPAREN _LBRACKET cases _RBRACKET
      {

        code("\n@switch%d:", lab_num);
        for (int i = 0; i < case_num; i++) {
          if(get_type(case_lit[i]) == INT)
            code("\n\t\tCMPS\t");
          else
            code("\n\t\tCMPU\t");

          gen_sym_name(case_var);
          code(", ");
          gen_sym_name(case_lit[i]);
          code("\n\t\tJEQ\t@case%d", atoi(get_name(case_lit[i])));
        }
        case_num = 0;
        code("\n\t\tJMP @default%d", lab_num);
        code("\n@exitswitch%d:", lab_num);
      }
  ;

cases
  : case maybe_default
  | cases case maybe_default
  ;

case
  : _CASE literal _COLON
    {
      if (get_type($2) != get_type(case_var))
        err("incompatible types in switch-case");
      code("\n@case%d:", atoi(get_name($2)));
      case_lit[case_num++] = $2;

    }
  statement maybe_break
  ;

maybe_default
  : /**/
  | _DEFAULT _COLON
    {
      code("\n@default%d:", lab_num);
    }
    statement
  ;

maybe_break
  : /**/
  | _BREAK _SEMICOLON {
    code("\n\t\tJMP @exitswitch%d", lab_num);
  }
  ;

rel_exp
  : num_exp
    {

        for (int i = 0; i < var_num_to_inc; i++) {
          int idx = vars_to_inc[i];
          code("\n\t\t%s ", ar_instructions[ADD + (get_type(idx) - 1) * AROP_NUMBER]);
          gen_sym_name(idx);
          code(", $1, ");
          gen_sym_name(idx);
        }
        var_num_to_inc = 0;
    }
   _RELOP num_exp
      {
        if(get_type($1) != get_type($4))
          err("invalid operands: relational operator");


          for (int i = 0; i < var_num_to_inc; i++) {
            int idx = vars_to_inc[i];
            code("\n\t\t%s ", ar_instructions[ADD + (get_type(idx) - 1) * AROP_NUMBER]);
            gen_sym_name(idx);
            code(", $1, ");
            gen_sym_name(idx);
        }
                  var_num_to_inc = 0;
        $$ = $3 + ((get_type($1) - 1) * RELOP_NUMBER);
        gen_cmp($1, $4);
      }
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
      {
        if(get_type(fun_idx) != get_type($2))
          err("incompatible types in return");
        gen_mov($2, FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));
      }
  ;

%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);

  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}
