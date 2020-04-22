################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../F31x_Blinky.c \
../hmc704.c \
../lmx2592.c 

OBJS += \
./F31x_Blinky.OBJ \
./hmc704.OBJ \
./lmx2592.OBJ 


# Each subdirectory must supply rules for building sources it contributes
%.OBJ: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

F31x_Blinky.OBJ: D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/C8051F310/inc/SI_C8051F310_Register_Enums.h C:/Users/wrangler/SimplicityStudio/v4_workspace/F31x_Blinky_2/src/sys.h D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/C8051F310/inc/SI_C8051F310_Defs.h D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/shared/si8051Base/si_toolchain.h D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/shared/si8051Base/stdint.h D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/shared/si8051Base/stdbool.h

hmc704.OBJ: D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/C8051F310/inc/c8051F310.h

lmx2592.OBJ: D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/C8051F310/inc/c8051F310.h


