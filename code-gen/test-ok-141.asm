
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		MOV 	$0,-8(%14)
		MOV 	$0,-4(%14)
		MOV 	$10,-8(%14)
@petljaj0:
		CMPU	-8(%14), $1
		JLTS	@petljaj_exit0
		MOV 	$1,-12(%14)
@petljaj1:
CMPS	-12(%14), $2
JGTS	@petljaj_exit1
		ADDS	-4(%14),$1,-4(%14)
		ADDS	-12(%14), $1, -12(%14)
		JMP @petljaj1
@petljaj_exit1:
		SUBU	-8(%14), $1, -8(%14)
		JMP @petljaj0
@petljaj_exit0:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET