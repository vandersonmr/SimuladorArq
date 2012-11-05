#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
/* memoria */
word m[MEMORY_W];
word mD[MEMORYD_W];
/* area inicial da memoria - escrita na tela */
int mfirst;
/* area final da memoria - escrita na tela */
int mlast;
/*ultimo endereco da memoria de instrucoes */
int endimem;

/* inicializacao */
void MEMORIA_Inicializacao1(char *namearq)
{
	int i;
	for (i = 0; i < MEMORY_W; m[i++] = 0) ;
	/* area de memoria para ser escrita na tela */
	mfirst = 0;
	mlast = 0;
	endimem = 0;
	/* carrega arquivo a ser executado */
	MEMORIA_CarregueArquivo(namearq);

}

uint32 MEMORIA_Carregue(uint32 address)
{
	if (address < MEMORY_W)
		return m[address];
}

void MEMORIA_Armazene(uint32 address, uint32 data)
{
	if (address < MEMORY_W)
		m[address] = data;
}

void MEMORIA_ArmazeneData(uint32 address, uint32 data){
	if(address < MEMORYD_W)
		mD[address] = data;
}

uint32 MEMORIA_CarregueData(uint32 address){
	if(address < MEMORYD_W)
		return mD[address];
}

void MEMORIA_CarregueArquivo(char *file)
{
	if (file == NULL) {
		printf("Error: file pointer is null.\n");
		exit(1);
	}
	FILE *f = fopen(file, "rt");
	char line[10];
	if (f) {
		uint32 int_output;
		int i = 0;
		while (fgets(line, 9, f) != NULL) {
			sscanf(line, "%x", &int_output);
			m[i++] = int_output;
		}
	} else {
		printf("Error: file does not exist.\n");
	}
	fclose(f);
}
