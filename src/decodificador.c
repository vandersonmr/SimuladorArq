
#include "defines.h"
#include "cpu.h"
#include "memoria.h"
#define classMask 0x3C000000
#define src1RegMask 0x3E00000
#define src2RegMask 0x1F0000
#define targetRegMask 0xF800
#define opMask 0x3C0
#define imediatoMask1 0xFFFF
#define imediatoMask2 0x3FFFFFFF
uint32 wData;

CONTROLE_DE *dec2exec;
uint32 formato;
uint32 opcode;
uint32 class;
uint32 src2Reg;

void carregaRegistradores(){
	
        if(formato==0){
                dec2exec->src1Reg
                         = BANCO_GetRegister(
                                dec2exec->src1Reg);
                dec2exec->src2Reg
                         = BANCO_GetRegister(
                                dec2exec->src2Reg);
        }else if(formato==1){
                dec2exec->src1Reg
			= BANCO_GetRegister(
				dec2exec->src1Reg);
        }else if(formato==2){
                // !TODO
        }else if(formato==3){
                // !TODO
        }
}

void decodifica(uint32 data, CONTROLE_DE * regControle)
{
	dec2exec = regControle;
	wData = data;
	uint32 mask = 0xC0000000;
	uint32 formato2 = data & mask;
	formato = formato2 >> 30;
	switch (formato2) {
	case 0x00000000:
		decodificaFormato1();
		break;
	case 0x40000000:
		decodificaFormato2();
		break;
	case 0x80000000:
		decodificaFormato3();
		break;
	case 0xC0000000:
		decodificaFormato4();
		break;
	}
	carregaRegistradores();
}


int32 decodificaOpcode(){        
        if(formato==0){
                switch(class){
                        case 0:
                                return opcode;
                        case 1:
                                return opcode+6;
                        case 2:
                        case 3: 
				dec2exec->acessaMemoria
						= opcode;

				return 16;
                        case 5:
                        case 6:
				dec2exec->targetReg = 1000;
                                return 16;
                        case 7:
                                dec2exec->Jump=1;
                                return 16;
                }
        }else if(formato==1) {
                if(opcode==16){
                        dec2exec->Jump=1;
			
                        return 16;
                }else{
                        return opcode;
                }
        }else if(formato==2){

        }else if(formato==3){
                dec2exec->Jump=1;
                return 16;
        }
}


void decodificaFormato1()
{
	class = wData & classMask;
	uint32 src1Reg = wData & src1RegMask;
	src2Reg = wData & src2RegMask;
	uint32 targetReg = wData & targetRegMask;
	opcode = wData & opMask;

	class = class >> 26;
	src1Reg = src1Reg >> 21;
	src2Reg = src2Reg >> 16;
	targetReg = targetReg >> 11;
	opcode = opcode >> 6;
	
	dec2exec->src1Reg = src1Reg;
	dec2exec->src2Reg = src2Reg;
	dec2exec->targetReg = targetReg;
	dec2exec->ALU = decodificaOpcode();
}

void decodificaFormato2()
{
	opcode = wData & classMask;
	uint32 src1Reg = wData & src1RegMask;
	uint32 targetReg = wData & src2RegMask;
	uint32 imediato = wData & imediatoMask1;

	opcode = opcode >> 26;
	src1Reg = src1Reg >> 21;
	targetReg = targetReg >> 16;
	
        dec2exec->src1Reg = src1Reg;
        dec2exec->src2Reg = imediato;
        dec2exec->targetReg = targetReg;
        dec2exec->ALU = decodificaOpcode();

}

void decodificaFormato3()
{
	decodificaFormato2();
	//modifica valores !TODO
}

void decodificaFormato4()
{
	uint32 imediato = wData & imediato;
}

