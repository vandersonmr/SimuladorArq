#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "memoria.h"
#include "cpu.h"

/* constructor */
inicialize_simulacao_1(char* namearq){ 

  /* INSTANCIACAO DOS COMPONENTES DO COMPUTADOR */

  /* memória */
  MEMORIA_Inicializacao1(namearq);

  /* cpu */
  CPU_Inicializacao();

}

/* constructor */
inicialize_simulacao_2(char* namearq, int first, int last){ 

  /* INSTANCIACAO DOS COMPONENTES DO COMPUTADOR */

  /* memória */
  MEMORIA_Inicializacao2(namearq, first, last);

  /* cpu */
  CPU_Inicializacao();

}

execute_simulacao() {


}

termine_simulacao() {

  MEMORIA_Finalizacao();
  CPU_Finalizacao();

}

int main(int argc, char **argv) {

  inicialize_simulacao_1();
  execute_simulacao();
  termine_simulacao();

  return 1;

}