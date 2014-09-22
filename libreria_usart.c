#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "libreria_usart.h"
#include "libreria_i2c.h"
#include "Libreria_Nokia.h"

volatile uint8_t colores=0,dat_col1,dat_col2,dat_col3;
volatile int i=0;
//============================================================================//
//                         Decodifica los clores RGB                         //
//==========================================================================//
void dec_color(void)
{
 uint8_t col_rel;
 colores++;

     switch(colores)
     {
      case rojo:
                dat_col1=UDR&0xE0;//Se toma el dato del color rojo
                break;
      case verde:
                 dat_col2=(UDR>>3)&0x1C;//se toma el dato del color verde
                 break;
      case azul:
                 dat_col3=(UDR>>6)&0x03;//Se toma el dato del color azul
                break;
      default:
               break;

    }

   if(colores==3)
    {
       col_rel=(dat_col1)|(dat_col2)|(dat_col3);
       PORTB=col_rel;
       colores=0;
       Mad_EEPROM(col_rel);
    }

}




ISR(USART_RXC_vect)
{
 /*if(UDR=='0')
  {
      PORTB=UDR;
      leer_EEPROM();
  }*/

   dec_color();

}

