#include "headers/defines.h"
#include "headers/cpu.h"
#include "headers/banco.h"

int escreveResultado(CONTROLE_MR inData)
{
	int aux = 0;
	if (inData.formato == 2) {
		if (inData.ulaResult == 1) {
			aux = inData.targetReg;
			BANCO_SetRegister(33, aux + inData.Pc);
			return 1;
		}else{
			return 0;
		}
	} else {
		BANCO_SetRegister(inData.targetReg, inData.ulaResult);
		return 0;
	}
	
}
