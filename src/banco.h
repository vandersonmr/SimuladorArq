#ifndef REGISTERS_H
#define REGISTERS_H

/* inicializador */
void BANCO_Inicializacao();
/* temporizador */
void BANCO_Finalizacao();
/* seta registrador */
void BANCO_SetRegister(uint32,int32);
/* retorna valor de um registrador */
int32 BANCO_GetRegister(uint32);
/* seta contador de programa */
void BANCO_SetPc(int32);
/* retorna valor do contador de programa */
int32 BANCO_GetPc();

#endif
