#include "defines.h"
#include "banco.h"
/* registradores especiais */
int32 pc;
/* 32 registradores */
int32 registers[numRegs];

/* inicializacao */
void BANCO_Inicializacao()
{
	int x;
	for (x = 0; x < numRegs; registers[x++] = 0); 
	pc = 0;
}

/* finalizacao */
void BANCO_Finalizacao()
{

}

/* armazena dados no resgistrador */
void BANCO_SetRegister(int32 address, int32 data)
{
	if (address >= 0 & address <= numRegs)
		registers[address] = data;
}

/* retorna dado de um determinado registrador */
int32 BANCO_GetRegister(int32 address)
{
	if (address >= 0 & address <= numRegs)
		return registers[address];
}

/* armazena dado */
void BANCO_SetPc(int32 data)
{
	pc = data;
}

/* retorna dado */
int32 BANCO_GetPc()
{
	return pc;
}
