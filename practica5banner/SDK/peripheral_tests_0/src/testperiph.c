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
#include "banner_pantalla.h"

#include "caracteres.h"
#include "frases_compuestas.h"


void BANNER_enviar(Xuint32 baseaddr,Xuint32 col, Xuint32 fil,Xuint32 dato){

	while(BANNER_PANTALLA_mWriteFIFOFull(baseaddr)){}

	Xuint32 data;

	data = ((fil & 0xff)<< (31-7)) + ((col & 0xff) << (31-15)) + ((dato & 0xff)<< (31-23));

	BANNER_PANTALLA_mWriteToFIFO(baseaddr,0,data);
}

void BANNER_inicializa(){
	Xuint32 dato,fila,columna,data;
	dato=0x1;
	for(fila = 0; fila < 7; fila++){
			for(columna = 0; columna < 8; columna++){
				data = (( fila & 0xff ) << (31 -7)) +  (( columna & 0xff ) << (31 -15)) + (( dato & 0xff ) << (31 -23));
				//baseaddr = XPAR_BANNER_0_BASEADDR;
				BANNER_PANTALLA_mWriteToFIFO( XPAR_BANNER_PANTALLA_0_BASEADDR , 0, data );
			}
	}
}

int main() 
{

	Xuint32 baseaddr = XPAR_BANNER_PANTALLA_0_BASEADDR;
   Xil_ICacheEnable();
   Xil_DCacheEnable();

   print("---Entering main---\n\r");


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
   xil_printf("Escritura de banner\n\r");
   BANNER_inicializa();
   
   BANNER_enviar(baseaddr,0,0,0x0E);
   BANNER_enviar(baseaddr,0,1,0x11);
   BANNER_enviar(baseaddr,0,2,0x11);
   BANNER_enviar(baseaddr,0,3,0x1F);
   BANNER_enviar(baseaddr,0,4,0x11);
   BANNER_enviar(baseaddr,0,5,0x11);
   BANNER_enviar(baseaddr,0,6,0x11);
	

   BANNER_enviar(baseaddr,2,1,0x11);
   BANNER_enviar(baseaddr,3,1,0x11);
   BANNER_enviar(baseaddr,1,4,0x1f);
   BANNER_enviar(baseaddr,1,5,0x1f);
   BANNER_enviar(baseaddr,1,6,0x1f);


   /*
    * Peripheral SelfTest will not be run for xps_uartlite_0
    * because it has been selected as the STDOUT device
    */


   print("---Exiting main---\n\r");

   Xil_DCacheDisable();
   Xil_ICacheDisable();

   return 0;
}

