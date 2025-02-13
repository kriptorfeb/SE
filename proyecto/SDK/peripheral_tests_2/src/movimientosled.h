/**
 * Author: Javier Romero Flores
 * Description:
 * Composicion de frases completas para la matriz de 8 displays
 * */

#ifndef MOVIMIENTOSLEDS_H
#define MOVIMIENTOSLEDS_H

#include "led_rgb.h"

#define RED 0
#define GREEN 1
#define BLUE 2
#define LED_0 XPAR_LED_RGB_0_BASEADDR


void normalLEDDelay(){
	int c;
	for ( c = 1 ; c <= 1500 ; c++ ){}
}

void alarmDelay(){
	int c;
	for ( c = 1 ; c <= 1000 ; c++ ){}
}

void fadeUp(Xuint32 LED,Xuint32 baseColor, Xuint32 nextColor){

	//xil_printf("base: %d, next: %d\n",baseColor,nextColor);
	int red = 255,green = 255,blue = 255,i;

	if(baseColor == RED)
		red=0;
	else if(baseColor == GREEN)
		green = 0;
	else if(baseColor == BLUE)
		blue = 0;
	//xil_printf("red: %d ,green %d, blue: %d\n",red,green,blue);
	for(i = 255; i >= 0; i--){
		LED_RGB_mWriteSlaveReg0(LED,0,red);
		LED_RGB_mWriteSlaveReg1(LED,0,green);
		LED_RGB_mWriteSlaveReg2(LED,0,blue);
		normalDelay();
		if(nextColor == RED)
			red=red - 1 ;
		else if(nextColor == GREEN)
			green = green - 1;
		else if(nextColor == BLUE)
			blue = blue - 1;
	}
	//xil_printf("red: %d ,green %d, blue: %d\n",red,green,blue);
}

void fadeDown(Xuint32 LED,Xuint32 baseColor, Xuint32 nextColor){
	//xil_printf("base: %d, next: %d\n",baseColor,nextColor);
	int red = 255,green = 255,blue = 255,i;

	if(baseColor == RED)
		red=0;
	else if(baseColor == GREEN)
		green = 0;
	else if(baseColor == BLUE)
		blue = 0;
	if(nextColor == RED)
		red=0;
	else if(nextColor == GREEN)
		green = 0;
	else if(nextColor == BLUE)
		blue = 0;

	//xil_printf("red: %d ,green %d, blue: %d\n",red,green,blue);
	for(i = 0; i <= 255; i++){
		LED_RGB_mWriteSlaveReg0(LED,0,red);
		LED_RGB_mWriteSlaveReg1(LED,0,green);
		LED_RGB_mWriteSlaveReg2(LED,0,blue);
		normalDelay();
		if(nextColor == RED)
			red=red + 1 ;
		else if(nextColor == GREEN)
			green = green + 1;
		else if(nextColor == BLUE)
			blue = blue + 1;
	}
	//xil_printf("red: %d ,green %d, blue: %d\n",red,green,blue);
}


void arcoiris(Xuint32 LED){
	LED_RGB_mWriteSlaveReg0(LED,0,0);
	LED_RGB_mWriteSlaveReg1(LED,0,255);
	LED_RGB_mWriteSlaveReg2(LED,0,255);

	   //xil_printf("rojo max sube verde\n\r");
	   fadeUp(LED,RED,GREEN);
	   //xil_printf("verde max baja rojo\n\r");
	   fadeDown(LED,GREEN,RED);
	   //xil_printf("verde max sube azul\n\r");
	   fadeUp(LED,GREEN,BLUE);
	   //xil_printf("azul max baja verde\n\r");
	   fadeDown(LED,BLUE,GREEN);
	   //xil_printf("azul max sube rojo\n\r");
	   fadeUp(LED,BLUE,RED);
	   //xil_printf("rojo max baja azul\n\r");
	   fadeDown(LED,RED,BLUE);

}

void arcoiris3(){
	LED_RGB_mWriteSlaveReg0(LED_0,0,0);
	LED_RGB_mWriteSlaveReg1(LED_0,0,255);
	LED_RGB_mWriteSlaveReg2(LED_0,0,255);


	fadeUp(LED_0,RED,GREEN);
	fadeDown(LED_0,GREEN,RED);
	fadeUp(LED_0,GREEN,BLUE);
	fadeDown(LED_0,BLUE,GREEN);
	fadeUp(LED_0,BLUE,RED);
	fadeDown(LED_0,RED,BLUE);
}

void alerta(){
	LED_RGB_mWriteSlaveReg0(XPAR_LED_RGB_0_BASEADDR,0,0);
	LED_RGB_mWriteSlaveReg1(XPAR_LED_RGB_0_BASEADDR,0,255);
	LED_RGB_mWriteSlaveReg2(XPAR_LED_RGB_0_BASEADDR,0,255);

	int i;
	for(i = 0;i <=255;i++){
		LED_RGB_mWriteSlaveReg0(XPAR_LED_RGB_0_BASEADDR,0,i);
		alarmDelay();
	}

	for(i = 255;i >=0;i--){
		LED_RGB_mWriteSlaveReg0(XPAR_LED_RGB_0_BASEADDR,0,i);
		alarmDelay();
	}

}

#endif /** MOVIMIENTOSLEDS_H */
