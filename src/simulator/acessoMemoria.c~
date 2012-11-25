#include "headers/defines.h"
#include "headers/cpu.h"
#include "headers/memoria.h"
#define maskByte 0xF
#define notMaskByte 0xFFFFFFF0
#define maskDouble 0xFF
#define notMaskDouble 0xFFFFFF00

void acessaMemoria(CONTROLE_EM inData, CONTROLE_MR * outData)
{
	outData->opclass = inData.opclass;
	outData->formato = inData.formato;
	outData->ulaResult = inData.ulaResult;
	outData->targetReg = inData.targetReg;
	outData->Pc = inData.Pc;

	int aux;
	uint32 uLocal;
	int32 local;
	switch (inData.acessaMemoria) {
	case 0:		//Lê 1 byte da memória
		uLocal = MEMORIA_CarregueData(inData.ulaResult);
		aux = outData->ulaResult;
		local = uLocal & maskByte;
		aux = aux & notMaskByte;
		outData->ulaResult = aux | uLocal;
		break;
	case 1:		//Lê 2 bytes da memória
		uLocal = MEMORIA_CarregueData(inData.ulaResult);
		aux = outData->ulaResult;
		uLocal = uLocal & maskDouble;
		aux = aux & notMaskDouble;
		outData->ulaResult = aux | uLocal;
		break;
	case 2:		//Lê 4 bytes da memória
		local = (int32) MEMORIA_CarregueData(inData.ulaResult);
		outData->ulaResult = local;
		break;
	case 3:		//Escreve 1 byte na memória
		local = MEMORIA_CarregueData(inData.ulaResult);
		inData.src2Reg = inData.src2Reg & 0x000000FF;
		local = local & 0xFFFFFF00;
		MEMORIA_ArmazeneData(inData.ulaResult,
				     (uint32) inData.src2Reg | local);
		outData->targetReg = -1;
		break;
	case 4:		//Escreve 2 bytes na memória
		local = MEMORIA_CarregueData(inData.ulaResult);
		inData.src2Reg = inData.src2Reg & 0x0000FFFF;
		local = local & 0xFFFF0000;
		MEMORIA_ArmazeneData(inData.ulaResult,
				     (uint32) inData.src2Reg | local);
		outData->targetReg = -1;
		break;
	case 5:		//Escreve 4 bytes na memória
		MEMORIA_ArmazeneData(inData.ulaResult, (uint32) inData.src2Reg);

		outData->targetReg = -1;
		break;
	}

}
