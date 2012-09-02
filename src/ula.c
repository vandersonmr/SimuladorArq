
/* executa a operacao Tarefa entre os operandos A e B */
int32 ULA_execute (int32 A, int32 B, uint32 Tarefa){ 
  int32 Local = 0;
  
  switch (Tarefa) {
  case 0  : Local = A + B; break;                      /* soma */
  case 1  : Local = (unsigned)A + (unsigned)B; break;  /* soma sem sinal */

  }
 
  return (Local);

}
