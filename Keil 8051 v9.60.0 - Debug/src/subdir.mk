################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
A51_UPPER_SRCS += \
D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/shared/si8051Base/SILABS_STARTUP.A51 

C_SRCS += \
../src/sys.c 

OBJS += \
./src/SILABS_STARTUP.OBJ \
./src/sys.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/SILABS_STARTUP.OBJ: D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/shared/si8051Base/SILABS_STARTUP.A51
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	AX51 "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/%.OBJ: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/sys.OBJ: D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/C8051F310/inc/SI_C8051F310_Register_Enums.h D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/C8051F310/inc/SI_C8051F310_Defs.h D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/shared/si8051Base/si_toolchain.h D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/shared/si8051Base/stdint.h D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.7/Device/shared/si8051Base/stdbool.h


