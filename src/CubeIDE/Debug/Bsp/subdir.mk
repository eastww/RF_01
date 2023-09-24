################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsp/bsp.c \
D:/work/rf_01/src/delay.c \
D:/work/rf_01/src/gpio.c \
../Bsp/timer.c \
../Bsp/uart.c 

OBJS += \
./Bsp/bsp.o \
./Bsp/delay.o \
./Bsp/gpio.o \
./Bsp/timer.o \
./Bsp/uart.o 

C_DEPS += \
./Bsp/bsp.d \
./Bsp/delay.d \
./Bsp/gpio.d \
./Bsp/timer.d \
./Bsp/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Bsp/%.o Bsp/%.su: ../Bsp/%.c Bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/work/rf_01/src/CubeIDE/Bsp" -I"D:/work/rf_01/src/Radio/inc" -I"D:/work/rf_01/src/CubeIDE/Service/kfifo" -I"D:/work/rf_01/src/CubeIDE/Bsp/Test" -I"D:/work/rf_01/src/CubeIDE/Application" -I"D:/work/rf_01/src/CubeIDE/Application/State" -I"D:/work/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/work/rf_01/src/CubeIDE/Service/stateMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Bsp/delay.o: D:/work/rf_01/src/delay.c Bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/work/rf_01/src/CubeIDE/Bsp" -I"D:/work/rf_01/src/Radio/inc" -I"D:/work/rf_01/src/CubeIDE/Service/kfifo" -I"D:/work/rf_01/src/CubeIDE/Bsp/Test" -I"D:/work/rf_01/src/CubeIDE/Application" -I"D:/work/rf_01/src/CubeIDE/Application/State" -I"D:/work/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/work/rf_01/src/CubeIDE/Service/stateMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Bsp/gpio.o: D:/work/rf_01/src/gpio.c Bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/work/rf_01/src/CubeIDE/Bsp" -I"D:/work/rf_01/src/Radio/inc" -I"D:/work/rf_01/src/CubeIDE/Service/kfifo" -I"D:/work/rf_01/src/CubeIDE/Bsp/Test" -I"D:/work/rf_01/src/CubeIDE/Application" -I"D:/work/rf_01/src/CubeIDE/Application/State" -I"D:/work/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/work/rf_01/src/CubeIDE/Service/stateMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsp

clean-Bsp:
	-$(RM) ./Bsp/bsp.d ./Bsp/bsp.o ./Bsp/bsp.su ./Bsp/delay.d ./Bsp/delay.o ./Bsp/delay.su ./Bsp/gpio.d ./Bsp/gpio.o ./Bsp/gpio.su ./Bsp/timer.d ./Bsp/timer.o ./Bsp/timer.su ./Bsp/uart.d ./Bsp/uart.o ./Bsp/uart.su

.PHONY: clean-Bsp

