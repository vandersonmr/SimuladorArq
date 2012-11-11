#include "defines.h"
#include "cpu.h"
#include "memoria.h"
#define maskByte 0xF
#define notMaskByte 0xFFFFFFF0
#define maskDouble 0xFF
#define notMaskDouble 0xFFFFFF00

void acessaMemoria(CONTROLE_EM inData
			,CONTROLE_MR *outData){

	outData->ulaResult = inData.ulaResult;
        outData->targetReg = inData.targetReg;
	int aux;
	uint32 local;
	switch(inData.acessaMemoria){
		case 0: //Lê 1 byte da memória
			local = MEMORIA_CarregueData(inData.ulaResult);
			aux = outData->ulaResult;
			local = local & maskByte;
			aux = aux & notMaskByte;
			outData->ulaResult = aux | local;		
			break;
		case 1: //Lê 2 bytes da memória
			local = MEMORIA_CarregueData(inData.ulaResult);
                        aux = outData->ulaResult;
                        local = local & maskDouble;
                        aux = aux & notMaskDouble;
                        outData->ulaResult = aux | local;   
			break;
		case 2: //Lê 4 bytes da memória
			local = MEMORIA_CarregueData(inData.ulaResult);
			outData->ulaResult = 
					local;
			break;
		case 3: //Escreve 1 byte na memória
			
			break;
		case 4: //Escreve 2 bytes na memória
			break;
		case 5: //Escreve 4 bytes na memória
			MEMORIA_ArmazeneData(inData.ulaResult,inData.src2Reg);
			
			outData->targetReg = -1;
			break;
	}
	
}
