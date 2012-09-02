
struct CONTROLE_BD {
	/* PC */
	unsigned long int Pc;
	/* instrucao */
	unsigned long int Instruction;

};

struct CONTROLE_DE {

	/* PC */
	unsigned long int Pc;
	/* operacao da alu */
	unsigned long int ALU;

};

struct CONTROLE_EM {

};

struct CONTROLE_MR {

};

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

	/* INSTANCIACAO DOS COMPONENTES INTERNOS */

}

void CPU_Execute()
{

	/* busca da intrucao */
	CPU_Busca();
	/* decodificacao */
	CPU_Decodificacao();
	/* execucao */
	CPU_Execucao();
	/* acesso a memória */
	CPU_Memoria();
	/* escrita do resultado */
	CPU_Resultado();

}

void CPU_Finalizacao()
{

}

/* atualiza barreira entre busca e decodificacao */
void CPU_SetBusca2Decodificacao(uint32 Pc, uint32 Instrucao)
{
	busca2decodificacao.Pc = Pc;
	busca2decodificacao.Instrucao = Instrucao;
}

/* atualiza barreira entre decodificacao e execucao */
void
CPU_SetDecoficao2Execucao(uint32 ALU,
			  uint32 LS,
			  uint32 ENC,
			  uint32 C,
			  uint32 B, uint32 A, uint32 I, uint32 RB, uint32 RA)
{

}

/* atualiza barreira entre execucao e acesso a memoria */
void CPU_SetExecucao2Memoria()
{

}

/* atualiza barreira entre memoria e resultado */
void CPU_SetMemoria2Resultado()
{

}

/* limpa barreira entre busca e decodificacao */
void CPU_LimpaBusca2Decodificacao()
{

	busca2decodificacao.Pc = 0;
	busca2decodificacao.Instruction = 0;

}

/* limpa barreira entre decodificacao e execucao */
void CPU_LimpaDecodificacao2Execucao()
{

}

/* limpa barreira entre execucao e acesso a memoria */
void CPU_LimpaExecucao2Memoria()
{

}

/* limpa barreira entre execucao e acesso a memoria */
void CPU_LimpaMemoria2Resultado()
{

}

/* busca de instrucao */
void CPU_Busca()
{
	word data = 0;

	/* envia pedido de nova instrucao para o barramento */
	data = MEMORIA_Load(BANCO_GetPc());

	/* coloca instrucao no registrador entre busca e decodificacao */
	SetBusca2Decodificacao(BANCO_GetPc(), data);
	/* calculo do novo pc */
	if (decodificacao2execucao.Jump)
		BANCO_SetPc(decodificacao2execucao.Pc);
	else
		BANCO_SetPc(BANCO_GetPc() + 1);
}

/* decodificacao de instrucao */
void CPU_Decodificacao()
{

}

/* execucao de instrucao */
void CPU_Execucao()
{

}

/* acesso a memória */
void CPU_Memoria()
{

}

/* escrita do resultado */
void CPU_Resultado()
{

}

int CPU_Compare(int reg1, int reg2, int opcode)
{
	int local = 0;

	switch (opcode) {
	case 0:
		local = (reg1 == reg2) ? 1 : 0;
		break;
	case 1:
		local = (reg1 != reg2) ? 1 : 0;
		break;
	case 2:
		local = (reg1 < reg2) ? 1 : 0;
		break;
	case 3:
		local = ((unsigned)reg1 < (unsigned)reg2) ? 1 : 0;
		break;
	case 4:
		local = (reg1 <= reg2) ? 1 : 0;
		break;
	case 5:
		local = ((unsigned)reg1 <= (unsigned)reg2) ? 1 : 0;
		break;
	case 6:
		local = (reg1 > reg2) ? 1 : 0;
		break;
	case 7:
		local = ((unsigned)reg1 > (unsigned)reg2) ? 1 : 0;
		break;
	case 8:
		local = (reg1 >= reg2) ? 1 : 0;
		break;
	case 9:
		local = ((unsigned)reg1 >= (unsigned)reg2) ? 1 : 0;
		break;
	case 10:
		local = (reg1 == 1) ? 1 : 0;
		break;
	case 11:
		local = (reg1 == 0) ? 1 : 0;
		break;
	}
	return local;

}

void CPU_Imprime()
{

}