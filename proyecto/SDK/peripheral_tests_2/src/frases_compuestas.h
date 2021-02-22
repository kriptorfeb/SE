/**
 * Author: Javier Romero Flores
 * Description:
 * Composicion de frases completas para la matriz de 8 displays
 * */

#ifndef FRASES_COMPUESTAS_H
#define FRASES_COMPUESTAS_H

#include "caracteres.h"


void normalDelay(){
	int c;
	for ( c = 1 ; c <= 1500 ; c++ ){}
}

void slowDelay(){
	int c,j;

	for ( c = 1 ; c <= 13500 ; c++ ){
		for ( j = 1 ; j <= 250 ; j++ ){}
	}

	//for(c = 1; c <= 843750;c++){}
}

void aSecondDelay(){
	int c,j;

	for ( c = 1 ; c <= 13500 ; c++ ){
		for ( j = 1 ; j <= 63 ; j++ ){}
	}
}

void write_winner(Xuint32 baseaddr){
	write_W(baseaddr,0);
	write_I(baseaddr,1);
	write_N(baseaddr,2);
	write_N(baseaddr,3);
	write_E(baseaddr,4);
	write_R(baseaddr,5);
	write_smile(baseaddr,6);
	write_espacio(baseaddr,7);
}

void write_looser(Xuint32 baseaddr){
	write_L(baseaddr,0);
	write_O(baseaddr,1);
	write_O(baseaddr,2);
	write_S(baseaddr,3);
	write_E(baseaddr,4);
	write_R(baseaddr,5);
	write_sad(baseaddr,6);
	write_espacio(baseaddr,7);
}

void varios(Xuint32 baseaddr){

	write_winner(baseaddr);
	while(BANNER_mWriteFIFOFull(baseaddr)){}
	normalDelay();
	write_looser(baseaddr);

}

void mostrarCartasLetras(Xuint32 baseaddr,Xuint32 dir){
	write_A_DIR(baseaddr,0,dir);
	write_diamante_DIR(baseaddr,1,dir);
	write_B_DIR(baseaddr,2,dir);
	write_diamante_DIR(baseaddr,3,dir);
	write_C_DIR(baseaddr,4,dir);
	write_diamante_DIR(baseaddr,5,dir);
	write_D_DIR(baseaddr,6,dir);
	write_diamante_DIR(baseaddr,7,dir);
}

void mostrarCartasNumeros(Xuint32 baseaddr,Xuint32 dir){
	write_1_DIR(baseaddr,0,dir);
	write_diamante_DIR(baseaddr,1,dir);
	write_2_DIR(baseaddr,2,dir);
	write_diamante_DIR(baseaddr,3,dir);
	write_3_DIR(baseaddr,4,dir);
	write_diamante_DIR(baseaddr,5,dir);
	write_4_DIR(baseaddr,6,dir);
	write_diamante_DIR(baseaddr,7,dir);
}

void cuentaAtras(Xuint32 baseaddr){
	aSecondDelay();
	BANNER_inicializa();
	write_4_DIR(XPAR_BANNER_0_BASEADDR,3,TURN_QUIET);
	aSecondDelay();
	BANNER_inicializa();
	write_3_DIR(XPAR_BANNER_0_BASEADDR,3,TURN_QUIET);
	aSecondDelay();
	BANNER_inicializa();
	write_2_DIR(XPAR_BANNER_0_BASEADDR,3,TURN_QUIET);
	aSecondDelay();
	BANNER_inicializa();
	write_1_DIR(XPAR_BANNER_0_BASEADDR,3,TURN_QUIET);
	aSecondDelay();
	BANNER_inicializa();
}

#endif /** FRASES_COMPUESTAS_H */
