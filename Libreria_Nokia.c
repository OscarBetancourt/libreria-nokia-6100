#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "libreria_usart.h"
#include "libreria_i2c.h"
#include "Libreria_Nokia.h"
//=============================================//
//                INI PUERTO                   //
//=============================================//
void inic_puerto(void)
{
 DDR=_BV(cs)|_BV(clk)|_BV(bit)|_BV(reset);
}

//=================================================//
//                MANDAR DATO                     //
//===============================================//
void mandar_dato_nokia(uint8_t datobit,uint8_t D_C)
{
 uint8_t cont=0x80,i;
 clk0();
 (D_C?bit1():bit0());
 clk1();

 for(i=0;i<=7;i++)
  {
   clk0();

   ((datobit&cont)?bit1():bit0());
   clk1();

   despl_bit_der(cont);
  }


}
//=====================================================//
//              INI LCD NOKIA 6100                     //
//====================================================//
void inic_nokia_6100(void)
{
  clk0();
  reset0();
  _delay_ms(20);
  clk1();
  reset1();


  mandar_dato_nokia(Sleep_out,comando);
  mandar_dato_nokia(Invon,comando);
  mandar_dato_nokia(Colmod,comando);
  mandar_dato_nokia(Pix_12,dato);
  mandar_dato_nokia(Setcon,comando);
  mandar_dato_nokia(contraste,dato);
  mandar_dato_nokia(Madctl,comando);
  mandar_dato_nokia(posicion,dato);
 // mandar_dato_nokia(0x2D,comando);
  _delay_ms(20);
  mandar_dato_nokia(Dispon,comando);

}
//=================================================//
//               LIMPIAR LCD                       //
//=================================================//
void Limpiar_lcd_color(int color)
{
  int i;
mandar_dato_nokia(Caset,comando);/** posicion en x**/
mandar_dato_nokia(0,dato);
mandar_dato_nokia(131,dato);

mandar_dato_nokia(Paset,comando);/**posicion en y**/
mandar_dato_nokia(0,dato);
mandar_dato_nokia(131,dato);

mandar_dato_nokia(RAMWR,comando);

for(i=0;i<=((131+1)*(131+1));i++){
  mandar_dato_nokia(color,dato);
  mandar_dato_nokia(color,dato);

  }
 }
//================================================================//
//                    LCD PIXEL                                   //
//================================================================//

void Lcd_pixel(uint8_t x,uint8_t y,uint8_t color)
{

mandar_dato_nokia(Caset,comando);/** posicion en x**/
mandar_dato_nokia(x,dato);
mandar_dato_nokia(x,dato);

mandar_dato_nokia(Paset,comando);/**posicion en y**/
mandar_dato_nokia(y,dato);
mandar_dato_nokia(y,dato);
mandar_dato_nokia(RAMWR,comando);
//

  mandar_dato_nokia(color,dato);
  mandar_dato_nokia(color,dato);


 }


