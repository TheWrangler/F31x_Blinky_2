/*
 * hmc704.c
 *
 *  Created on: 2020Äê4ÔÂ22ÈÕ
 *      Author: wrangler
 */


#include "c8051F310.h"

#define CS_1 (P2 |= 0x40)
#define CS_0 (P2 &= ~0x40)

#define CLK_1 (P3 |= 0x10)
#define CLK_0 (P3 &= ~0x10)

#define DAT_1 (P2 |= 0x80)
#define DAT_0 (P2 &= ~0x80)


unsigned int hmc704[8] = {0x0,0x000020,
							0x2,0x000004,
							0x3,0x0000b5,
							0x4,0x000000};


void hmc704_Reset()
{
	CS_0;
	CLK_1;
	DAT_1;
}

void hmc704_WriteReg(unsigned char addr,unsigned int reg)
{
	unsigned char i;
	unsigned long var;

	var = addr;
	var = (var << 24);
	var |= reg;

	CS_1;
	for(i=0;i<31;i++)
	{
		if((var & 0x40000000) == 0x40000000)
			DAT_1;
		else DAT_0;
		CLK_0;
		CLK_1;

		var = (var << 1);
	}
	CLK_0;
	CLK_1;
	CS_0;
}

void hmc704_Config()
{
	unsigned char i;

	for(i=0;i<4;i++)
	{
		hmc704_WriteReg(hmc704[2*i],hmc704[2*i+1]);
	}
}
