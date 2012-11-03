#include "defines.h"
#include "ula.h"
#include "banco.h"
#include "cpu.h"

CONTROLE_EM *outData;
CONTROLE_DE inData;

void salvaDestino(int32 value){
	uint32 formato=inData.formato;
	if(formato==0 || formato==1){
		BANCO_SetRegister(inData.targetReg,
					value);
	}
}

uint32 src1,src2,op;

void carregaOperandos(){
	if(inData.formato==0){
		src1 = BANCO_GetRegister(
				inData.src1Reg);
		src2 = BANCO_GetRegister(
				inData.src2Reg);
		op = inData.ALU; 
	}else if(inData.formato==1){
		// !TODO
	}else if(inData.formato==2){
		// !TODO
        }else if(inData.formato==3){
		// !TODO
        }
}

int32 executaUla(){
	return ULA_execute(src1,src2,op);
}


void executa(CONTROLE_DE dataDecoded, CONTROLE_EM *results)
{
        outData = results;
	inData=dataDecoded;
        carregaOperandos();
        int32 res = executaUla();
        salvaDestino(res);
}

