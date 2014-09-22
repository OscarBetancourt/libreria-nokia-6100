/**
 *  \brief Librerías para el manejo del I2c Atmega16
 *  \author Oscar Arley Betancourt-Juan Carlos Gerena-Jairo Perez.
 */

#ifndef _LIBRERIA_I2C_H
#define _LIBRERIA_I2C_H
/** \file libreria_i2c.h */
/** \defgroup libreria_i2c.h <libreria_i2c.h>: Funciones de manejo i2c
	\code
    #include "libreria_i2c.h"
    \endcode

    \note
*/

#define FRE_TWBR TWBR=4
#define PRE_TWP  TWSR=(0<<TWPS0)
/**\def DIR_WR
    Se define la dirrecion del esclavo para escribir */
#define DIR_WR 0xA0

/**\def DIR_RD
    Se define la dirrecion del esclaco para leer*/
#define DIR_RD 0xA1



/** \fn WR_EEPROM(uint8_t dat)
	\brief funcion que espera que el esclavo halla recivido el dato o dirrecion
	\param uint8_t dato entero sin signo que indica el dato a escribir
	\return No retorna nada
*/
void WR_EEPROM(uint8_t dat);

/** \fn void Mad_EEPROM(uint8_t dat)
	\brief funcion que manda la dirrecion y el dato para escribir
	\param uint8_t dato entero que indica la dirrecion o dato a enviar
	\return No retorna nada
*/
void Mad_EEPROM(uint8_t dat);

/** \fn uint8_t Read_EEPROM(void)
     \return un uint8_t que indica el dato qu quiere ser leido
*/
uint8_t Read_EEPROM(void);

/** \fn void leer_EEPROM(void)
	\brief funcion que indica cual dato quiere ser leido
	\return No retorna nada
*/
void leer_EEPROM(void);

/** \fn I2c_start(void)
	\brief funcion que habilitad el i2c del Atmega16
	\return No retorna nada
*/
void I2c_start(void);
#endif

