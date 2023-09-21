################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Service/stateMachine/stateMachine.c 

OBJS += \
./Service/stateMachine/stateMachine.o 

C_DEPS += \
./Service/stateMachine/stateMachine.d 


# Each subdirectory must supply rules for building sources it contributes
Service/stateMachine/%.o Service/stateMachine/%.su: ../Service/stateMachine/%.c Service/stateMachine/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=1 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/work/rf_01/src/CubeIDE/Bsp" -I"D:/work/rf_01/src/Radio/inc" -I"D:/work/rf_01/src/CubeIDE/Service/kfifo" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Service-2f-stateMachine

clean-Service-2f-stateMachine:
	-$(RM) ./Service/stateMachine/stateMachine.d ./Service/stateMachine/stateMachine.o ./Service/stateMachine/stateMachine.su

.PHONY: clean-Service-2f-stateMachine

