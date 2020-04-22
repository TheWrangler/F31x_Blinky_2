/*
 * sys.c
 *
 *  Created on: 2020Äê1ÔÂ23ÈÕ
 *      Author: wrangler
 */
#include <SI_C8051F310_Register_Enums.h>

unsigned long Sys_Clk = 24500000;

void Port_IO_Init()
{
    // P0.0  -  Skipped,     Open-Drain, Digital
    // P0.1  -  Skipped,     Open-Drain, Digital
    // P0.2  -  Skipped,     Open-Drain, Digital
    // P0.3  -  Skipped,     Open-Drain, Digital
    // P0.4  -  TX0 (UART0), Open-Drain, Digital
    // P0.5  -  RX0 (UART0), Open-Drain, Digital
    // P0.6  -  Skipped,     Open-Drain, Digital
    // P0.7  -  Skipped,     Open-Drain, Digital

    // P1.0  -  Skipped,     Open-Drain, Digital
    // P1.1  -  Skipped,     Open-Drain, Digital
    // P1.2  -  Skipped,     Open-Drain, Digital
    // P1.3  -  Skipped,     Open-Drain, Digital
    // P1.4  -  Skipped,     Open-Drain, Digital
    // P1.5  -  Skipped,     Open-Drain, Digital
    // P1.6  -  Skipped,     Open-Drain, Digital
    // P1.7  -  Skipped,     Open-Drain, Digital
    // P2.0  -  SCK  (SPI0), Open-Drain, Digital
    // P2.1  -  MISO (SPI0), Open-Drain, Digital
    // P2.2  -  MOSI (SPI0), Open-Drain, Digital
    // P2.3  -  NSS  (SPI0), Open-Drain, Digital

//	P0MDOUT  |= 0x10;      // Enable UTX as push-pull output
//	P2MDOUT  |= 0x0d;      //Enable SCK\MOSI\NSS as push-pull output
//    P3MDIN    = 0xFB;
//    P0SKIP    = 0xCF;
//    P1SKIP    = 0xFF;
//    XBR0      = 0x03;
//    XBR1      = 0x40;

	P0MDOUT   = 0x18;
	P1MDOUT   = 0x02;
	P2MDOUT   = 0xC0;
	P3MDOUT   = 0x10;
	XBR1      = 0x40;
}

void Oscillator_Init()
{
	//internal osc enable,SYSCLK derived from internal osc divided by 1
    OSCICN    = 0x83;
}

void Interrupts_Init()
{
    IP        = 0x10;
    IE        = 0x50;
}

void Init_Device(void)
{
	IE &= ~0x80;

	Port_IO_Init();
    Oscillator_Init();
//    Timer_Init();
//    UART_Init();
//    SPI_Init();
//    ADC_Init();

//    Interrupts_Init();
//
//    IE |= 0x80;
}

