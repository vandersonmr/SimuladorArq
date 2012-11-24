#include "headers/defines.h"
#include "headers/cpu.h"
#include "headers/banco.h"

uint32 escreveResultado(CONTROLE_MR inData)
{
	if (inData.formato == 2) {
		if (inData.ulaResult == 1) {
			int aux = inData.targetReg;
			BANCO_SetRegister(33, aux + inData.Pc);
		}
	} else {
		BANCO_SetRegister(inData.targetReg, inData.ulaResult);
	}
}
