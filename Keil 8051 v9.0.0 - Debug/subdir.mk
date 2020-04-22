################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../F31x_Blinky.c \
../cmd.c \
../sta.c 

OBJS += \
./F31x_Blinky.OBJ \
./cmd.OBJ \
./sta.OBJ 


# Each subdirectory must supply rules for building sources it contributes
%.OBJ: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

F31x_Blinky.OBJ: D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/C8051F310/inc/SI_C8051F310_Register_Enums.h F:/simplicity_studo_workspace/F31x_Blinky/src/timer.h F:/simplicity_studo_workspace/F31x_Blinky/src/uart.h F:/simplicity_studo_workspace/F31x_Blinky/src/adc.h F:/simplicity_studo_workspace/F31x_Blinky/src/sys.h F:/simplicity_studo_workspace/F31x_Blinky/sta.h D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/C8051F310/inc/SI_C8051F310_Defs.h D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/shared/si8051Base/si_toolchain.h D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/shared/si8051Base/stdint.h D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/shared/si8051Base/stdbool.h

cmd.OBJ: F:/simplicity_studo_workspace/F31x_Blinky/cmd.h

sta.OBJ: F:/simplicity_studo_workspace/F31x_Blinky/sta.h


