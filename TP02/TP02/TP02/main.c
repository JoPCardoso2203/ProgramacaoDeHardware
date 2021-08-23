/****************************************************************************
 * Copyright (C) 2021 by Programa��o de Hardware Engenharia de computa��o   *
 *                                                                          *
 * This file is part of TP02.                                                *
 *                                                                          *
 * TP02 � um software livre: voc� pode redistribu�-lo e / ou modific�-lo     *
 * sob os termos da GNU Lesser General Public License conforme publicada    *
 * pela Free Software Foundation, seja a vers�o 3 da Licen�a, ou            *
 * (� sua escolha) qualquer vers�o posterior.                               *
 *                                                                          *
 * O TP02 � distribu�do na esperan�a de que seja �til,                       *
 * mas SEM QUALQUER GARANTIA; sem mesmo a garantia impl�cita de             *
 * COMERCIALIZA��O ou ADEQUA��O A UM DETERMINADO FIM. Veja o                *
 * GNU Lesser General Public License para obter mais detalhes.              *
 *                                                                          *
 * Voc� deve ter recebido uma c�pia do GNU Lesser General Public            *
 * Licen�a junto com TP02. Caso contr�rio, consulte                          *
 *<http://www.gnu.org/licenses/>.                                           *
 * <https://www.doxygen.nl/manual/index.html>                               *
 ****************************************************************************/

/**
 * @file TP02.h
 * @author Jo�o Paulo Cardoso D'Oliveira
 * @date 23 Aug 2021
 * @brief TP02 da mat�ria Programa��o de Hardware do 6 ciclo de engenharia de computa��o.
 *
 * O c�digo se refere a um programa de um sensor de luminosidade (LDR)
 * Que faz v�rias leituras e conforme o resultado envia um valor (High ou Low) para a porta de escolha do usu�rio
 * As fun��es foram feitas em assembler e s�o chamadas em C. 
 * A porta quando ligada, liga uma luz para que o ambiente n�o fique com baixa luminosidade.
 */

#include <avr/io.h>

/**
 * @brief Este Tp � o segundo TP da disciplica de Program���o de Hardware.
 *
 *  O aluno(a) dever� desenvolver um c�digo em C, em que ele dever� criar as fun��es de manipula��o de IO (usando os registros DDRx,PINx,PORTx) onde cada dever� proporcionar ao usu�rio
 *  poder escolher qualquer pino e port que ele quiser.  Em seguida, na fun��o main, o aluno dever� implementar um exemplo usando as fun�oes, e de preferencia para implementar 
 *  como se fosse um projeto (de sua escolha. EX: Sensor de janelas).A resposta dever� ser implementado cabe�alho de acordo com o exemplo deste e descri��o de cada comando usando Doxygen.
 *  A resposta dever� ser enviada para o pr�prio github do aluno, e postar os arquivos fonte na tarefa do teams, deve-se postar os arquivos em si(n�o postarem em formato zip).
 */

/**
  * @brief Fun��o que inicializa os registradores 
  * 
  * Esta fun��o inicializa os registradores utilizados
  * nas fun��es assembly e configura o sensor de luminosidade
  */
extern void inicio();

/**
  * @brief Fun��o respons�vel pela leitura do sensor 
  * 
  * Esta fun��o faz a leitura dos valores vindos do sensor
  */
extern void leitura();

/**
  * @brief Fun��o muda o estado da porta escolhida 
  * 
  * Esta fun��o altera o valor enviado para a porta escolhida
  * de acordo com o valor lido no sensor
  */
extern char muda_estado_porta(char);

/**
  * @brief M�todo principal que chama as fun��es assembly
  * 
  * As fun��es assembly importadas s�o chamadas
  *	neste m�todo para serem executadas
  */
int main(void)
{
	volatile unsigned char portab;
	
    while (1) 
    {
		portab = 0b00000001;
		inicio();
		leitura();
		muda_estado_porta(portab);
    }
}

