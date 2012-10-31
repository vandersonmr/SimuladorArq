
#include "defines.h"
#include "cpu.h"
#include "memoria.h"
#define classMask 0x78000000
#define src1RegMask 0x3C00000
#define src2RegMask 0x3E0000
#define targetRegMask 0x1F000
#define opMask 0xF80
uint32 wData;

CONTROLE_DE *dec2exec;

void decodifica(uint32 data,CONTROLE_DE *regControle){
	dec2exec=regControle;
	wData=data;
	uint32 mask = 0xFC000000;
	uint32 formato = data & mask;
	switch(formato){
		case 0x00000000: decodificaFormato1(); break;
		case 0x40000000: decodificaFormato2(); break;
		case 0x80000000: decodificaFormato3(); break;
		case 0xC0000000: decodificaFormato4(); break;
	}		
}


void decodificaFormato1(){
	uint32 class = wData & classMask;
	uint32 src1Reg = wData & src1RegMask;
	uint32 src2Reg = wData & src1RegMask;	
	uint32 targetReg = wData & targetRegMask; 
 	uint32 opcode = wData & opMask;

	class = class >> 26;
	src1Reg = src1Reg >> 21;
	//src2Reg = src2Reg >> 15;
      	targetReg = targetReg >> 11;
	//opcode = opcode >> 6;
	
	dec2exec->src1Reg = src1Reg;
	dec2exec->src2Reg = src2Reg;
	dec2exec->targetReg = targetReg;
	dec2exec->opcode = opcode;	
}

int main(){
	CONTROLE_DE teste;
	uint32 data = 0x4610C0;
	decodifica(data,&teste);
	printf("r1: %d \n",teste.src1Reg);
	printf("r2: %d \n",teste.src2Reg);
	printf("rd: %d \n",teste.targetReg);
	printf("op: %d \n",teste.opcode);
	return 0;
}

void decodificaFormato2(){
	
}

void decodificaFormato3(){
	
}

void decodificaFormato4(){	
	
}

