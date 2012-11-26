#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "headers/defines.h"
#include "headers/memoria.h"
#include "headers/cpu.h"
#include "headers/banco.h"

void imprimeRegistradores()
{
	int i;
	printf("Registradores \n");
	for (i = 0; i < 31; i += 2) {
		printf("R%d = %d	R%d = %d\n", i,
		       BANCO_GetRegister(i), i + 1, BANCO_GetRegister(i + 1));
	}

	printf("\n ------------------------------------------------\n");
}

void imprimeMemoria(int mS, int mF)
{
	int i;
	printf("Memória \n");
	printf("Endereço  -  Valor\n");
	for (i = mS; i <= mF; i++)
		printf("%d  =  %d\n", i, MEMORIA_CarregueData(i));
	printf("\n ------------------------------------------------\n");
}

int main(int argc, char *argv[])
{
	char *fileName = "codigo.src";
	int mS;
	int mF;
	int pM = 0;
	int reg = 0;
	int steps = 0;
	int e = 0;
	int x;
	for (x = 0; x < argc; x++) {
		char *s = argv[x];
		if (strcmp(s, "-h") == 0 || strcmp(s, "--help") == 0) {
			printf("\nSimulador arquitetura MIPS verão 0.1\n");
			printf("\nParametros: \n\n");
			printf
			    ("	-s <arquivo> Para definir arquivo onde se encontra o código hexadecimal a ser executado.\n");
			printf
			    ("	-r Imprime o valor dos registradores\n");
			printf
			    ("	-pm <inicio> <fim> Imprime uma faixa de valores da memória de dados.\n");
			printf
			    ("	-e Imprime quantidade de instruções executadas.\n");
			printf("	--steps Imprime ciclo por ciclo.");
			printf
			    ("\n		Esse simulador possui poderes de super foca\n\n");
		} else {
			if (strcmp(s, "-s") == 0)
				fileName = argv[x + 1];
			if (strcmp(s, "-r") == 0)
				reg = 1;
			if (strcmp(s, "-pm") == 0) {
				pM = 1;
				mS = atoi(argv[x + 1]);
				mF = atoi(argv[x + 2]);
			}
			if (strcmp(s, "-e") == 0)
				e = 1;
			if (strcmp(s, "--steps")==0)
				steps = 1;
		}

	}

	MEMORIA_Inicializacao1(fileName);
	CPU_Inicializacao();
	if(steps){
		int i=0;
        	while(CPU_Ciclo()){
			i++;
			printf("\033[2J");
			printf("\nCiclo %d - PC = %d\n",i,BANCO_GetPc());
			if (reg)
                		imprimeRegistradores();
        		if (pM)
                		imprimeMemoria(mS, mF);
        		if (e)
	                	imprimirDadosEstatisticos();
			printf("\n Enter para continuar \n");
	                getchar();
        	}
        }else{
		CPU_Execute();
        }
	if (reg)
		imprimeRegistradores();
	if (pM)
		imprimeMemoria(mS, mF);
	if (e)
		imprimirDadosEstatisticos();

	return 1;

}
