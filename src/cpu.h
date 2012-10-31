#ifndef CPU_H
#define CPU_H

void CPU_Execute();
void CPU_Imprime();

typedef struct CONTROLE_BD  {
        /* PC */
        unsigned long int Pc;
        /* instrucao */
        unsigned long int Instruction;

}CONTROLE_BD;


typedef struct CONTROLES_DE {
        unsigned long int Pc;
        unsigned long int ALU;
        unsigned long int src1Reg;
        unsigned long int src2Reg;
        unsigned long int targetReg;
        unsigned long int opcode;
}CONTROLE_DE;

typedef struct CONTROLE_EM {

}CONTROLE_EM;

typedef struct CONTROLE_MR {

}CONTROLE_MR; 

#endif 
