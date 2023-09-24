################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Service/kfifo/kfifo.c 

OBJS += \
./Service/kfifo/kfifo.o 

C_DEPS += \
./Service/kfifo/kfifo.d 


# Each subdirectory must supply rules for building sources it contributes
Service/kfifo/%.o Service/kfifo/%.su: ../Service/kfifo/%.c Service/kfifo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/work/rf_01/src/CubeIDE/Bsp" -I"D:/work/rf_01/src/Radio/inc" -I"D:/work/rf_01/src/CubeIDE/Service/kfifo" -I"D:/work/rf_01/src/CubeIDE/Bsp/Test" -I"D:/work/rf_01/src/CubeIDE/Application" -I"D:/work/rf_01/src/CubeIDE/Application/State" -I"D:/work/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/work/rf_01/src/CubeIDE/Service/stateMachine" -I"D:/work/rf_01/src/CubeIDE/Bsp/config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Service-2f-kfifo

clean-Service-2f-kfifo:
	-$(RM) ./Service/kfifo/kfifo.d ./Service/kfifo/kfifo.o ./Service/kfifo/kfifo.su

.PHONY: clean-Service-2f-kfifo

