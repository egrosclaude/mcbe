	LD IN
	ST K2
	LD K2
	SUB DATO0
	JZ COND0
	LD B
	ST OUT
COND0:	NOP
	LD K2
	SUB DATO1
	JZ COND1
	LD C
	ST OUT
COND1:	NOP
	HLT
C:	2
K2:	0
B:	1
DATO0:	8
DATO1:	2
