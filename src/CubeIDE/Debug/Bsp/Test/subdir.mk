################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsp/Test/bsp_test.c 

OBJS += \
./Bsp/Test/bsp_test.o 

C_DEPS += \
./Bsp/Test/bsp_test.d 


# Each subdirectory must supply rules for building sources it contributes
Bsp/Test/%.o Bsp/Test/%.su: ../Bsp/Test/%.c Bsp/Test/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 '-DAPP_VERSION=1.0.0' -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/work/rf_01/src/CubeIDE/Bsp" -I"D:/work/rf_01/src/Radio/inc" -I"D:/work/rf_01/src/CubeIDE/Service/kfifo" -I"D:/work/rf_01/src/CubeIDE/Bsp/Test" -I"D:/work/rf_01/src/CubeIDE/Application" -I"D:/work/rf_01/src/CubeIDE/Application/State" -I"D:/work/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/work/rf_01/src/CubeIDE/Service/stateMachine" -I"D:/work/rf_01/src/CubeIDE/Bsp/config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsp-2f-Test

clean-Bsp-2f-Test:
	-$(RM) ./Bsp/Test/bsp_test.d ./Bsp/Test/bsp_test.o ./Bsp/Test/bsp_test.su

.PHONY: clean-Bsp-2f-Test

