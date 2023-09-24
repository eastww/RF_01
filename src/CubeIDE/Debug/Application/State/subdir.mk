################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/State/errorState.c \
../Application/State/rfRecvState.c \
../Application/State/rfSendState.c 

OBJS += \
./Application/State/errorState.o \
./Application/State/rfRecvState.o \
./Application/State/rfSendState.o 

C_DEPS += \
./Application/State/errorState.d \
./Application/State/rfRecvState.d \
./Application/State/rfSendState.d 


# Each subdirectory must supply rules for building sources it contributes
Application/State/%.o Application/State/%.su: ../Application/State/%.c Application/State/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/work/rf_01/src/CubeIDE/Bsp" -I"D:/work/rf_01/src/Radio/inc" -I"D:/work/rf_01/src/CubeIDE/Service/kfifo" -I"D:/work/rf_01/src/CubeIDE/Bsp/Test" -I"D:/work/rf_01/src/CubeIDE/Application" -I"D:/work/rf_01/src/CubeIDE/Application/State" -I"D:/work/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/work/rf_01/src/CubeIDE/Service/stateMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-State

clean-Application-2f-State:
	-$(RM) ./Application/State/errorState.d ./Application/State/errorState.o ./Application/State/errorState.su ./Application/State/rfRecvState.d ./Application/State/rfRecvState.o ./Application/State/rfRecvState.su ./Application/State/rfSendState.d ./Application/State/rfSendState.o ./Application/State/rfSendState.su

.PHONY: clean-Application-2f-State

