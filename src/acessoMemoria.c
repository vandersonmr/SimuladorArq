#include "defines.h"
#include "cpu.h"
#include "memoria.h"

void acessaMemoria(CONTROLE_EM inData
			,CONTROLE_MR *outData){
	outData->ulaResult = inData.ulaResult;	
	outData->targetReg = inData.targetReg;
}
