#ifndef acessoMemoria_h
#define acessoMemoria_h
/* inicializações */
MEMORIA_Inicializacao1(char*);
MEMORIA_Inicializacao2(char*,int,int);

/* finalizacao */
MEMORIA_Finalizacao();

/* retorna valor lido de um endereco da memoria */
uint32 MEMORIA_Carregue(uint32); 
uint32 MEMORIA_CarregueData(uint32);
/* escreve um dado em determinado endereco da memoria */
void MEMORIA_Armazene(uint32, word); 
void MEMORIA_ArmazeneData(uint32, word);
/* carrega arquivo para a memoria */
void MEMORIA_CarregueArquivo(char*);

void MEMORIA_Imprime();
#endif

