################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsp/bsp.c \
D:/Code/rf_01/src/delay.c \
../Bsp/dial_switch.c \
D:/Code/rf_01/src/gpio.c \
../Bsp/timer.c \
../Bsp/uart.c 

OBJS += \
./Bsp/bsp.o \
./Bsp/delay.o \
./Bsp/dial_switch.o \
./Bsp/gpio.o \
./Bsp/timer.o \
./Bsp/uart.o 

C_DEPS += \
./Bsp/bsp.d \
./Bsp/delay.d \
./Bsp/dial_switch.d \
./Bsp/gpio.d \
./Bsp/timer.d \
./Bsp/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Bsp/%.o Bsp/%.su Bsp/%.cyclo: ../Bsp/%.c Bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 '-DAPP_VERSION=1.0.0' -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Code/rf_01/src/CubeIDE/Bsp" -I"D:/Code/rf_01/src/Radio/inc" -I"D:/Code/rf_01/src/CubeIDE/Service/kfifo" -I"D:/Code/rf_01/src/CubeIDE/Bsp/Test" -I"D:/Code/rf_01/src/CubeIDE/Application" -I"D:/Code/rf_01/src/CubeIDE/Application/State" -I"D:/Code/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/Code/rf_01/src/CubeIDE/Service/stateMachine" -I"D:/Code/rf_01/src/CubeIDE/Bsp/config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Bsp/delay.o: D:/Code/rf_01/src/delay.c Bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 '-DAPP_VERSION=1.0.0' -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Code/rf_01/src/CubeIDE/Bsp" -I"D:/Code/rf_01/src/Radio/inc" -I"D:/Code/rf_01/src/CubeIDE/Service/kfifo" -I"D:/Code/rf_01/src/CubeIDE/Bsp/Test" -I"D:/Code/rf_01/src/CubeIDE/Application" -I"D:/Code/rf_01/src/CubeIDE/Application/State" -I"D:/Code/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/Code/rf_01/src/CubeIDE/Service/stateMachine" -I"D:/Code/rf_01/src/CubeIDE/Bsp/config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Bsp/gpio.o: D:/Code/rf_01/src/gpio.c Bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 '-DAPP_VERSION=1.0.0' -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Code/rf_01/src/CubeIDE/Bsp" -I"D:/Code/rf_01/src/Radio/inc" -I"D:/Code/rf_01/src/CubeIDE/Service/kfifo" -I"D:/Code/rf_01/src/CubeIDE/Bsp/Test" -I"D:/Code/rf_01/src/CubeIDE/Application" -I"D:/Code/rf_01/src/CubeIDE/Application/State" -I"D:/Code/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/Code/rf_01/src/CubeIDE/Service/stateMachine" -I"D:/Code/rf_01/src/CubeIDE/Bsp/config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsp

clean-Bsp:
	-$(RM) ./Bsp/bsp.cyclo ./Bsp/bsp.d ./Bsp/bsp.o ./Bsp/bsp.su ./Bsp/delay.cyclo ./Bsp/delay.d ./Bsp/delay.o ./Bsp/delay.su ./Bsp/dial_switch.cyclo ./Bsp/dial_switch.d ./Bsp/dial_switch.o ./Bsp/dial_switch.su ./Bsp/gpio.cyclo ./Bsp/gpio.d ./Bsp/gpio.o ./Bsp/gpio.su ./Bsp/timer.cyclo ./Bsp/timer.d ./Bsp/timer.o ./Bsp/timer.su ./Bsp/uart.cyclo ./Bsp/uart.d ./Bsp/uart.o ./Bsp/uart.su

.PHONY: clean-Bsp

