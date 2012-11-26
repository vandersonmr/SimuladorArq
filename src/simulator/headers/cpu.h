#ifndef CPU_H
#define CPU_H
void CPU_Execute();
void CPU_Imprime();
void imprimirDadosEstatisticos();
int CPU_Ciclo();

typedef struct CONTROLE_BD  {
        /* PC */
        unsigned long int Pc;
        /* instrucao */
        unsigned long int Instruction;

}CONTROLE_BD;


typedef struct CONTROLE_DE {
        unsigned long int Pc;
        unsigned long int ALU;
        long int src1Reg;
        long int src2Reg;
        unsigned long int targetReg;
	unsigned long int acessaMemoria;
	unsigned long int formato;
	int Jump;
	unsigned long int opclass;	
}CONTROLE_DE;

typedef struct CONTROLE_EM {
	long int ulaResult;
	unsigned long int opcode;
	unsigned long int opclass;
	unsigned long int formato;
	unsigned long int targetReg;
	long int src2Reg;
	unsigned long int acessaMemoria;
	unsigned long int Pc;
	
}CONTROLE_EM;

typedef struct CONTROLE_MR {
	unsigned long int opclass;
	unsigned long int formato;
	long int ulaResult;
	unsigned long int targetReg;
	unsigned long int Pc;
	
}CONTROLE_MR; 

#endif 
