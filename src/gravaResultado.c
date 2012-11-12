#include "defines.h"
#include "cpu.h"
#include "banco.h"

uint32 escreveResultado(CONTROLE_MR inData){
		BANCO_SetRegister(inData.targetReg,inData.ulaResult);
			
}
