
#include "headers/defines.h"
#include "headers/cpu.h"
#include "headers/memoria.h"
#define classMask 0x3C000000
#define src1RegMask 0x3E00000
#define src2RegMask 0x1F0000
#define targetRegMask 0xF800
#define opMask 0x7C0
#define imediatoMask1 0xFFFF
#define imediatoMask2 0x3FFFFFFF
uint32 wData;

CONTROLE_DE *dec2exec;
uint32 formato;
uint32 opcode;
uint32 class;
int32 src1Reg;
int32 src2Reg;
int32 imediato;

void carregaRegistradores(){
	
        if(formato==0){
	        	dec2exec->src1Reg
                        	= BANCO_GetRegister(
                                	dec2exec->src1Reg);
                	dec2exec->src2Reg
                        	 = BANCO_GetRegister(
                                	dec2exec->src2Reg);
		if(class==4){
			dec2exec->src2Reg = 1;
			uint32 aux = dec2exec->Pc;
			dec2exec->Pc=dec2exec->src1Reg;
			dec2exec->src1Reg=aux;
		}else if(class==5){
			dec2exec->Pc = BANCO_GetRegister(31);
		}
        }else if(formato==1){	
                dec2exec->src1Reg
			= BANCO_GetRegister(
				dec2exec->src1Reg);
		dec2exec->src2Reg
			= imediato;
		if(opcode==14){
			dec2exec->src1Reg 
				= dec2exec->Pc;
		}		
		 
        }else if(formato==2){
		 dec2exec->src1Reg
                                = BANCO_GetRegister(
                                        dec2exec->src1Reg);
                 dec2exec->src2Reg
                                = BANCO_GetRegister(
                                        dec2exec->src2Reg);
        }else if(formato==3){
                dec2exec->src1Reg 
			= dec2exec->Pc;
		dec2exec->Pc=imediato;
		dec2exec->src2Reg
			= 1;
        }
}

void limpaSaida(){
        dec2exec->Pc=0;
        dec2exec->ALU=0;
        dec2exec->src1Reg=0;
        dec2exec->src2Reg=0;
        dec2exec->targetReg=0;
        dec2exec->acessaMemoria=0;
        dec2exec->Jump=0;
	dec2exec->formato=0;
}

void decodifica(uint32 data, CONTROLE_DE * regControle,uint32 Pc)
{
	dec2exec = regControle;
	limpaSaida();
	dec2exec->Pc = Pc;
	wData = data;
	dec2exec->acessaMemoria=-1;
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
	dec2exec->formato=formato;
	dec2exec->opclass = class;
}


int32 decodificaOpcode(){        
        if(formato==0){
                switch(class){
                        case 0:
                                return opcode;
                        case 1:
                                return opcode + 6;
                        case 2:
				return opcode + 18;
                        case 3: 
				dec2exec->acessaMemoria
						= opcode;
				if(opcode>2){
					dec2exec->targetReg 
						= 1000;
				}
				return 16;
			case 4:
				dec2exec->Jump=1;	
				return 0;
                        case 6:
				dec2exec->targetReg = 1000;
                                return 16;
                        case 5:
                                dec2exec->Jump=1;
				dec2exec->targetReg=1000;
                                return 16;
			
                }
        }else if(formato==1) {
                if(opcode==14){
			dec2exec->targetReg
					= 33;                       
                        return 0;
                }else if(opcode==13){
			return 17;
		}else{
                        return opcode;
                }
        }else if(formato==2){
		return 18+opcode;
        }else if(formato==3){
                dec2exec->Jump=1;
		dec2exec->targetReg
			= 31; 
                return 0;
        }
}


void decodificaFormato1()
{
	class = wData & classMask;
	src1Reg = wData & src1RegMask;
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
	src1Reg = wData & src1RegMask;
	uint32 targetReg = wData & src2RegMask;
	unsigned short int imediato2 = wData & imediatoMask1;
	
	imediato = (short int) imediato2;
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
	uint32 aux = dec2exec->src2Reg;
	dec2exec->src2Reg = dec2exec->targetReg;
	dec2exec->targetReg=aux;
	dec2exec->ALU = decodificaOpcode();
}

void decodificaFormato4()
{
	imediato = wData & imediatoMask2;
	dec2exec->ALU = decodificaOpcode();
}

