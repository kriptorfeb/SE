/*
 *
 * Autor: Javier Romero Flores
 * Asignatura: Sistemas Empotrados
 * Tem�tica: Juego de Tutti frutti/Stop/Alto al l�piz con una cuenta regresiva de 4s
 */

/*
 * 
 *
 * This file is a generated sample test application.
 *
 * This application is intended to test and/or illustrate some 
 * functionality of your system.  The contents of this file may
 * vary depending on the IP in your system and may use existing
 * IP driver functions.  These drivers will be generated in your
 * SDK application project when you run the "Generate Libraries" menu item.
 *
 */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "xparameters.h"
#include "xil_cache.h"
#include "xbasic_types.h"
#include "xbram.h"
#include "bram_header.h"
#include "banner.h"
#include "frases_compuestas.h"
#include "keypad.h"
#include "caracteres.h"
#include "movimientosled.h"


Xuint8 carta1,carta2,carta3,carta4,cartaElegida;
int puntaje[4] = {0};

Xuint32 getNumber(){
	xil_printf("entro a get\n");
	Xuint32 baseaddr,value,dato,oldValue;
	value = KEYPAD_mReadReg(XPAR_KEYPAD_0_BASEADDR,0);
	dato = (value>>28) & 0xF;
	KEYPAD_mWriteReg(XPAR_KEYPAD_0_BASEADDR,0,value);

	while(dato != 0x1 && dato != 0x2 && dato != 0x3 && dato != 0x4){
	   if(value != oldValue){
		   dato = (value>>28) & 0xF;
		   xil_printf("se ha leido %01x \n\r",dato);
		   oldValue = value;
	   }
	   value = KEYPAD_mReadReg(XPAR_KEYPAD_0_BASEADDR,0);
	   //dato = KEYPAD_mReadReg(XPAR_KEYPAD_0_BASEADDR,0);
	   KEYPAD_mWriteReg(XPAR_KEYPAD_0_BASEADDR,0,0);
	}
	return dato;
}


void showCards(){
	xil_printf("carta show cards %d\n",cartaElegida);
	BANNER_inicializa();
	switch(cartaElegida){
	case 1:
		showCard(carta1,3);
		break;
	case 2:
		showCard(carta2,3);
		break;
	case 3:
		showCard(carta3,3);
		break;
	case 4:
		showCard(carta4,3);
		break;
	}
}


int main() 
{
	srand48(time(NULL));
   Xuint32 numPlayers,pnt = 0;
   Xuint8 player1,player2,player3,player4;
   Xuint8 score1,score2,score3,score4;

   Xil_ICacheEnable();
   Xil_DCacheEnable();
   print("---Comezamos el juego---\n\r");
   startGame();
   print("---Selecciona el n� de jugadores (max 4)---\n\r");
   print("---                    				  ---\n\r");

   numPlayers = getNumber();
   xil_printf("Num jugadores: %01x \n",numPlayers);

   xil_printf("C�mo jugar: \n");
   xil_printf("1- Elige una carta para mostrarte una letra\n");
   xil_printf("2- Menciona el nombre de lo que ves en la pantalla que inicie por dicha letra \n");
   xil_printf("3- Empieza la cuenta atr�s , presiona 0 para detener la cuenta (si llegas a 0 pierdes)\n");
   xil_printf("4- Gana el que m�s puntos tenga\n");
   xil_printf("Presiona C para salir \n");

   while(cartaElegida!= 0xC){

	   mostrarCartasNumeros(TURN_QUIET);

	   carta1 = 1 +rand()%26;
	   carta2 = 1 +rand()%26;
	   carta3 = 1 +rand()%26;
	   carta4 = 1 +rand()%26;

	   cartaElegida = getNumber();
	   xil_printf("cartaElegida: %01x \n",cartaElegida);
	   showCards();
	   slowDelay();
	   showRandomQuestion(TURN_LEFT);
	   aSecondDelay();
	   pnt += cuentaAtras();
	   xil_printf("pnt: %d \n",pnt);
	   /*cartaElegida = getNumber();
	   xil_printf("cartaElegida: %01x \n",cartaElegida);*/
   }


   
   /*
    * Peripheral SelfTest will not be run for xps_uartlite_0
    * because it has been selected as the STDOUT device
    */


   print("---Exiting main---\n\r");

   Xil_DCacheDisable();
   Xil_ICacheDisable();

   return 0;
}

