
/* registradores especiais */
int32 pc;
/* 32 registradores */
int32 registers[32];

/* inicializacao */
void BANCO_Inicializacao() {
 for(int x=0;x<32;registers[x++] = 0); 
 pc = 0;
}

/* finalizacao */
void BANCO_Finalizacao() {

}

/* armazena dados no resgistrador */
void BANCO_SetRegister (int32 address, int32 data) {
  if (address>=0)
    registers[address] = data; 
}
 
/* retorna dado de um determinado registrador */
int32 BANCO_GetRegister (int32 address) {

 return registers[address];
}

/* armazena dado */
void BANCO_SetPc () {

}

/* retorna dado */
int BANCO_GetPc() {

}
