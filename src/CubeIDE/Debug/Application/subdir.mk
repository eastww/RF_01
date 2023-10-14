################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/global.c \
../Application/stateActuator.c 

OBJS += \
./Application/global.o \
./Application/stateActuator.o 

C_DEPS += \
./Application/global.d \
./Application/stateActuator.d 


# Each subdirectory must supply rules for building sources it contributes
Application/%.o Application/%.su Application/%.cyclo: ../Application/%.c Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 '-DAPP_VERSION=1.0.0' -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Code/rf_01/src/CubeIDE/Bsp" -I"D:/Code/rf_01/src/Radio/inc" -I"D:/Code/rf_01/src/CubeIDE/Service/kfifo" -I"D:/Code/rf_01/src/CubeIDE/Bsp/Test" -I"D:/Code/rf_01/src/CubeIDE/Application" -I"D:/Code/rf_01/src/CubeIDE/Application/State" -I"D:/Code/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/Code/rf_01/src/CubeIDE/Service/stateMachine" -I"D:/Code/rf_01/src/CubeIDE/Bsp/config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application

clean-Application:
	-$(RM) ./Application/global.cyclo ./Application/global.d ./Application/global.o ./Application/global.su ./Application/stateActuator.cyclo ./Application/stateActuator.d ./Application/stateActuator.o ./Application/stateActuator.su

.PHONY: clean-Application

