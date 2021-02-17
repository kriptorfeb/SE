/*
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE.
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

#include <stdbool.h>

#include <stdio.h>
#include "xparameters.h"
#include "xil_cache.h"
#include "xbasic_types.h"
#include "xgpio.h"
#include "gpio_header.h"
#include "xbasic_types.h"
#include "xbram.h"
#include "bram_header.h"
#include "lcd_pantalla.h"

#define lcd_screen 0xC7000000

#define CLEAR_DISPLAY_CMD 0x00000001
#define RETURN_HOME 0x00000002
#define WRITE_CMD 0X00000200 // 10 0000 0000 escribe en el reg de datos
#define FIRST_ROW 0x00000080 // 00 1000 0000
#define SECOND_ROW 0x000000c0 //00 1100 0000


void LCD_send(Xuint32 cmd){
	Xuint32 stat ;

	xil_printf("%04X\n", cmd);
	while((stat = LCD_PANTALLA_mWriteFIFOFull(XPAR_LCD_PANTALLA_0_BASEADDR)) == true){
		xil_printf("%d\n", stat);
		stat = LCD_PANTALLA_mWriteFIFOFull(XPAR_LCD_PANTALLA_0_BASEADDR);
	}
	LCD_PANTALLA_mWriteToFIFO(XPAR_LCD_PANTALLA_0_BASEADDR,0,cmd);
}

void LCD_start(){
	LCD_PANTALLA_mResetWriteFIFO(lcd_screen);
	LCD_send(CLEAR_DISPLAY_CMD);
	LCD_send(RETURN_HOME);
	LCD_send(WRITE_CMD);
}

void LCD_begin(){
	//Estab. modo de funcionamiento
	LCD_PANTALLA_mWriteReg(lcd_screen,0,0x00111000);
	//Estab. modo de entrada
	LCD_PANTALLA_mWriteReg(lcd_screen,0,0x00000101);
	//Inicializacion
	LCD_PANTALLA_mWriteReg(lcd_screen,0,0x00000001);
}


int main() {

	Xil_ICacheEnable();
	Xil_DCacheEnable();

	print("---Entering main---\n\r");
/*
	LCD_PANTALLA_SelfTest(lcd_screen);

	//Estab. modo de funcionamiento
	LCD_PANTALLA_mWriteReg(lcd_screen,0,0x00111000);
	//Estab. modo de entrada
	LCD_PANTALLA_mWriteReg(lcd_screen,0,0x00000101); // 01 0000 0001
	//Inicializacion
	LCD_PANTALLA_mWriteReg(lcd_screen,0,0x00000001);
*/
//las letras est�n en codigo ascii -> codigo ascii dec a hex
	LCD_start();
	LCD_send(WRITE_CMD + 'J');
	LCD_send(WRITE_CMD + 'A');
	LCD_send(WRITE_CMD + 'J');
	LCD_send(WRITE_CMD + 'A');
	LCD_send(WRITE_CMD + 'J');
	LCD_send(WRITE_CMD + 'A');

	{
		u32 status;

		print("\r\nRunning GpioOutputExample() for leds_gpio...\r\n");

		status = GpioOutputExample(XPAR_LEDS_GPIO_DEVICE_ID,8);

		if (status == 0) {
			print("GpioOutputExample PASSED.\r\n");
		}
		else {
			print("GpioOutputExample FAILED.\r\n");
		}
	}

	{
		int status;

		print("\r\nRunning Bram Example() for xps_bram_if_cntlr_0...\r\n");

		status = BramExample(XPAR_XPS_BRAM_IF_CNTLR_0_DEVICE_ID);

		if (status == 0) {
			xil_printf("Bram Example PASSED.\r\n");
		} else {
			print("Bram Example FAILED.\r\n");
		}
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

