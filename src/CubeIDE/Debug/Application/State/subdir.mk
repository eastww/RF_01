################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/State/checkGroupState.c \
../Application/State/errorState.c \
../Application/State/rfRecvState.c \
../Application/State/rfSendState.c 

OBJS += \
./Application/State/checkGroupState.o \
./Application/State/errorState.o \
./Application/State/rfRecvState.o \
./Application/State/rfSendState.o 

C_DEPS += \
./Application/State/checkGroupState.d \
./Application/State/errorState.d \
./Application/State/rfRecvState.d \
./Application/State/rfSendState.d 


# Each subdirectory must supply rules for building sources it contributes
Application/State/%.o Application/State/%.su Application/State/%.cyclo: ../Application/State/%.c Application/State/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -DUSE_CUBEIDE -DBSP_TEST_ENABLE=0 '-DAPP_VERSION=1.0.0' -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Code/rf_01/src/CubeIDE/Bsp" -I"D:/Code/rf_01/src/Radio/inc" -I"D:/Code/rf_01/src/CubeIDE/Service/kfifo" -I"D:/Code/rf_01/src/CubeIDE/Bsp/Test" -I"D:/Code/rf_01/src/CubeIDE/Application" -I"D:/Code/rf_01/src/CubeIDE/Application/State" -I"D:/Code/rf_01/src/CubeIDE/Service/messageQueue" -I"D:/Code/rf_01/src/CubeIDE/Service/stateMachine" -I"D:/Code/rf_01/src/CubeIDE/Bsp/config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-State

clean-Application-2f-State:
	-$(RM) ./Application/State/checkGroupState.cyclo ./Application/State/checkGroupState.d ./Application/State/checkGroupState.o ./Application/State/checkGroupState.su ./Application/State/errorState.cyclo ./Application/State/errorState.d ./Application/State/errorState.o ./Application/State/errorState.su ./Application/State/rfRecvState.cyclo ./Application/State/rfRecvState.d ./Application/State/rfRecvState.o ./Application/State/rfRecvState.su ./Application/State/rfSendState.cyclo ./Application/State/rfSendState.d ./Application/State/rfSendState.o ./Application/State/rfSendState.su

.PHONY: clean-Application-2f-State

