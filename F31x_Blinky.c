
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_C8051F310_Register_Enums.h>
#include "./src/sys.h"

//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup (void)
{
   PCA0MD &= ~0x40;                       // WDTE = 0 (clear watchdog timer
}

void Delay()
{
	unsigned int i=0;
	while(i<60000)
		i++;
}

//-----------------------------------------------------------------------------
// MAIN Routine
//-----------------------------------------------------------------------------
void main (void)
{
	Init_Device();

	Delay();

	hmc704_Reset();
	lmx2592_Reset();

	hmc704_Config();

	while(1)
	{
		lmx2592_Config();
	}
}
