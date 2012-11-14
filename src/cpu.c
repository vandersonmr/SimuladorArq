#include "defines.h"
#include "cpu.h"
#include "banco.h"
#include "decodificador.h"
#include "executador.h"
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
	busca2decodificacao.Instruction=0x18000000;
	decodificacao2execucao.targetReg=-1;
	execucao2memoria.targetReg=-1;
	memoria2resultado.targetReg=-1;
	/* INSTANCIACAO DOS COMPONENTES INTERNOS */
	BANCO_Inicializacao();

}


void CPU_Execute()
{
	int i=0;
	for(i=0;i<MEMORY_W;i++){
		CPU_Resultado();
		CPU_Memoria();
		CPU_Execucao();
		CPU_Decodificacao();
		CPU_Busca();
	}
}

void CPU_Finalizacao()
{

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
	word data = 0;
	int PC = BANCO_GetPc();
	data = MEMORIA_Carregue(PC);
	CPU_SetBusca2Decodificacao(PC, data);
	if (decodificacao2execucao.Jump)
		BANCO_SetPc(decodificacao2execucao.Pc);
	else
		BANCO_SetPc(BANCO_GetPc() + 1);

	
}

int main(){
	MEMORIA_CarregueArquivo("codigo.src");
	CPU_Inicializacao();
	CPU_Execute();
	
	
	printf("r2 = %d \n", BANCO_GetRegister(2));
	return 0;
}

/* decodificacao de instrucao */
void CPU_Decodificacao()
{
	decodifica(busca2decodificacao.Instruction
			,&decodificacao2execucao,BANCO_GetPc());

}

/* execucao de instrucao */
void CPU_Execucao()
{
	executa(decodificacao2execucao,
			&execucao2memoria);
}

/* acesso a memória */
void CPU_Memoria()
{
	acessaMemoria(execucao2memoria,&memoria2resultado);
}

/* escrita do resultado */
void CPU_Resultado()
{
	escreveResultado(memoria2resultado);
}

void CPU_Imprime()
{

}
