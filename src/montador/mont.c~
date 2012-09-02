#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define N_INST 30

main()
{

	char instrucoes[N_INST][6] = { "JMP", "ADD", "ADDU", "SUB", "SUBU",
		"MUL", "MULU", "AND", "OR", "XOR", "NOT", "LSL",
		"ASR", "SEQ", "SNE", "SLT", "SLTU", "SLE", "SLEU",
		"SGT", "SGTU", "SGE", "SGEU", "LDW", "STW", "JMPL",
		"RET", "CALL", "LUI", "LSR"
	};

	char inst[10], dest[10], op1[10], op2[10];
	int i, rd, rs1, rs2, out;

	while (scanf("%s %s %s %s", inst, op1, op2, dest) != EOF) {
		printf("%s %s %s %s\n", inst, op1, op2, dest);
		for (i = 0; i < N_INST; i++)
			if (!strcasecmp(instrucoes[i], inst)) {
				if (*dest == 'r')
					rd = atoi(&dest[1]);
				else
					rd = atoi(dest);
				if (*op1 == 'r')
					rs1 = atoi(&op1[1]);
				else
					rs1 = atoi(op1);
				if (*op2 == 'r')
					rs2 = atoi(&op2[1]);
				else
					rs2 = atoi(op2);

				if (i > 0 && i < 27) {
					rs1 = rs1 << 21;
					rs2 = rs2 << 16;
					rd = rd << 11;
				} else {
					rs1 = rs1 << 16;
				}

				switch (i) {
				 /*JMP*/ case 0:
					out = 0x7C000000 | rd;
					break;
				case 1:
					 /*ADD*/ out =
					    0x04000000 | rs1 | rs2 | rd;
					break;
				case 2:
					out = 0x04000040 | rs1 | rs2 | rd;
					break;	// ADDU
				case 3:
					out = 0x04000080 | rs1 | rs2 | rd;
					break;	// SUB
				case 4:
					out = 0x040000C0 | rs1 | rs2 | rd;
					break;	// SUBU
				case 5:
					out = 0x04000100 | rs1 | rs2 | rd;
					break;	// MUL
				case 6:
					out = 0x04000140 | rs1 | rs2 | rd;
					break;	// MULU
				case 7:
					out = 0x08000000 | rs1 | rs2 | rd;
					break;	// AND
				case 8:
					out = 0x08000040 | rs1 | rs2 | rd;
					break;	// OR
				case 9:
					out = 0x08000080 | rs1 | rs2 | rd;
					break;	// XOR
				case 10:
					out = 0x080000C0 | rs1 | rs2 | rd;
					break;	// NOT
				case 11:
					out = 0x08000100 | rs1 | rs2 | rd;
					break;	// LSL
				case 12:
					out = 0x08000140 | rs1 | rs2 | rd;
					break;	// LSR
				case 13:
					out = 0x08000180 | rs1 | rs2 | rd;
					break;	// ASR
				case 14:
					out = 0x0C000000 | rs1 | rs2 | rd;
					break;	// SEQ
				case 15:
					out = 0x0C000040 | rs1 | rs2 | rd;
					break;	// SNE
				case 16:
					out = 0x0C000080 | rs1 | rs2 | rd;
					break;	// SLT
				case 17:
					out = 0x0C0000C0 | rs1 | rs2 | rd;
					break;	// SLTU
				case 18:
					out = 0x0C000100 | rs1 | rs2 | rd;
					break;	// SLE
				case 19:
					out = 0x0C000140 | rs1 | rs2 | rd;
					break;	// SLEU
				case 20:
					out = 0x0C000180 | rs1 | rs2 | rd;
					break;	// SGT
				case 21:
					out = 0x0C0001C0 | rs1 | rs2 | rd;
					break;	// SGTU
				case 22:
					out = 0x0C000400 | rs1 | rs2 | rd;
					break;	// SGE
				case 23:
					out = 0x0C000440 | rs1 | rs2 | rd;
					break;	// SGEU
				case 24:
					out = 0x14000000 | rs1 | rs2 | rd;
					break;	// LDW
				case 25:
					out = 0x14000100 | rs1 | rs2 | rd;
					break;	// STW
				case 29:
					out = 0x74000000 | rs1 | rs2;
					break;	// LUI
				default:
					out = 0;
				}
				printf("%x\n", out);
			}
	}
}
