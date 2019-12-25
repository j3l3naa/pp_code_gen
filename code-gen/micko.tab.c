/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "micko.y" /* yacc.c:337  */

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


#line 100 "micko.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "micko.tab.h".  */
#ifndef YY_YY_MICKO_TAB_H_INCLUDED
# define YY_YY_MICKO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _TYPE = 258,
    _IF = 259,
    _ELSE = 260,
    _RETURN = 261,
    _ID = 262,
    _INT_NUMBER = 263,
    _UINT_NUMBER = 264,
    _LPAREN = 265,
    _RPAREN = 266,
    _LBRACKET = 267,
    _RBRACKET = 268,
    _ASSIGN = 269,
    _SEMICOLON = 270,
    _AROP = 271,
    _MDROP = 272,
    _RELOP = 273,
    _PLUSPLUS = 274,
    _QMARK = 275,
    _COLON = 276,
    _FOR = 277,
    _SWITCH = 278,
    _CASE = 279,
    _DEFAULT = 280,
    _BREAK = 281,
    _WHILE = 282,
    _DO = 283,
    _TO = 284,
    _DOWNTO = 285,
    _STEP = 286,
    _NEXT = 287,
    _ITERATE = 288,
    ONLY_IF = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "micko.y" /* yacc.c:352  */

  int i;
  char *s;

#line 183 "micko.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MICKO_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

#define YYUNDEFTOK  2
#define YYMAXUTOK   289

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    81,    83,    87,   105,   106,   111,   110,
     136,   138,   148,   147,   156,   158,   162,   171,   173,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     191,   195,   218,   234,   217,   275,   293,   295,   311,   336,
     338,   345,   351,   353,   362,   367,   375,   399,   404,   366,
     463,   467,   475,   478,   485,   488,   494,   493,   524,   526,
     539,   538,   557,   563,   556,   576,   595,   603,   659,   668,
     658,   692,   695,   701,   706,   700,   728,   727,   758,   759,
     764,   763,   774,   777,   776,   783,   785,   792,   791,   823
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_TYPE", "_IF", "_ELSE", "_RETURN",
  "_ID", "_INT_NUMBER", "_UINT_NUMBER", "_LPAREN", "_RPAREN", "_LBRACKET",
  "_RBRACKET", "_ASSIGN", "_SEMICOLON", "_AROP", "_MDROP", "_RELOP",
  "_PLUSPLUS", "_QMARK", "_COLON", "_FOR", "_SWITCH", "_CASE", "_DEFAULT",
  "_BREAK", "_WHILE", "_DO", "_TO", "_DOWNTO", "_STEP", "_NEXT",
  "_ITERATE", "ONLY_IF", "$accept", "program", "global_variables",
  "global_vars", "function_list", "function", "$@1", "parameter", "body",
  "$@2", "variable_list", "variable", "statement_list", "statement",
  "compound_statement", "assignment_statement", "iterating_statement",
  "@3", "$@4", "postincrement_statement", "num_exp", "exp", "basic_for",
  "$@5", "@6", "$@7", "$@8", "direction", "maybe_step", "literal",
  "function_call", "$@9", "argument", "do_while_statement", "@10",
  "while_statement", "@11", "$@12", "conditional_operator", "stmt",
  "for_statement", "@13", "$@14", "if_statement", "if_part", "@15", "$@16",
  "case_statement", "$@17", "cases", "case", "$@18", "maybe_default",
  "$@19", "maybe_break", "rel_exp", "$@20", "return_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289
};
# endif

#define YYPACT_NINF -94

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-94)))

#define YYTABLE_NINF -57

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -94,    11,    31,   -94,    29,   -94,    35,   -94,    24,    38,
     -94,   -94,    41,   -94,    45,    46,    51,   -94,    47,   -94,
     -94,    54,    67,   -94,   -94,    62,    48,   -94,    68,    34,
      -6,   -94,   -94,     2,    80,   -94,   -94,    87,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,    94,   -94,
     -94,   -94,    -3,   -94,   -94,    34,     4,   -94,   -94,   -94,
     -94,    34,    81,    60,    86,    97,    98,    96,    91,   -94,
      91,    34,   -94,    99,     6,    90,   -94,    34,    34,     9,
     -94,   -94,   -94,    93,   -94,    34,    83,    84,   -94,    12,
     -94,    34,   -94,   102,    88,    95,   -94,   -94,    23,    23,
     100,   -94,   106,    23,   110,    12,   111,    34,    77,    39,
     -94,   105,   112,    34,   101,    91,   -94,    12,   -94,   -94,
     104,   -94,   -94,    23,   113,   103,    91,   115,    23,   -94,
      77,   -94,    34,    23,   -10,   107,   -94,   114,   -94,   -94,
     108,   -94,   116,   -94,   107,   117,   -94,   -94,    91,    23,
     -94,   118,   -94,   -94,   -94,   -94,   -94,    91,   124,    91,
      91,   109,   121,   119,   -94,   -94,   123,   120,   -94,   127,
      91,   -94,   -94,   -94
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     4,     2,     6,     8,     0,
       7,     5,     0,     8,    10,     0,     0,    11,     0,    14,
       9,    12,     0,    17,    15,     0,     0,    16,     0,     0,
       0,    17,    13,     0,     0,    62,    60,     0,    18,    19,
      20,    29,    23,    28,    27,    26,    24,    21,    71,    25,
      22,    73,    40,    54,    55,     0,     0,    36,    39,    41,
      44,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,    43,     0,    87,     0,    89,     0,     0,     0,
      35,    30,    45,     0,    76,     0,     0,     0,    72,    87,
      74,    58,    42,     0,     0,    37,    38,    31,     0,     0,
       0,    63,     0,     0,     0,    59,     0,     0,     0,     0,
      68,     0,     0,     0,     0,     0,    57,    88,    66,    67,
       0,    50,    51,     0,     0,     0,     0,     0,     0,    75,
       0,    46,     0,     0,     0,    82,    64,     0,    33,    65,
      52,    69,     0,    77,    82,     0,    78,    61,     0,     0,
      47,     0,    80,    79,    83,    34,    53,     0,     0,     0,
       0,     0,     0,    85,    84,    48,     0,     0,    81,     0,
       0,    86,    49,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -94,   -94,   -94,   -94,   -94,   130,   -94,   -94,   -94,   -94,
     -94,   -94,   122,   -68,   -94,   -94,   -94,   -94,   -94,   -94,
     -28,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -93,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,    13,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
      10,   -94,     3,   -94,   -94,   -67,   -94,   -94
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,     7,    12,    16,    20,    23,
      21,    24,    26,    38,    39,    40,    41,    87,   148,    42,
      89,    57,    43,    98,   140,   157,   169,   123,   150,    58,
      59,    73,   106,    44,    68,    45,    67,   112,    60,   120,
      46,   124,   151,    47,    48,    71,   104,    49,   100,   134,
     135,   159,   146,   160,   168,    75,    93,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      86,    56,    88,   143,    90,   109,   110,   -56,    61,    64,
     114,     3,    65,    62,   133,   119,    72,    92,   101,    76,
      77,    78,    77,    78,    97,    77,    78,    74,    77,    78,
     131,    53,    54,    79,     4,   138,     8,   119,     9,    11,
     142,    52,    53,    54,    55,    13,   127,   129,    15,    95,
      96,    14,    28,    17,    29,    30,   156,    22,   136,    19,
      31,    32,    18,   105,    28,   141,    29,    30,   121,   122,
      33,    34,    31,    81,    25,    35,    36,    27,    51,   117,
     155,    37,    33,    34,   118,    53,    54,    35,    36,   161,
      66,   163,   164,    37,    69,    28,    80,    29,    30,    70,
      82,    94,   173,    31,    83,    84,    85,    99,   108,    91,
     102,   111,    78,    33,    34,   103,   113,   125,    35,    36,
     107,   115,   116,   126,    37,   130,   137,   133,   132,   147,
     128,   162,   145,   158,   170,   171,    10,   152,   154,   149,
     166,   165,   172,   139,   144,   167,     0,   153,     0,     0,
       0,     0,     0,    63
};

static const yytype_int16 yycheck[] =
{
      68,    29,    70,    13,    71,    98,    99,    10,    14,     7,
     103,     0,    10,    19,    24,   108,    19,    11,    85,    15,
      16,    17,    16,    17,    15,    16,    17,    55,    16,    17,
     123,     8,     9,    61,     3,   128,     7,   130,     3,    15,
     133,     7,     8,     9,    10,     7,   113,   115,     3,    77,
      78,    10,     4,     7,     6,     7,   149,     3,   126,    12,
      12,    13,    11,    91,     4,   132,     6,     7,    29,    30,
      22,    23,    12,    13,     7,    27,    28,    15,    10,   107,
     148,    33,    22,    23,     7,     8,     9,    27,    28,   157,
      10,   159,   160,    33,     7,     4,    15,     6,     7,     5,
      14,    11,   170,    12,     7,     7,    10,    14,    20,    10,
      27,    11,    17,    22,    23,    31,    10,    12,    27,    28,
      18,    11,    11,    11,    33,    21,    11,    24,    15,    15,
      29,     7,    25,    15,    11,    15,     6,    21,    21,    31,
      19,    32,    15,   130,   134,    26,    -1,   144,    -1,    -1,
      -1,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    37,     0,     3,    38,    39,    40,     7,     3,
      40,    15,    41,     7,    10,     3,    42,     7,    11,    12,
      43,    45,     3,    44,    46,     7,    47,    15,     4,     6,
       7,    12,    13,    22,    23,    27,    28,    33,    48,    49,
      50,    51,    54,    57,    68,    70,    75,    78,    79,    82,
      92,    10,     7,     8,     9,    10,    55,    56,    64,    65,
      73,    14,    19,    47,     7,    10,    10,    71,    69,     7,
       5,    80,    19,    66,    55,    90,    15,    16,    17,    55,
      15,    13,    14,     7,     7,    10,    48,    52,    48,    55,
      90,    10,    11,    91,    11,    55,    55,    15,    58,    14,
      83,    90,    27,    31,    81,    55,    67,    18,    20,    64,
      64,    11,    72,    10,    64,    11,    11,    55,     7,    64,
      74,    29,    30,    62,    76,    12,    11,    90,    29,    48,
      21,    64,    15,    24,    84,    85,    48,    11,    64,    74,
      59,    90,    64,    13,    85,    25,    87,    15,    53,    31,
      63,    77,    21,    87,    21,    48,    64,    60,    15,    86,
      88,    48,     7,    48,    48,    32,    19,    26,    89,    61,
      11,    15,    15,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    39,    39,    41,    40,
      42,    42,    44,    43,    45,    45,    46,    47,    47,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      49,    50,    52,    53,    51,    54,    55,    55,    55,    56,
      56,    56,    56,    56,    56,    58,    59,    60,    61,    57,
      62,    62,    63,    63,    64,    64,    66,    65,    67,    67,
      69,    68,    71,    72,    70,    73,    74,    74,    76,    77,
      75,    78,    78,    80,    81,    79,    83,    82,    84,    84,
      86,    85,    87,    88,    87,    89,    89,    91,    90,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     3,     1,     2,     0,     7,
       0,     2,     0,     5,     0,     2,     3,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     0,     0,     9,     3,     1,     3,     3,     1,
       1,     1,     3,     2,     1,     0,     0,     0,     0,    14,
       1,     1,     0,     2,     1,     1,     0,     5,     0,     1,
       0,     8,     0,     0,     7,     7,     1,     1,     0,     0,
      14,     1,     3,     0,     0,     7,     0,     8,     2,     3,
       0,     6,     0,     0,     4,     0,     2,     0,     4,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 75 "micko.y" /* yacc.c:1652  */
    {
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
#line 1401 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 88 "micko.y" /* yacc.c:1652  */
    {
        int idx = lookup_symbol((yyvsp[-1].s), GLOB);
        if (idx == NO_INDEX)
          {
            insert_symbol((yyvsp[-1].s), GLOB, (yyvsp[-2].i), NO_ATR, NO_ATR);
          }
        else
          {
            err("redefinition of global variable");
          }

        code("\n%s:", (yyvsp[-1].s));
        code("\t\tWORD\t1");
      }
#line 1420 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 111 "micko.y" /* yacc.c:1652  */
    {
        fun_idx = lookup_symbol((yyvsp[0].s), FUN|GLOB);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol((yyvsp[0].s), FUN, (yyvsp[-1].i), NO_ATR, NO_ATR);
        else
          err("redefinition of function '%s'", (yyvsp[0].s));

        code("\n%s:", (yyvsp[0].s));
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
#line 1436 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 123 "micko.y" /* yacc.c:1652  */
    {
        clear_symbols(fun_idx + 1);
        var_num = 0;

        code("\n@%s_exit:", (yyvsp[-5].s));
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
#line 1450 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 136 "micko.y" /* yacc.c:1652  */
    { set_atr1(fun_idx, 0); }
#line 1456 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 139 "micko.y" /* yacc.c:1652  */
    {
        insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), 1, NO_ATR);
        set_atr1(fun_idx, 1);
        set_atr2(fun_idx, (yyvsp[-1].i));
      }
#line 1466 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 148 "micko.y" /* yacc.c:1652  */
    {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      }
#line 1476 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 163 "micko.y" /* yacc.c:1652  */
    {
        if(lookup_symbol((yyvsp[-1].s), VAR|PAR) == NO_INDEX)
           insert_symbol((yyvsp[-1].s), VAR, (yyvsp[-2].i), ++var_num, NO_ATR);
        else
           err("redefinition of '%s'", (yyvsp[-1].s));
      }
#line 1487 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 196 "micko.y" /* yacc.c:1652  */
    {
        int idx = lookup_symbol((yyvsp[-3].s), VAR|PAR|GLOB);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", (yyvsp[-3].s));
        else
          if(get_type(idx) != get_type((yyvsp[-1].i)))
            err("incompatible types in assignment");

        for (int i = 0; i < var_num_to_inc; i++) {
          int idx = vars_to_inc[i];
          code("\n\t\t%s ", ar_instructions[ADD + (get_type(idx) - 1) * AROP_NUMBER]);
          gen_sym_name(idx);
          code(", $1, ");
          gen_sym_name(idx);
        }
        var_num_to_inc = 0;
        gen_mov((yyvsp[-1].i), idx);
      }
#line 1510 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 218 "micko.y" /* yacc.c:1652  */
    {
      int idx = lookup_symbol((yyvsp[0].s), VAR|PAR|GLOB);
      if (idx == NO_INDEX)
        err("'%s' undeclared", (yyvsp[0].s));

      lab_num++;
      (yyval.i) = lab_num;
      code("\n\t\tMOV $1, ");
      gen_sym_name(idx);
      code("\n@iterate%d:", lab_num);
      code("\n\t\t");


    }
#line 1529 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 234 "micko.y" /* yacc.c:1652  */
    {
      int idx = lookup_symbol((yyvsp[-5].s), VAR|PAR|GLOB);
      if(idx != NO_INDEX)
      {
      if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)) || get_type((yyvsp[-2].i)) != get_type(idx))
        err("incompatible types in iterating_statement");
      }
    }
#line 1542 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 243 "micko.y" /* yacc.c:1652  */
    {
      int idx = lookup_symbol((yyvsp[-7].s), VAR|PAR|GLOB);
      if (idx != NO_INDEX)
      {
      code("\n\t\t%s\t", ar_instructions[ADD + (get_type(idx) -1 )*AROP_NUMBER]);
      gen_sym_name(idx);
      code(", $%d, ", atoi(get_name((yyvsp[-4].i))));
      gen_sym_name(idx);

      if(get_type((yyvsp[-4].i)) == INT)
        {
          code("\n\t\tCMPS\t");
          gen_sym_name(idx);
          code(", ");
          gen_sym_name((yyvsp[-2].i));
          code("\n\t\tJLES @iterate%d", (yyvsp[-6].i));
        }
        else {
          code("\n\t\tCMPU\t");
          gen_sym_name(idx);
          code(", ");
          gen_sym_name((yyvsp[-2].i));
          code("\n\t\tJLES @iterate%d", (yyvsp[-6].i));
        }

      code("\n@exititerate%d:", (yyvsp[-6].i));
    }
    }
#line 1575 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 276 "micko.y" /* yacc.c:1652  */
    {
        int idx = lookup_symbol((yyvsp[-2].s), VAR|PAR|GLOB);
        if(idx == NO_INDEX)
          {
            err("undefined %s", (yyvsp[-2].s));
          }
        else
          {
            code("\n\t\t%s\t", ar_instructions[ADD + (get_type(idx) - 1)*AROP_NUMBER]);
            gen_sym_name(idx);
            code(",$1,");
            gen_sym_name(idx);
          }
    }
#line 1594 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 296 "micko.y" /* yacc.c:1652  */
    {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: arithmetic operation");
        int t1 = get_type((yyvsp[-2].i));
        code("\n\t\t%s\t", ar_instructions[(yyvsp[-1].i) + (t1 - 1) * AROP_NUMBER]);
        gen_sym_name((yyvsp[-2].i));
        code(",");
        gen_sym_name((yyvsp[0].i));
        code(",");
        free_if_reg((yyvsp[0].i));
        free_if_reg((yyvsp[-2].i));
        (yyval.i) = take_reg();
        gen_sym_name((yyval.i));
        set_type((yyval.i), t1);
      }
#line 1614 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 312 "micko.y" /* yacc.c:1652  */
    {
     {
       if (get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          {
            err("invalid operands : Arithmetic operation");
          }
          int type = get_type((yyvsp[-2].i));

          code("\n\t\t%s\t", ar_instructions[(yyvsp[-1].i) + (type - 1) * AROP_NUMBER]);
          gen_sym_name((yyvsp[-2].i));
          code(",");
          gen_sym_name((yyvsp[0].i));
          code(",");
          free_if_reg((yyvsp[0].i));
          free_if_reg((yyvsp[-2].i));
          (yyval.i) = take_reg();
          gen_sym_name((yyval.i));
          set_type((yyval.i), type);

     }
     }
#line 1640 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 339 "micko.y" /* yacc.c:1652  */
    {
        (yyval.i) = lookup_symbol((yyvsp[0].s), VAR|PAR|GLOB);
        if((yyval.i) == NO_INDEX)
          err("'%s' undeclared", (yyvsp[0].s));
      }
#line 1650 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 346 "micko.y" /* yacc.c:1652  */
    {
        (yyval.i) = take_reg();
        gen_mov(FUN_REG, (yyval.i));
      }
#line 1659 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 352 "micko.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 1665 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 354 "micko.y" /* yacc.c:1652  */
    {
      (yyval.i) = lookup_symbol((yyvsp[-1].s), VAR|PAR|GLOB);
      if ((yyval.i) == NO_INDEX)
        err("'%s' undeclared", (yyvsp[-1].s));

      vars_to_inc[var_num_to_inc++] = (yyval.i);

     }
#line 1678 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 367 "micko.y" /* yacc.c:1652  */
    {
      int idx = lookup_symbol((yyvsp[-1].s), VAR|PAR|GLOB);

      if (idx == NO_INDEX)
        err("'%s' undefined", (yyvsp[-1].s));

    }
#line 1690 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 375 "micko.y" /* yacc.c:1652  */
    {
      int idx = lookup_symbol((yyvsp[-5].s), VAR|PAR|GLOB);
      if (get_type(idx) != get_type((yyvsp[-2].i)) && get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("incompatible types in basic for statement");
      if ((yyvsp[-1].i) == 1)
        {
          if(atoi(get_name((yyvsp[-2].i))) > atoi(get_name((yyvsp[0].i))))
            {
              err("wrong direction");
            }
        }
        else {
          if(atoi(get_name((yyvsp[-2].i))) < atoi(get_name((yyvsp[0].i))))
            {
              err("wrong direction");
            }
        }
        ++lab_num;
        code("\n@basicfor%d:", lab_num);
        (yyval.i) = lab_num;
        gen_mov((yyvsp[-2].i), idx);
    }
#line 1717 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 399 "micko.y" /* yacc.c:1652  */
    {
      code("\n@forstmt%d:", (yyvsp[-1].i));
    }
#line 1725 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 404 "micko.y" /* yacc.c:1652  */
    {
      int idx = lookup_symbol((yyvsp[-10].s), VAR|PAR|GLOB);
      if ((yyvsp[-6].i) == 1)
      {
        code("\n\t\t%s\t", ar_instructions[ADD + (get_type(idx) - 1) * AROP_NUMBER]);
        gen_sym_name(idx);
        code(", $%d, ", (yyvsp[-3].i));
        gen_sym_name(idx);

        if (get_type(idx) == INT) {
          code("\n\t\tCMPS\t");
          gen_sym_name(idx);
          code(", ");
          gen_sym_name((yyvsp[-5].i));
          code("\n\t\tJLES @forstmt%d", (yyvsp[-4].i));

        }
        else
          {
          code("\n\t\tCMPU\t");
          gen_sym_name(idx);
          code(", ");
          gen_sym_name((yyvsp[-5].i));
          code("\n\t\tJLES @forstmt%d", (yyvsp[-4].i));
          }
      }
      else
      {

        code("\n\t\t%s\t", ar_instructions[SUB + (get_type(idx) - 1) * AROP_NUMBER]);
        gen_sym_name(idx);
        code(", $%d, ", (yyvsp[-3].i));
        gen_sym_name(idx);

        if (get_type(idx) == INT) {
          code("\n\t\tCMPS\t");
          gen_sym_name(idx);
          code(", ");
          gen_sym_name((yyvsp[-5].i));
          code("\n\t\tJGES @forstmt%d", (yyvsp[-4].i));

        }
        else
          {
          code("\n\t\tCMPU\t");
          gen_sym_name(idx);
          code(", ");
          gen_sym_name((yyvsp[-5].i));
          code("\n\t\tJGES @forstmt%d", (yyvsp[-4].i));
          }
      }
    }
#line 1782 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 457 "micko.y" /* yacc.c:1652  */
    {
        code("\n@forbasicexit%d:", (yyvsp[-6].i));
      }
#line 1790 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 464 "micko.y" /* yacc.c:1652  */
    {
      (yyval.i) = 1;
    }
#line 1798 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 468 "micko.y" /* yacc.c:1652  */
    {
      (yyval.i) = 2;
    }
#line 1806 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 475 "micko.y" /* yacc.c:1652  */
    {
      (yyval.i) = 1;
    }
#line 1814 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 479 "micko.y" /* yacc.c:1652  */
    {
      (yyval.i) = atoi(get_name((yyvsp[0].i)));
    }
#line 1822 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 486 "micko.y" /* yacc.c:1652  */
    { (yyval.i) = insert_literal((yyvsp[0].s), INT); }
#line 1828 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 489 "micko.y" /* yacc.c:1652  */
    { (yyval.i) = insert_literal((yyvsp[0].s), UINT); }
#line 1834 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 494 "micko.y" /* yacc.c:1652  */
    {
        fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", (yyvsp[0].s));
      }
#line 1844 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 500 "micko.y" /* yacc.c:1652  */
    {
      for (int i = 0; i < var_num_to_inc; i++) {
        int idx = vars_to_inc[i];
        code("\n\t\t%s ", ar_instructions[ADD + (get_type(idx) - 1) * AROP_NUMBER]);
        gen_sym_name(idx);
        code(", $1, ");
        gen_sym_name(idx);
      }
      var_num_to_inc = 0;

        if(get_atr1(fcall_idx) != (yyvsp[-1].i))
          err("wrong number of arguments");
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if((yyvsp[-1].i) > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", (yyvsp[-1].i) * 4);


        set_type(FUN_REG, get_type(fcall_idx));
        (yyval.i) = FUN_REG;
      }
#line 1869 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 524 "micko.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 1875 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 527 "micko.y" /* yacc.c:1652  */
    {
      if(get_atr2(fcall_idx) != get_type((yyvsp[0].i)))
        err("incompatible type for argument");
      free_if_reg((yyvsp[0].i));
      code("\n\t\t\tPUSH\t");
      gen_sym_name((yyvsp[0].i));
      (yyval.i) = 1;
    }
#line 1888 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 539 "micko.y" /* yacc.c:1652  */
    {
      lab_num++;
      (yyval.i) = lab_num;
      code("\n@dowhile%d:", lab_num);
    }
#line 1898 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 545 "micko.y" /* yacc.c:1652  */
    {
    code("\n\t\t%s\t@dowhileexit%d", opp_jumps[(yyvsp[-2].i)], (yyvsp[-6].i));
    code("\n\t\tJMP @dowhile%d", (yyvsp[-6].i));
    code("\n@dowhileexit%d:", (yyvsp[-6].i));
   }
#line 1908 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 557 "micko.y" /* yacc.c:1652  */
    {
      lab_num++;
      code("\n@while%d:", lab_num);
      (yyval.i) = lab_num;
    }
#line 1918 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 563 "micko.y" /* yacc.c:1652  */
    {

      code("\n\t\t%s @whilexit%d", opp_jumps[(yyvsp[0].i)], (yyvsp[-2].i));

    }
#line 1928 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 569 "micko.y" /* yacc.c:1652  */
    {
      code("\n\t\t JMP @while%d", (yyvsp[-5].i));
      code("\n@whilexit%d:", (yyvsp[-5].i));
    }
#line 1937 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 577 "micko.y" /* yacc.c:1652  */
    {
      if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
        err("incompatible types");

      ++lab_num;
      code("\n\t\t%s @false%d", opp_jumps[(yyvsp[-5].i)], lab_num);
      int reg = take_reg();
      gen_mov((yyvsp[-2].i), reg);
      code("\n\t\tJMP @exit%d", lab_num);
      code("\n@false%d:", lab_num);
      gen_mov((yyvsp[0].i), reg);
      code("\n@exit%d:", lab_num);
      (yyval.i) = reg;
      set_type((yyval.i), get_type((yyvsp[-2].i)));
    }
#line 1957 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 596 "micko.y" /* yacc.c:1652  */
    {
    int idx = lookup_symbol((yyvsp[0].s), VAR|PAR|GLOB);
    if(idx == NO_INDEX)
      err("'%s' undeclared");

    (yyval.i) = idx;
    }
#line 1969 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 659 "micko.y" /* yacc.c:1652  */
    {
        (yyval.i) = ++lab_num;
        int i = lookup_symbol((yyvsp[-2].s), VAR|PAR);
        if(i == NO_INDEX)
          err("nedeklarisno %s", (yyvsp[-2].s));
        gen_mov((yyvsp[0].i),i);  //inicijalizacija iteratora, pre pocetka petlje
        code("\n@for%d:", lab_num);
      }
#line 1982 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 668 "micko.y" /* yacc.c:1652  */
    {
        code("\n\t\t%s\t@exit%d", opp_jumps[(yyvsp[0].i)], (yyvsp[-2].i));
      }
#line 1990 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 672 "micko.y" /* yacc.c:1652  */
    {
        int i = lookup_symbol((yyvsp[-3].s), VAR|PAR);
        if(i == NO_INDEX)
          err("nedeklarisno %s", (yyvsp[-3].s));
        //gk za inkrement (na kraju petlje)
        //resenje = iz v7
        if(get_type(i) == INT)
          code("\n\t\tADDS\t");
        else
          code("\n\t\tADDU\t");
        gen_sym_name(i);
        code(",$1,");
        gen_sym_name(i);

        code("\n\t\tJMP \t@for%d", (yyvsp[-8].i));
        code("\n@exit%d:", (yyvsp[-8].i));
      }
#line 2012 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 693 "micko.y" /* yacc.c:1652  */
    { code("\n@exit%d:", (yyvsp[0].i)); }
#line 2018 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 696 "micko.y" /* yacc.c:1652  */
    { code("\n@exit%d:", (yyvsp[-2].i)); }
#line 2024 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 701 "micko.y" /* yacc.c:1652  */
    {
        (yyval.i) = ++lab_num;
        code("\n@if%d:", lab_num);
      }
#line 2033 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 706 "micko.y" /* yacc.c:1652  */
    {
        code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], (yyvsp[-1].i));
        code("\n@true%d:", (yyvsp[-1].i));
        for (int i = 0; i < var_num_to_inc; i++) {
          int idx = vars_to_inc[i];
          code("\n\t\t%s ", ar_instructions[ADD + (get_type(idx) - 1) * AROP_NUMBER]);
          gen_sym_name(idx);
          code(", $1, ");
          gen_sym_name(idx);
        }
        var_num_to_inc = 0;
      }
#line 2050 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 719 "micko.y" /* yacc.c:1652  */
    {
        code("\n\t\tJMP \t@exit%d", (yyvsp[-4].i));
        code("\n@false%d:", (yyvsp[-4].i));
        (yyval.i) = (yyvsp[-4].i);
      }
#line 2060 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 728 "micko.y" /* yacc.c:1652  */
    {
        int idx = lookup_symbol((yyvsp[0].s), VAR|PAR|GLOB);
        if (idx == NO_INDEX)
          err("'%s' undeclared", (yyvsp[0].s));
        case_var = idx;
        lab_num++;
        code("\n\t\tJMP @switch%d", lab_num);
      }
#line 2073 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 737 "micko.y" /* yacc.c:1652  */
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
#line 2096 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 764 "micko.y" /* yacc.c:1652  */
    {
      if (get_type((yyvsp[-1].i)) != get_type(case_var))
        err("incompatible types in switch-case");
      code("\n@case%d:", atoi(get_name((yyvsp[-1].i))));
      case_lit[case_num++] = (yyvsp[-1].i);

    }
#line 2108 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 777 "micko.y" /* yacc.c:1652  */
    {
      code("\n@default%d:", lab_num);
    }
#line 2116 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 785 "micko.y" /* yacc.c:1652  */
    {
    code("\n\t\tJMP @exitswitch%d", lab_num);
  }
#line 2124 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 792 "micko.y" /* yacc.c:1652  */
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
#line 2140 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 804 "micko.y" /* yacc.c:1652  */
    {
        if(get_type((yyvsp[-3].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: relational operator");


          for (int i = 0; i < var_num_to_inc; i++) {
            int idx = vars_to_inc[i];
            code("\n\t\t%s ", ar_instructions[ADD + (get_type(idx) - 1) * AROP_NUMBER]);
            gen_sym_name(idx);
            code(", $1, ");
            gen_sym_name(idx);
        }
                  var_num_to_inc = 0;
        (yyval.i) = (yyvsp[-1].i) + ((get_type((yyvsp[-3].i)) - 1) * RELOP_NUMBER);
        gen_cmp((yyvsp[-3].i), (yyvsp[0].i));
      }
#line 2161 "micko.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 824 "micko.y" /* yacc.c:1652  */
    {
        if(get_type(fun_idx) != get_type((yyvsp[-1].i)))
          err("incompatible types in return");
        gen_mov((yyvsp[-1].i), FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));
      }
#line 2172 "micko.tab.c" /* yacc.c:1652  */
    break;


#line 2176 "micko.tab.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 832 "micko.y" /* yacc.c:1918  */


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
