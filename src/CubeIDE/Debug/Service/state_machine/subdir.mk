################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Service/state_machine/state_Machine.c 

OBJS += \
./Service/state_machine/state_Machine.o 

C_DEPS += \
./Service/state_machine/state_Machine.d 


# Each subdirectory must supply rules for building sources it contributes
Service/state_machine/%.o Service/state_machine/%.su: ../Service/state_machine/%.c Service/state_machine/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/work/rf_01/src/CubeIDE/Bsp" -I"D:/work/rf_01/src/Radio/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Service-2f-state_machine

clean-Service-2f-state_machine:
	-$(RM) ./Service/state_machine/state_Machine.d ./Service/state_machine/state_Machine.o ./Service/state_machine/state_Machine.su

.PHONY: clean-Service-2f-state_machine

