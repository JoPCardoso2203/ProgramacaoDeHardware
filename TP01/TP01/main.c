/*
 * TP01.c
 *
 * Author : Jo�o Paulo Cardoso D'Oliveira RA: 176851
 */ 

#include <avr/io.h>

extern char resolve_operacao(char, char, char, char);

main()
{
	volatile unsigned char v1, v2, v3, v4, v5;
	
    while (1) 
    {
		//Valores da equa��o
		v1 = 0x37;
		v2 = 45;
		v3 = 0b00111000;
		v4 = 0x2B;
		
		//M�todo em assembly que resolve a equa��o
		v5 = resolve_operacao(v1,v2,v3,v4); /*Resultado da equa��o aqui*/
    }
}

