#include "defines.h"
#include "cpu.h"
#include "memoria.h"

void acessaMemoria(CONTROLE_EM inData
			,CONTROLE_MR *outData){

	outData->ulaResult = inData.ulaResult;
        outData->targetReg = inData.targetReg;

	uint32 local;
	switch(inData.acessaMemoria){
		case 0: //Lê 1 byte da memória
		 		
			break;
		case 1: //Lê 2 bytes da memória
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
			MEMORIA_ArmazeneData(inData.ulaResult,inData.targetReg);
			inData.targetReg = -1;
			break;
	}
	
}
