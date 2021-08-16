
/*
 * FuncoesAssembler.S
 *
 * Created: 16/08/2021 01:04:04
 *  Author: User
 */ 

 #include <avr/io.h>

 .global resolve_operacao

 resolve_operacao:
	add r24, r22		; v1 = v1 + v2
	add r20, r18
	sub r24, r20
	ret