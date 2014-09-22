/**
 *  \brief Librerías para el manejo de la USART Atmega16
 *  \author Oscar Arley Betancourt-Juan Carlos Gerena-Jairo Perez.
 */


#ifndef _LIBRERIA_USART_H
#define _LIBRERIA_USART_H

/** \file _libreria_usart.h */
/** \defgroup libreria_usart.h <libreria_usart.h>: Funciones de manejo de la usart Atmega16
	\code
    #include "libreria_usart.h"
    \endcode

    \note

    las funciones que se encuetran en esta libreria son las funciones
    inicializacion de la usart, el modo de trabajo de la usart es decir
    con cuantos bit de parada,si paridad par o impar y los datos a enviar
*/

/**\def F_CPU
    se define la frecuencia*/
#define F_CPU 12000000UL

/**\def HAB_RX
    Se define el macro para la habiltacion de la RX y el vetor de interrupciones*/
#define HAB_RX() UCSRB|=_BV(RXCIE)|_BV(RXEN)
//UCSZ0 8bits
//USBS  bits parada
//UPM0 paridad impar
/**\def  CONF_USART
    Se define el macro pra configurar el modo de trbajo de la USART
   */
#define CONF_USART() UCSRC=(1<<URSEL)|(3<<UPM0)|(1<<USBS)|(3<<UCSZ0)

/**\def rojo
    para comparar el primer dato que se recive*/
#define rojo 1
/**\def verde
   para comparar el segundo dato que se recive*/
#define verde 2
/**\def azul
   para comparar el tercer dato que se recive*/
#define azul 3

/** \fn void de_color(void)
	\brief funcion para decodificar los colores recividos
	\return No retorna nada
*/
void dec_color(void);

#endif
