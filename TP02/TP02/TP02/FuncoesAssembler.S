
/*
 * FuncoesAssembler.S
 *
 * Created: 23/08/2021 00:00:23
 *  Author: User
 */ 

#include <avr/io.h>

.global inicio

.global leitura

.global muda_estado_porta


inicio:
	.org 0x000

	;inicializacao dos registradores
	ldi r26, 0b00000000
	ldi r27, 0b11011001		;valor de limite do sensor para ligar as portas
    eor r1, r1
	
	;setup
    ldi r16, 0xFF
    out ddrb, r16

	;conficuracao
    LDI r16, 0x00
    STS ADMUX, r16

    LDI r16, (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)
    STS ADCSRA, r16 
    STS ADCSRA, r16 
 
    LDS r16,ADCSRA
    ori r16, (1<<ADSC);
    STS ADCSRA, r16
	ret

leitura:
    LDS r16,ADCSRA
    ori r16, (1<<ADSC);
    STS ADCSRA, r16

adc_leitura_loop:		;método responsável pela leitura do sensor
    lds r16,ADCSRA
    sbrc r16,ADSC
    rjmp adc_leitura_loop

leitura_ADC_value: 
    lds r23,ADCL
    lds r25,ADCH
	ret

muda_estado_porta:
	cp r25, r26
	breq liga_porta		;chama a função que liga as portas selecionadas
	call desliga_porta	;chama a função que liga as portas selecionadas
    ret
		
desliga_porta:
	ldi r17, 0b00000000	;zera o valor do registrador
	out PORTB, r17		;desliga todas as portas selecionadas
	ret
	
liga_porta:
	cp r23, r27
	brsh desliga_porta	;chama método para desligar portas
	ldi r17, r24		;valor da variavel com as portas que serão ligadas
	out PORTB, r17		;liga as portas selecionadas pela variavel
	ret