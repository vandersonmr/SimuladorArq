#include "headers/defines.h"
#include "headers/cpu.h"
#include "headers/banco.h"
#include "headers/decodificador.h"
#include "headers/executador.h"
/* variaveis utilizadas para contadores de instrucao */
int32 arithop;
int32 setop;
int32 memop;
int32 branch;

/* barreira entre estagio de busca e estagio de decodificacao */
CONTROLE_BD busca2decodificacao;
/* barreira entre  estagio de decodificacao e estagio de execucao */
CONTROLE_DE decodificacao2execucao;
/* barreira entre  estagio de execucao para o estágio de acesso à memória*/
CONTROLE_EM execucao2memoria;
/* barreira entre estagio de acesso à memória e o estagio de escrita do resultado */
CONTROLE_MR memoria2resultado;

/* inicializacao */
void CPU_Inicializacao()
{
	/* inicializacao dos contadores */
	arithop = 0;
	setop = 0;
	memop = 0;
	branch = 0;
	/* inicializacao de registradores de instrucoes */
	busca2decodificacao.Instruction = 0x18000000;
	decodificacao2execucao.targetReg = -1;
	execucao2memoria.targetReg = -1;
	memoria2resultado.targetReg = -1;
	/* INSTANCIACAO DOS COMPONENTES INTERNOS */
	BANCO_Inicializacao();
}

void Ini_DE(){
	decodificacao2execucao.Pc = 0;
        decodificacao2execucao.ALU = 16;
        decodificacao2execucao.src1Reg = 0;
        decodificacao2execucao.src2Reg = 0;
        decodificacao2execucao.targetReg = 1000;
        decodificacao2execucao.acessaMemoria = 18446744073709551615;
        decodificacao2execucao.formato = 0;
        decodificacao2execucao.Jump = 0;
}
void Ini_EM(){
        execucao2memoria.ulaResult = 0;
        execucao2memoria.opcode = 0;
        execucao2memoria.opclass = 0;
        execucao2memoria.formato = 0;
        execucao2memoria.targetReg = 1000;
        execucao2memoria.src2Reg = 0;
        execucao2memoria.acessaMemoria = 18446744073709551615;
	execucao2memoria.Pc = 0;
}
void Ini_MR(){
	memoria2resultado.formato = 0;
	memoria2resultado.ulaResult = 0;
	memoria2resultado.targetReg = 1000;
	memoria2resultado.Pc = 0;
}

void CPU_LimpaSinais(){
	Ini_DE();
	Ini_EM();
	Ini_MR();
}

void CPU_Execute()
{
	int i = 0;
	for (i = 0; i < MEMORY_W; i++) {
		int esvaziaPipe = CPU_Resultado();
		if(!esvaziaPipe){
			CPU_Memoria();
			CPU_Execucao();
			CPU_Decodificacao();
		}else{
			CPU_LimpaSinais();
		}
			CPU_Busca();
		
	}
}

/* atualiza barreira entre busca e decodificacao */
void CPU_SetBusca2Decodificacao(uint32 Pc, uint32 Instruction)
{
	busca2decodificacao.Pc = Pc;
	busca2decodificacao.Instruction = Instruction;
}

/* busca de instrucao */
void CPU_Busca()
{

	if(decodificacao2execucao.Jump)
               BANCO_SetPc(decodificacao2execucao.Pc);	 
	word data = 0;
	int PC = BANCO_GetPc();
	data = MEMORIA_Carregue(PC);
	CPU_SetBusca2Decodificacao(PC, data);
	
		BANCO_SetPc(BANCO_GetPc() + 1);

}

int main()
{	
	MEMORIA_CarregueArquivo("codigo.src");
	CPU_Inicializacao();
	CPU_Execute();
		printf("R2 = %d \n",BANCO_GetRegister(2));
	return 0;
}

/* decodificacao de instrucao */
void CPU_Decodificacao()
{
		decodifica(busca2decodificacao.Instruction, &decodificacao2execucao,
			   busca2decodificacao.Pc);
}

/* execucao de instrucao */
void CPU_Execucao()
{
	executa(decodificacao2execucao, &execucao2memoria);
}

/* acesso a memória */
void CPU_Memoria()
{
	acessaMemoria(execucao2memoria, &memoria2resultado);
}

/* escrita do resultado */
int CPU_Resultado()
{
	return escreveResultado(memoria2resultado);
}


void CPU_Imprime()
{

}
