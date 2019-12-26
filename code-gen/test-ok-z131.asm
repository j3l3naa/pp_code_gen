
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$0,-8(%14)
		MOV 	$5,-4(%14)
@for_in_range0:
		CMPS	$1, -4(%14)
		JGTS @for_in_range_exit0
		ADDS	-8(%14),$1,-8(%14)
		SUBS	-4(%14), $3, -4(%14)
		JMP @for_in_range0
@for_in_range_exit0:
		MOV 	-8(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET