
#include "defines.h"
#include "cpu.h"
#include "memoria.h"
#define classMask 0x78000000
#define src1RegMask 0x3E00000
#define src2RegMask 0x1F0000
#define targetRegMask 0xF800
#define opMask 0x3C0
#define imediatoMask1 0xFFFF
#define imediatoMask2 0x3FFFFFFF
uint32 wData;

CONTROLE_DE *dec2exec;

void decodifica(uint32 data, CONTROLE_DE * regControle)
{
	dec2exec = regControle;
	wData = data;
	uint32 mask = 0xFC000000;
	uint32 formato = data & mask;
	switch (formato) {
	case 0x00000000:
		decodificaFormato1();
		break;
	case 0x40000000:
		decodificaFormato2();
		break;
	case 0x80000000:
		decodificaFormato3();
		break;
	case 0xC0000000:
		decodificaFormato4();
		break;
	}
}

void decodificaFormato1()
{
	uint32 class = wData & classMask;
	uint32 src1Reg = wData & src1RegMask;
	uint32 src2Reg = wData & src2RegMask;
	uint32 targetReg = wData & targetRegMask;
	uint32 opcode = wData & opMask;

	class = class >> 26;
	src1Reg = src1Reg >> 21;
	src2Reg = src2Reg >> 16;
	targetReg = targetReg >> 11;
	opcode = opcode >> 6;

	dec2exec->src1Reg = src1Reg;
	dec2exec->src2Reg = src2Reg;
	dec2exec->targetReg = targetReg;
	dec2exec->opcode = opcode;
}

void decodificaFormato2()
{
	uint32 opcode = wData & classMask;
	uint32 src1Reg = wData & src1RegMask;
	uint32 targetReg = wData & src2RegMask;
	uint32 imediato = wData & imediatoMask1;

	opcode = opcode >> 26;
	src1Reg = src1Reg >> 21;
	targetReg = targetReg >> 16;

	//dec2exec <- valores !TODO
}

void decodificaFormato3()
{
	decodificaFormato2();
	//modifica valores !TODO
}

void decodificaFormato4()
{
	uint32 imediato = wData & imediato;
}
