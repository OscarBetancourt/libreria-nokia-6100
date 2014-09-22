/**
 *  \brief Librerías para el manejo de pantalla Nokia 6100
 *  \author Oscar Arley Betancourt-Juan Carlos Gerena-Jairo Perez.
 */

#ifndef _LIBRERIA_NOKIA_H_
#define _LIBRERIA_NOKIA_H_

/** \file mi_libreria_lcd.h */
/** \defgroup mi_libreria_lcd.h <mi_libreria_lcd.h>: Funciones de manejo para pantallas nokia 6100
	\code
    #include "mi_libreria_lcd.h"
    \endcode

    \note Si no se declara el macro que define puerto del lcd
	por defecto el puerto utilizado es el PUERTO A

    las funciones que se encuetran en esta libreria son las funcion de
    inicializacion de la pantalla, el cambio de color de la pantlla
    completa,graficar un pixel o varios al tiempo,cambiar las coordenadas
    de la pantalla,graficar cuadrados,lineas y cuadfros de un solo color
*/
/**\def reset
    pin del puerto donde se manda la señal de reset a la lcd Nokia 6100*/
#define reset 2
/**\def bit
     pin del puerto donde se mandan los datos a la lcd Nokia 6100*/
#define bit   3
/**\def clk
    pin del puerto que manela la entrada de reloj de la lcd Nokia 6100*/
#define clk   4
/**\def cs
    pin del puerto que maneja el cs de la lcd Nokia 6100  */
#define cs    5

//#define Puerto_nokia C

#ifndef Puerto_nokia
	# warning "Puerto lcd no definido, por defecto Puerto A"
	# define Puerto_nokia A
#endif

#define CONCAT(a,b)    a##b
#define OUTPORT(name)  CONCAT(PORT,name)
#define INPORT(name)   CONCAT(PIN,mane)
#define DDRPORT(name)  CONCAT(DDR,name)
#define PORT           OUTPORT(Puerto_nokia)
#define PIN            INPORT(Puerto_nokia)
#define DDR            DDRPORT(Puerto_nokia)

/**\def sleep_oup
    comando*/
#define Sleep_out 0x11
/**\def invonn
    comando invertir colores*/
#define Invon     0x21

/**\def colomod
    comando para saber con cuantos bit se quiere trabajar*/
#define Colmod    0x3A
/**\def pixel_12
    dato declara que se trabaje con 12 pixeles*/
#define Pix_12    0x03
/**\def setco
    comando de contraste*/
#define Setcon    0x25
/**\def contraste
    dato que indica el contraste de la lcd nokia 6100*/
#define contraste 0x60
/**\def madctl
    comando para cambiar coordenadas*/
#define Madctl    0x36
#define posicion  0xC8
/**\def dispon
    comando para habilitar lcd*/
#define Dispon    0x29

/**\def dato
     define si lo que se le esta mandando a la lcd es un dato*/
#define dato    1

/**\def comando
    define si lo que se le esta mandando a la lcd es un comando*/
#define comando 0

/**\def sbi
     saca un uno por un pin del puerto*/
#define sbi(sfr,bit)   (sfr|=(1<<bit))

/**\def  cbi
     saca un cero por un pin del puerto*/
#define cbi(sfr,bit)   (sfr&=~(1<<bit))

/**\def  despl_bit_der(dat)
     despalza un bit a la dereha*/
#define despl_bit_der(dat) (dat>>=1)
/**\def clk0()
     saca un cero por en pin de clk del puerto*/
#define clk0()  cbi(PORT,clk)

/**\def clk1()
     saca un uno por el pin de clk del puerto*/
#define clk1()  sbi(PORT,clk)

/**\def bit0()
     saca un uno por el pin de datos del puerto*/
#define bit0()  cbi(PORT,bit)

/**\def bit1()
     saca un uno por el pin de datos del puerto*/
#define bit1()  sbi(PORT,bit)

/**\def rest0()
     saca un cero por el pin de reset del puerto*/
#define reset0() cbi(PORT,reset)

/**\def reset(1)
     saca un uno por el pin de reset del puerto*/
#define reset1() sbi(PORT,reset)

/**\def cs0()
     saca un cero por el pin de cs del puerto*/
#define cs0() cbi(PORT,cs)

/**\def cs1()
     saca un uno por el pin de cs del puerto*/
#define cs1() sbi(PORT,cs)

/**\def caset
    comando posicion en x*/
#define Caset 0x2A
/**\def paset
    comando posicion en y*/
#define Paset 0x2B
/**\def ramwr
    comando escribir memoria*/
#define RAMWR 0x2C
/**\def Rojo
    dato para el color rojo*/
#define Rojo 0xE0

/**\def Azul
    dato para el color Azul*/
#define Azul 0x02
/**\def Verde
    dato para el color verde*/
#define Verde 0x1C

/**\def Blanco
    dato para el color blanco*/
#define Blanco 0xff
/**\def Negro
    dato para el color negro*/
#define Negro 0x00


void inic_puerto(void);
/** \fn void mandar_dato_nokia(uint8_t datobit, uint8_t D_C)
	\brief funcion que manda bit por bit a la lcd Nokia
	\param datobit un entero sin signo de 8bits que indica el dato o camdo
	\param D_C un entero que indica que si bit es dato o comando
	\return No retorna nada
*/
void mandar_dato_nokia(uint8_t datobit,uint8_t D_C);

/** \fn void inic_nokia_6100(void)
	\brief funcion para inicializar la lcd de Nokia 6100
	\return No retorna nada
*/
void inic_nokia_6100(void);
/** \fn void Limpiar_lcd_color(int color)
	\brief funcion limpia la pantalla de un solo color
	\param color un entero que indica el color a llenar la pantalla
	\return No retorna nada
*/
void Limpiar_lcd_color(int color);

/** \fn void lcd_pixeles(int x_min,int x_max,int y_min,int y_max)
	\brief funcion que manda un solo pixel o varios para rellenar parte de la pantalla
	 si se quiere un solo pixel se manda la misma posicion en x y la misma
	 posicion en y
	\param int x entero que indica la posicion en x
    \param int y entero que indica la posicion en y
	\param int color entero que indica el color del pixel
	\return No retorna nada
*/
void Lcd_pixel(uint8_t x,uint8_t y,uint8_t color);




#endif

