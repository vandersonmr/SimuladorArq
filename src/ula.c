
/* executa a operacao Tarefa entre os operandos A e B */
int32 ULA_execute (int32 A, int32 B, uint32 tarefa){ 
  int32 local = 0;
  
  switch (tarefa) {
	case 0 : local = A + B; break; 
 	case 1 : local = (unsigned)A + (unsigned)B; break;
	case 2 : local = A - B; break;
	case 3 : local = (unsigned)A - (unsigned)B; break;
	//case 4 : local = A * B; break; Pode ter * na ULA?
	//case 5 : local = (unsigned)A * (unsigned)B; break;
	case 6 : local = A & B; break;
        case 7 : local = A | B; break;	
	case 8 : local = A ^ B; break;
	case 9 : local = ~(A & B); break;
	case 10: local = ~(A | B); break;
	case 11: local = ~(A ^ B); break;
	case 12: local = ~(A); break;
	case 13: local = A  << B; 
	case 14: local = A >> B;
	case 15: local = ASL(A,B);
  }
 
  return (local);

}

int32 ASL(int32 A,int32 B){
	//!TODO	
	return 0;
}

