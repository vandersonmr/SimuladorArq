#include "headers/defines.h"
#include "headers/cpu.h"
#include "headers/banco.h"

uint32 escreveResultado(CONTROLE_MR inData)
{
	if (inData.formato == 2) {
		if (inData.ulaResult == 1) {
			int aux = inData.targetReg;
			BANCO_SetRegister(33, aux + BANCO_GetPc());
		}
	} else {
		BANCO_SetRegister(inData.targetReg, inData.ulaResult);
	}
}
