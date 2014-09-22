#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "libreria_usart.h"
#include "libreria_i2c.h"
#include "Libreria_Nokia.h"

int main(void)
{
int i=0,c=0;
DDRB=0xff;
DDRD=(1<<PD1)|(0<<PD0);
PORTD=(0<<PD1)|(1<<PD0);
UBRRH=0;
UBRRL=77; //se configura la veloidad a 96000 con un crystal de 12M
HAB_RX();// se habilita la RX
CONF_USART();//se configura la usart
FRE_TWBR;
PRE_TWP;

inic_puerto();
inic_nokia_6100();

Limpiar_lcd_color(Rojo);
_delay_ms(40);

   sei();

while(1)
 {


leer_EEPROM();


 }
    return 0;
}

