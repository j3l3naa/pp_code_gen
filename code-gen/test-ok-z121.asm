
y:		WORD	1
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
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
@if1:
		ADDS y, $1, y
		CMPS 	-4(%14),y
		JGES	@false1
@true1:
		MOV 	$0,-4(%14)
		JMP 	@exit1
@false1:
@exit1:
		MOV 	$0,-8(%14)
@fordef20:
		CMPS 	-8(%14),$5
		JGES @fordefexit20
		ADDS	-8(%14), $1, -8(%14)
		MOV 	$1,-12(%14)
@fordef23:
		CMPS 	-12(%14),$2
		JGES @fordefexit23
		ADDS	-12(%14), $1, -12(%14)
		ADDS	y,$1,y
		JMP @fordef23
@fordefexit23:
		JMP @fordef20
@fordefexit20:
		ADDS	-4(%14),y,%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET