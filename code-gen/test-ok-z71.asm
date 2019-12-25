
y:		WORD	1
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$0,-4(%14)
		MOV 	$3,y
		ADDS	-4(%14),y,%0
		ADDS	%0,$42,%0
		ADDS -4(%14), $1, -4(%14)
		ADDS y, $1, y
		MOV 	%0,-8(%14)
		MOV 	$1,-8(%14)
		JMP @switch0
@case1:
		MOV 	$1,-8(%14)
		JMP @exitswitch0
@case2:
		MOV 	$5,-8(%14)
@default0:
		MOV 	$6,-8(%14)
@switch0:
		CMPS	-4(%14), $1
		JEQ	@case1
		CMPS	-4(%14), $2
		JEQ	@case2
		JMP @default0
@exitswitch0:
		ADDS	-4(%14),y,%0
		ADDS	%0,-8(%14),%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET