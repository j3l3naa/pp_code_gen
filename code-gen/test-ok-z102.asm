
y:		WORD	1
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		MOV 	$2,-4(%14)
		MOV 	$6,y
@if0:
		ADDS -4(%14), $1, -4(%14)
		CMPS 	-4(%14),y
		JNE 	@false0
@true0:
		MOV 	$2,-4(%14)
		JMP 	@exit0
@false0:
@exit0:
@basicfor1:
		MOV 	$0,-8(%14)
@forstmt1:
@basicfor2:
		MOV 	$10,-12(%14)
@forstmt2:
		ADDS	-4(%14),$1,-4(%14)
		SUBS	-12(%14), $2, -12(%14)
		CMPS	-12(%14), $5
		JGES @forstmt2
@forbasicexit2:
		ADDS	-8(%14), $1, -8(%14)
		CMPS	-8(%14), $5
		JLES @forstmt1
@forbasicexit1:
@if3:
		ADDS y, $1, y
		CMPS 	-4(%14),y
		JGES	@false3
@true3:
		MOV 	$0,-4(%14)
		JMP 	@exit3
@false3:
@exit3:
		ADDS	-4(%14),y,%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET