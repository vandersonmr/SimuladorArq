#include "defines.h"
#include "cpu.h"
#include "banco.h"

uint32 escreveResultado(CONTROLE_MR inData){
		if(inData.formato==2){
			if(inData.ulaResult==1){
				BANCO_SetRegister(33,inData.targetReg+BANCO_GetPc());
			}
		}else{
			BANCO_SetRegister(inData.targetReg,inData.ulaResult);
		}	
}
