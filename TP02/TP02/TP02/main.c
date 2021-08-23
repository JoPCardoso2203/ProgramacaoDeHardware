/****************************************************************************
 * Copyright (C) 2021 by Programação de Hardware Engenharia de computação   *
 *                                                                          *
 * This file is part of TP02.                                                *
 *                                                                          *
 * TP02 é um software livre: você pode redistribuí-lo e / ou modificá-lo     *
 * sob os termos da GNU Lesser General Public License conforme publicada    *
 * pela Free Software Foundation, seja a versão 3 da Licença, ou            *
 * (à sua escolha) qualquer versão posterior.                               *
 *                                                                          *
 * O TP02 é distribuído na esperança de que seja útil,                       *
 * mas SEM QUALQUER GARANTIA; sem mesmo a garantia implícita de             *
 * COMERCIALIZAÇÃO ou ADEQUAÇÃO A UM DETERMINADO FIM. Veja o                *
 * GNU Lesser General Public License para obter mais detalhes.              *
 *                                                                          *
 * Você deve ter recebido uma cópia do GNU Lesser General Public            *
 * Licença junto com TP02. Caso contrário, consulte                          *
 *<http://www.gnu.org/licenses/>.                                           *
 * <https://www.doxygen.nl/manual/index.html>                               *
 ****************************************************************************/

/**
 * @file TP02.h
 * @author João Paulo Cardoso D'Oliveira
 * @date 23 Aug 2021
 * @brief TP02 da matéria Programação de Hardware do 6 ciclo de engenharia de computação.
 *
 * O código se refere a um programa de um sensor de luminosidade (LDR)
 * Que faz várias leituras e conforme o resultado envia um valor (High ou Low) para a porta de escolha do usuário
 * As funções foram feitas em assembler e são chamadas em C. 
 * A porta quando ligada, liga uma luz para que o ambiente não fique com baixa luminosidade.
 */

#include <avr/io.h>

/**
 * @brief Este Tp é o segundo TP da disciplica de Programãção de Hardware.
 *
 *  O aluno(a) deverá desenvolver um código em C, em que ele deverá criar as funções de manipulação de IO (usando os registros DDRx,PINx,PORTx) onde cada deverá proporcionar ao usuário
 *  poder escolher qualquer pino e port que ele quiser.  Em seguida, na função main, o aluno deverá implementar um exemplo usando as funçoes, e de preferencia para implementar 
 *  como se fosse um projeto (de sua escolha. EX: Sensor de janelas).A resposta deverá ser implementado cabeçalho de acordo com o exemplo deste e descrição de cada comando usando Doxygen.
 *  A resposta deverá ser enviada para o próprio github do aluno, e postar os arquivos fonte na tarefa do teams, deve-se postar os arquivos em si(não postarem em formato zip).
 */

/**
  * @brief Função que inicializa os registradores 
  * 
  * Esta função inicializa os registradores utilizados
  * nas funções assembly e configura o sensor de luminosidade
  */
extern void inicio();

/**
  * @brief Função responsável pela leitura do sensor 
  * 
  * Esta função faz a leitura dos valores vindos do sensor
  */
extern void leitura();

/**
  * @brief Função muda o estado da porta escolhida 
  * 
  * Esta função altera o valor enviado para a porta escolhida
  * de acordo com o valor lido no sensor
  */
extern char muda_estado_porta(char);

/**
  * @brief Método principal que chama as funções assembly
  * 
  * As funções assembly importadas são chamadas
  *	neste método para serem executadas
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

