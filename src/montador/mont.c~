#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define N_INST 63

main()
{
	char instrucoes[N_INST][6] =
	    { "ADD", "ADDU", "SUB", "SUBU", "MUL", "MULU", "AND", "OR", "XOR",
		"NAND", "NOR", "NXOR", "NOT", "LSL", "LSR", "ASR", "SEQ", "SNE",
		"SLT", "SLTU", "SLE",
		"SLEU", "SQT", "SGTU", "SGE", "SGEU", "LDB", "LDS", "LDW",
		"STB", "STS", "STW", "JMPL",
		"RET", "Noop", "ADDI", "ADDUI", "SUBI", "SUBUI", "ANDI", "ORI",
		"XORI", "NANDI", "NORI", "XNORI",
		"LSLI", "LSRI", "ASRI", "LUI", "JMP", "BEQ", "BNE", "BLT",
		"BLTU", "BLE", "BLEU", "BGT", "BGTU",
		"BGE", "BGEU", "BRT", "BRF", "CALL"
	};

	char inst[10], dest[10], op1[10], op2[10];
	unsigned short int uRd;
	unsigned int aux;
	int out, rs1, rs2, i, rd;

	while (scanf("%s %s %s %s", inst, op1, op2, dest) != EOF) {
		//printf("%s %s %s %s\n", inst, op1, op2, dest);

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

				if (i >= 0 && i < 35) {	//Formato 1
					rs1 = rs1 << 21;
					rs2 = rs2 << 16;
					rd = rd << 11;
				} else if (i < 62) {	//Formato 2 e 3
					rs1 = rs1 << 21;
					rs2 = rs2 << 16;
					uRd = atoi(dest);
				} else {	// formato 4
					rd = atoi(dest);
					//aux = (unsigned int) rd;
				}

				if (i >= 0) {
					if (i <= 5)
						out = 0x00000000
						    | rs1 | rs2 | rd | (i << 6);
					else if (i <= 15)
						out = 0x04000000
						    | rs1 | rs2 | rd | ((i - 6)
									<< 6);
					else if (i <= 25)
						out = 0x08000000
						    | rs1 | rs2 | rd | ((i - 16)
									<< 6);
					else if (i <= 31)
						out = 0x0C000000
						    | rs1 | rs2 | rd | ((i - 26)
									<< 6);
					else if (i == 32)
						out = 0x10000000
						    | rs1 | rs2 | rd;
					else if (i == 33)
						out = 0x14000000;
					else if (i == 34)
						out = 0x18000000;
					else if (i <= 49)
						out = 0x40000000
						    | rs1 | rs2 | uRd |
						    ((i - 35)
						     << 26);
					else if (i <= 61)
						out = 0x80000000
						    | rs1 | rs2 | uRd |
						    ((i - 50)
						     << 26);
					else if (i == 62)
						out = 0xC0000000 | rd;
				}
				printf("%x\n", out);
			}
	}
	printf("\n");
}
