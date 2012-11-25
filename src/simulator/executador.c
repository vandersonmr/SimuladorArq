#include "headers/defines.h"
#include "headers/ula.h"
#include "headers/banco.h"
#include "headers/cpu.h"

CONTROLE_EM *outData;
CONTROLE_DE inData;

int32 src1, src2, op;

int32 executaUla()
{
	src1 = inData.src1Reg;
	src2 = inData.src2Reg;
	op = inData.ALU;
	return ULA_execute(src1, src2, op);
}

void executa(CONTROLE_DE dataDecoded, CONTROLE_EM * results)
{
	outData = results;
	inData = dataDecoded;
	int32 res = executaUla();
	results->Pc = dataDecoded.Pc;
	results->ulaResult = res;
	results->targetReg = dataDecoded.targetReg;
	results->acessaMemoria = dataDecoded.acessaMemoria;
	results->src2Reg = dataDecoded.src2Reg;
	results->formato = dataDecoded.formato;
	results->opclass = dataDecoded.opclass;
}
