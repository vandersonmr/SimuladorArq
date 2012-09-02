/* memoria */
word m[MEMORY_W]; 
/* area inicial da memoria - escrita na tela */
int mfirst;
/* area final da memoria - escrita na tela */
int mlast;
/*ultimo endereco da memoria de instrucoes */
int endimem;

/* inicializacao */
void MEMORIA_Inicializacao1(char* namearq) {


  /* area de memoria para ser escrita na tela */
  mfirst = 0;
  mlast  = 0;
  endimem = 0;
  /* carrega arquivo a ser executado */
  MEMORIA_CarregueArquivo(namearq);

}
