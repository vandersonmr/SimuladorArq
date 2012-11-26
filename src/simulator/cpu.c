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
int32 jmpsop;

/* barreira entre estagio de busca e estagio de decodificacao */
CONTROLE_BD busca2decodificacao;
/* barreira entre  estagio de decodificacao e estagio de execucao */
CONTROLE_DE decodificacao2execucao;
/* barreira entre  estagio de execucao para o estágio de acesso à memória*/
CONTROLE_EM execucao2memoria;
/* barreira entre estagio de acesso à memória e o estagio de escrita do resultado */
CONTROLE_MR memoria2resultado;
void imprimirDadosEstatisticos()
{
	int total = arithop + setop + memop + branch + jmpsop;
	printf("\nDas instruções executadas: \n");
	printf("Aritméticas: %f% \n", ((float)arithop / total) * 100);
	printf("Sets: %f% \n ", ((float)setop / total) * 100);
	printf("Memória: %f% \n ", ((float)memop / total) * 100);
	printf("branch: %f% \n ", ((float)branch / total) * 100);
	printf("jmps: %f% \n ", ((float)jmpsop / total) * 100);
	printf("Total de %d operações.\n\n", total);
}

/* inicializacao */
void CPU_Inicializacao()
{
	/* inicializacao dos contadores */
	arithop = 0;
	setop = 0;
	memop = 0;
	branch = 0;
	jmpsop = 0;
	/* inicializacao de registradores de instrucoes */
	busca2decodificacao.Instruction = 0x18000000;
	decodificacao2execucao.targetReg = -1;
	execucao2memoria.targetReg = -1;
	memoria2resultado.targetReg = -1;
	/* INSTANCIACAO DOS COMPONENTES INTERNOS */
	BANCO_Inicializacao();
}

void Ini_DE()
{
	decodificacao2execucao.Pc = 0;
	decodificacao2execucao.ALU = 16;
	decodificacao2execucao.src1Reg = 0;
	decodificacao2execucao.src2Reg = 0;
	decodificacao2execucao.targetReg = 1000;
	decodificacao2execucao.acessaMemoria = 18446744073709551615;
	decodificacao2execucao.formato = 0;
	decodificacao2execucao.Jump = 0;
}

void Ini_EM()
{
	execucao2memoria.ulaResult = 0;
	execucao2memoria.opcode = 0;
	execucao2memoria.opclass = 0;
	execucao2memoria.formato = 0;
	execucao2memoria.targetReg = 1000;
	execucao2memoria.src2Reg = 0;
	execucao2memoria.acessaMemoria = 18446744073709551615;
	execucao2memoria.Pc = 0;
}

void Ini_MR()
{
	memoria2resultado.formato = 0;
	memoria2resultado.ulaResult = 0;
	memoria2resultado.targetReg = 1000;
	memoria2resultado.Pc = 0;
}

void CPU_LimpaSinais()
{
	Ini_DE();
	Ini_EM();
	Ini_MR();
}

void contarInstrucao()
{
	int formato = memoria2resultado.formato;
	int class = memoria2resultado.opclass;
	if (formato == 0) {
		if (class == 0 || class == 1)
			arithop++;
		else if (class == 2)
			setop++;
		else if (class == 3)
			memop++;
		else if (class == 4 || class == 5)
			jmpsop++;
	} else if (formato == 1)
		arithop++;
	else if (formato == 2)
		branch++;
	else if (formato == 3)
		jmpsop++;
}

void CPU_Execute()
{
	while (CPU_Ciclo()) ;
}

int CPU_Ciclo()
{
	if (BANCO_GetPc() < MEMORY_W) {
		int esvaziaPipe = CPU_Resultado();
		contarInstrucao();
		if (!esvaziaPipe) {
			CPU_Memoria();
			CPU_Execucao();
			CPU_Decodificacao();
		} else {
			CPU_LimpaSinais();
		}
		CPU_Busca();
		return 1;
	} else {
		return 0;
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

	if (decodificacao2execucao.Jump)
		BANCO_SetPc(decodificacao2execucao.Pc);
	word data = 0;
	int PC = BANCO_GetPc();
	data = MEMORIA_Carregue(PC);
	CPU_SetBusca2Decodificacao(PC, data);

	BANCO_SetPc(BANCO_GetPc() + 1);

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
