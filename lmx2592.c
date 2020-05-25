/*
 * lmx2592.c
 *
 *  Created on: 2020Äê4ÔÂ22ÈÕ
 *      Author: wrangler
 */
#include "c8051F310.h"

#define CS_1 (P1 |= 0x02)
#define CS_0 (P1 &= ~0x02)

#define CLK_1 (P0 |= 0x08)
#define CLK_0 (P0 &= ~0x08)

#define DAT_1 (P0 |= 0x10)
#define DAT_0 (P0 &= ~0x10)

#define FREQ (P0 & 0x04)


//unsigned int lmx2592[34] = {0,0x2206,
//								9,0x0302,
//								10,0x10d8,//0x12d8,
//								12,0x7001,
//								11,0x0018,//0x0058,
//								30,0x0035,
//								38,0x0062,//freq=0
//								44,0x0000,
//								45,0x0000,//freq=0
//								40,0x0000,
//								41,0x2710,
//								34,0xc3ca,
//								31,0x0481,
//								36,0x0000,
//								46,0x3fa3,
//								47,0x08c0,
//								0,0x220c};

unsigned int lmx2592[34] = {0,0x2206,
								9,0x0b02,
								10,0x10d8,
								12,0x7001,
								11,0x0018,
								30,0x0035,
								38,0x0030,//freq=0
								44,0x0000,
								45,0xc350,//freq=0
								40,0x0001,
								41,0x86a0,
								34,0xc3ca,
								31,0x0481,
								36,0x0000,
								46,0x3fa3,
								47,0x08c0,
								0,0x220c};

//unsigned short lmx2592[64] = {0x40,0x0077,0x3f,0x00a8,0x0000,0x0001,0x0000,0x03fc,0x08cf,0x1fa3,
//								0x0000,0x0000,0x0000,0x0000,0x2710,0x0000,0x8204,0x0062,
//								0x5000,0x0000,0x001d,0xc3ca,0x2a0a,0x210a,0x0481,0x0035,
//								0x0084,0x2924,0x0000,0x0509,0x8842,0x2300,      ,0x012c,
//								0x0965,0x0ffc,0x4000,0x7001,0x0058,0x12d8,0x0302,0x1084,
//								0x28b2,      ,        ,0x1943,0x0500,0x0808,0x220c}


//unsigned short lmx2592_2[32] = {0,0x2306,
//									9,0x0302,
//									10,0x12d8,
//									12,0x7001,
//									11,0x0058,
//                                    30,0x0035,
//									38,0x001c,//freq=1
//									44,0x0000,
//									45,0x0c35,//freq=1
//									40,0x0000,
//									41,0x4e20,
//									34,0xc3ca,
//									31,0x0481,
//									36,0x0000,
//									47,0x08c0,
//									0,0x230e};

unsigned char freq = 0xff;

void lmx2592_Reset()
{
	CS_1;
	CLK_1;
	DAT_1;
}

void lmx2592_WriteReg(unsigned char addr,unsigned int reg)
{
	unsigned char i;
	unsigned long var;

	var = addr;
	var = (var << 16);
	var |= reg;

	CS_0;
	for(i=0;i<24;i++)
	{
		if((var & 0x800000) == 0x800000)
			DAT_1;
		else DAT_0;
		CLK_0;
		CLK_1;

		var = (var << 1);
	}
	CS_1;
}

void lmx2592_Config()
{
	unsigned char i;

	if(freq == FREQ)
		return;

	freq = FREQ;

	if(freq == 0)
	{
		lmx2592[13] = 0x0030;
		lmx2592[17] = 0xc350;
//		lmx2592[13] = 0x0026;//R38
//		lmx2592[15] = 0x0009;//R44
//		lmx2592[17] = 0x27C0;//R45
	}
	else
	{
		lmx2592[13] = 0x0038;
		lmx2592[17] = 0x3d09;

//		lmx2592[13] = 0x002C;//R38
//		lmx2592[15] = 0x0008;//R44
//		lmx2592[17] = 0x02C8;//R45
	}

	for(i=0;i<17;i++)
	{
		lmx2592_WriteReg(lmx2592[2*i],lmx2592[2*i+1]);
	}

	/*
	lmx2592_WriteReg(0x40,0x0077);
	lmx2592_WriteReg(0x3f,0x00a8);
	lmx2592_WriteReg(0x3e,0x0000);
	lmx2592_WriteReg(0x3d,0x0001);
	lmx2592_WriteReg(0x3b,0x0000);
	lmx2592_WriteReg(0x30,0x03fc);
	lmx2592_WriteReg(0x2f,0x08cf);
	lmx2592_WriteReg(0x2e,0x1fa3);
	lmx2592_WriteReg(0x2d,0x0000);
	lmx2592_WriteReg(0x2c,0x0000);
	lmx2592_WriteReg(0x2b,0x0000);
	lmx2592_WriteReg(0x2a,0x0000);
	lmx2592_WriteReg(0x29,0x2710);
	lmx2592_WriteReg(0x28,0x0000);
	lmx2592_WriteReg(0x27,0x8204);
	lmx2592_WriteReg(0x26,0x0062);
	lmx2592_WriteReg(0x25,0x5000);
	lmx2592_WriteReg(0x24,0x0000);
	lmx2592_WriteReg(0x23,0x001d);
	lmx2592_WriteReg(0x22,0xc3ca);
	lmx2592_WriteReg(0x21,0x2a0a);
	lmx2592_WriteReg(0x20,0x210a);
	lmx2592_WriteReg(0x1f,0x0481);
	lmx2592_WriteReg(0x1e,0x0035);
	lmx2592_WriteReg(0x1d,0x0084);
	lmx2592_WriteReg(0x1c,0x2924);
	lmx2592_WriteReg(0x19,0x0000);
	lmx2592_WriteReg(0x18,0x0509);
	lmx2592_WriteReg(0x17,0x8842);
	lmx2592_WriteReg(0x16,0x2300);
	lmx2592_WriteReg(0x14,0x012c);
	lmx2592_WriteReg(0x13,0x0965);
	lmx2592_WriteReg(0x0e,0x0ffc);
	lmx2592_WriteReg(0x0d,0x4000);
	lmx2592_WriteReg(0x0c,0x7001);
	lmx2592_WriteReg(0x0b,0x0058);
	lmx2592_WriteReg(0x0a,0x12d8);
	lmx2592_WriteReg(0x09,0x0302);
	lmx2592_WriteReg(0x08,0x1084);
	lmx2592_WriteReg(0x07,0x28b2);
	lmx2592_WriteReg(0x04,0x1943);
	lmx2592_WriteReg(0x02,0x0500);
	lmx2592_WriteReg(0x01,0x0808);
	lmx2592_WriteReg(0x00,0x220c);*/
}


