#include "headers/defines.h"

int32 ASL(int32 A, int32 B)
{
	int i = 0;
	int result = A;
	for (i = 0; i < B; i++) {
		result = result * 2;
	}
	return result;
}

/* executa a operacao Tarefa entre os operandos A e B */
int32 ULA_execute(int32 A, int32 B, uint32 tarefa)
{
	int32 local = 0;

	switch (tarefa) {
	case 0:
		local = A + B;
		break;
	case 1:
		local = (unsigned)A + (unsigned)B;
		break;
	case 2:
		local = A - B;
		break;
	case 3:
		local = (unsigned)A - (unsigned)B;
		break;
	case 4:
		local = A * B;
		break;
	case 5:
		local = (unsigned)A *(unsigned)B;
		break;
	case 6:
		local = A & B;
		break;
	case 7:
		local = A | B;
		break;
	case 8:
		local = A ^ B;
		break;
	case 9:
		local = ~(A & B);
		break;
	case 10:
		local = ~(A | B);
		break;
	case 11:
		local = ~(A ^ B);
		break;
	case 12:
		local = ~(A);
		break;
	case 13:
		local = A << B;
		break;
	case 14:
		local = A >> B;
		break;
	case 15:
		local = ASL(A, B);
		break;
	case 16:
		local = A;
		break;
	case 17:
		local = B;
		break;		//nop;
	case 18:
		local = (A == B) ? 1 : 0;
		break;
	case 19:
		local = (A != B) ? 1 : 0;
		break;
	case 20:
		local = (A < B) ? 1 : 0;
		break;
	case 21:
		local = ((unsigned)A < (unsigned)B) ? 1 : 0;
		break;
	case 22:
		local = (A <= B) ? 1 : 0;
		break;
	case 23:
		local = ((unsigned)A <= (unsigned)B) ? 1 : 0;
		break;
	case 24:
		local = (A > B) ? 1 : 0;
		break;
	case 25:
		local = ((unsigned)A > (unsigned)B) ? 1 : 0;
		break;
	case 26:
		local = (A >= B) ? 1 : 0;
		break;
	case 27:
		local = ((unsigned)A >= (unsigned)B) ? 1 : 0;
		break;
	case 28:
		local = (A == 1) ? 1 : 0;
		break;
	case 29:
		local = (A == 0) ? 1 : 0;
		break;

	}

	return (local);

}
