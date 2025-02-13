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


int main() 
{


   Xil_ICacheEnable();
   Xil_DCacheEnable();

   print("---Entering main---\n\r");

   Xuint32 baseaddr,value,dato,oldValue;
   	Xil_ICacheEnable();
   	Xil_DCacheEnable();

   	print("---Entering main---\n\r");

   	baseaddr =  XPAR_KEYPAD_0_BASEADDR;
   	xil_printf("Pulsar una tecla:\n\r");
   	value = KEYPAD_mReadReg(baseaddr,0);
   	xil_printf("se ha leido: %04x el reg \n\r",value);
   	KEYPAD_mWriteReg(baseaddr,0,0);
   	oldValue =  value;


   	xil_printf("Escritura de banner\n\r");
   	BANNER_inicializa();
   	//write_A_DIR(XPAR_BANNER_0_BASEADDR,1,TURN_LEFT);

   	//varios(baseaddr);
   	write_winner(XPAR_BANNER_0_BASEADDR);

   	while(1){
   	   if(value != oldValue){
   		   dato = (value>>28) & 0xF;
   		   xil_printf("se ha leido %01x \n\r",dato);
   		   oldValue = value;
   	   }
   	   value = KEYPAD_mReadReg(baseaddr,0);
   	   KEYPAD_mWriteReg(baseaddr,0,value);
   	}


   {
      int status;
      
      print("\r\nRunning Bram Example() for xps_bram_if_cntlr_0...\r\n");

      status = BramExample(XPAR_XPS_BRAM_IF_CNTLR_0_DEVICE_ID);

      if (status == 0) {
         xil_printf("Bram Example PASSED.\r\n");
      }
      else {
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

