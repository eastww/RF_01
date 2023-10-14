################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Code/rf_01/src/Radio/src/cmt2300.c \
D:/Code/rf_01/src/Radio/src/cmt2300_hal.c \
D:/Code/rf_01/src/Radio/src/cmt_spi3.c \
D:/Code/rf_01/src/Radio/src/crc.c \
D:/Code/rf_01/src/Radio/src/radio.c 

OBJS += \
./Bsp/Radio/src/cmt2300.o \
./Bsp/Radio/src/cmt2300_hal.o \
./Bsp/Radio/src/cmt_spi3.o \
./Bsp/Radio/src/crc.o \
./Bsp/Radio/src/radio.o 

C_DEPS += \
./Bsp/Radio/src/cmt2300.d \
./Bsp/Radio/src/cmt2300_hal.d \
./Bsp/Radio/src/cmt_spi3.d \
./Bsp/Radio/src/crc.d \
./Bsp/Radio/src/radio.d 


# Each subdirectory must supply rules for building sources it contributes
Bsp/Radio/src/cmt2300.o: D:/Code/rf_01/src/Radio/src/cmt2300.c Bsp/Radio/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 '-DAPP_VERSION=1.0.0' -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Code/rf_01/src/CubeIDE/Bsp" -I"D:/Code/rf_01/src/Radio/inc" -I"D:/Code/rf_01/src/CubeIDE/Service/kfifo" -I"D:/Code/rf_01/src/CubeIDE/Bsp/Test" -I"D:/Code/rf_01/src/CubeIDE/Application" -I"D:/Code/rf_01/src/CubeIDE/Application/State" -I"D:/Code/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/Code/rf_01/src/CubeIDE/Service/stateMachine" -I"D:/Code/rf_01/src/CubeIDE/Bsp/config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Bsp/Radio/src/cmt2300_hal.o: D:/Code/rf_01/src/Radio/src/cmt2300_hal.c Bsp/Radio/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 '-DAPP_VERSION=1.0.0' -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Code/rf_01/src/CubeIDE/Bsp" -I"D:/Code/rf_01/src/Radio/inc" -I"D:/Code/rf_01/src/CubeIDE/Service/kfifo" -I"D:/Code/rf_01/src/CubeIDE/Bsp/Test" -I"D:/Code/rf_01/src/CubeIDE/Application" -I"D:/Code/rf_01/src/CubeIDE/Application/State" -I"D:/Code/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/Code/rf_01/src/CubeIDE/Service/stateMachine" -I"D:/Code/rf_01/src/CubeIDE/Bsp/config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Bsp/Radio/src/cmt_spi3.o: D:/Code/rf_01/src/Radio/src/cmt_spi3.c Bsp/Radio/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 '-DAPP_VERSION=1.0.0' -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Code/rf_01/src/CubeIDE/Bsp" -I"D:/Code/rf_01/src/Radio/inc" -I"D:/Code/rf_01/src/CubeIDE/Service/kfifo" -I"D:/Code/rf_01/src/CubeIDE/Bsp/Test" -I"D:/Code/rf_01/src/CubeIDE/Application" -I"D:/Code/rf_01/src/CubeIDE/Application/State" -I"D:/Code/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/Code/rf_01/src/CubeIDE/Service/stateMachine" -I"D:/Code/rf_01/src/CubeIDE/Bsp/config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Bsp/Radio/src/crc.o: D:/Code/rf_01/src/Radio/src/crc.c Bsp/Radio/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 '-DAPP_VERSION=1.0.0' -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Code/rf_01/src/CubeIDE/Bsp" -I"D:/Code/rf_01/src/Radio/inc" -I"D:/Code/rf_01/src/CubeIDE/Service/kfifo" -I"D:/Code/rf_01/src/CubeIDE/Bsp/Test" -I"D:/Code/rf_01/src/CubeIDE/Application" -I"D:/Code/rf_01/src/CubeIDE/Application/State" -I"D:/Code/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/Code/rf_01/src/CubeIDE/Service/stateMachine" -I"D:/Code/rf_01/src/CubeIDE/Bsp/config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Bsp/Radio/src/radio.o: D:/Code/rf_01/src/Radio/src/radio.c Bsp/Radio/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 '-DAPP_VERSION=1.0.0' -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Code/rf_01/src/CubeIDE/Bsp" -I"D:/Code/rf_01/src/Radio/inc" -I"D:/Code/rf_01/src/CubeIDE/Service/kfifo" -I"D:/Code/rf_01/src/CubeIDE/Bsp/Test" -I"D:/Code/rf_01/src/CubeIDE/Application" -I"D:/Code/rf_01/src/CubeIDE/Application/State" -I"D:/Code/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/Code/rf_01/src/CubeIDE/Service/stateMachine" -I"D:/Code/rf_01/src/CubeIDE/Bsp/config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsp-2f-Radio-2f-src

clean-Bsp-2f-Radio-2f-src:
	-$(RM) ./Bsp/Radio/src/cmt2300.cyclo ./Bsp/Radio/src/cmt2300.d ./Bsp/Radio/src/cmt2300.o ./Bsp/Radio/src/cmt2300.su ./Bsp/Radio/src/cmt2300_hal.cyclo ./Bsp/Radio/src/cmt2300_hal.d ./Bsp/Radio/src/cmt2300_hal.o ./Bsp/Radio/src/cmt2300_hal.su ./Bsp/Radio/src/cmt_spi3.cyclo ./Bsp/Radio/src/cmt_spi3.d ./Bsp/Radio/src/cmt_spi3.o ./Bsp/Radio/src/cmt_spi3.su ./Bsp/Radio/src/crc.cyclo ./Bsp/Radio/src/crc.d ./Bsp/Radio/src/crc.o ./Bsp/Radio/src/crc.su ./Bsp/Radio/src/radio.cyclo ./Bsp/Radio/src/radio.d ./Bsp/Radio/src/radio.o ./Bsp/Radio/src/radio.su

.PHONY: clean-Bsp-2f-Radio-2f-src

