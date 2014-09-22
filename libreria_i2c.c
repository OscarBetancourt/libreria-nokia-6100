#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <util/twi.h>
#include "libreria_usart.h"
#include "libreria_i2c.h"
#include "Libreria_Nokia.h"

volatile  uint8_t WR_Mer_L=0x00,WR_Mer_H=0x00,RD_Mer_H=0x00,RD_Mer_L=0x00;
volatile int p_x=0,p_y=0;
//uint16_t reco_m=0,reco_f=0;

//============================================================================//
//                              I2C  START                                   //
//==========================================================================//
void I2c_start(void)
{
//se habilita el two ,la condicion de estar y la int de transmicion completa
    TWCR=_BV(TWINT)|_BV(TWSTA)|_BV(TWEN);
    loop_until_bit_is_set(TWCR,TWINT);
}

//=============================================================================//
//                   Escribir el la EEPROM                                    //
//===========================================================================//
void WR_EEPROM(uint8_t dat)
{

 TWDR=dat;
 TWCR=_BV(TWINT)|_BV(TWEN);
 loop_until_bit_is_set(TWCR,TWINT);//Se espera que la trasmicion sea completa

}

//===============================================================================//
//                     Datos a la EEPROM                                        //
//=============================================================================//
void Mad_EEPROM(uint8_t dat)
{
  if(WR_Mer_L==0xFF)
     {WR_Mer_H++;}

  I2c_start();
  WR_EEPROM(DIR_WR);//Se le dice a la EEprom que se le va a escribir
  WR_EEPROM(WR_Mer_H);//Dierrcion alta de la EEPROM
  WR_EEPROM(WR_Mer_L);//Dirrecion baja de la EEPROM
  WR_EEPROM(dat);
  WR_Mer_L++;
  TWCR=_BV(TWINT)|_BV(TWEN)|_BV(TWSTO);
  PORTB=dat;

}
//========================================================================//
//                          Leer EEPROM                                  //
//======================================================================//
void leer_EEPROM(void)
{
uint8_t dat;
 if(RD_Mer_L==0xff)
   {
     RD_Mer_H++;}

 _delay_ms(3);
  I2c_start();
  WR_EEPROM(DIR_WR);//Dirrecion de la memoria para escuribir en la memoria
  WR_EEPROM(RD_Mer_H);//Dirrecion Alta de la EEPROM
  WR_EEPROM(RD_Mer_L);//Dirrecion baja de la EEPROM

  I2c_start();

  dat=Read_EEPROM();

Lcd_pixel(p_x,p_y,dat);
Lcd_pixel(p_x,p_y,dat);
Lcd_pixel(p_x,p_y,dat);

PORTB=dat;
    if(p_y==132)
   {
     p_x++;
     p_y=0;
   }
  if(p_x==132)
  {
     p_x=0;
  }
p_y++;
RD_Mer_L++;


TWCR=_BV(TWINT)|_BV(TWEN)|_BV(TWSTO);

}

uint8_t Read_EEPROM(void)
{
 uint8_t dat;
 WR_EEPROM(DIR_RD); //Dirrecioon de la memoria para leer
 TWCR=_BV(TWINT)|_BV(TWEN);
 loop_until_bit_is_set(TWCR,TWINT);
 dat=TWDR;

 return dat;

}


