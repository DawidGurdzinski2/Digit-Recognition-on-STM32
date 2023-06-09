################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SIALGORITHMS/ForwardPass.c \
../SIALGORITHMS/NeuralNetwork.c 

OBJS += \
./SIALGORITHMS/ForwardPass.o \
./SIALGORITHMS/NeuralNetwork.o 

C_DEPS += \
./SIALGORITHMS/ForwardPass.d \
./SIALGORITHMS/NeuralNetwork.d 


# Each subdirectory must supply rules for building sources it contributes
SIALGORITHMS/%.o SIALGORITHMS/%.su SIALGORITHMS/%.cyclo: ../SIALGORITHMS/%.c SIALGORITHMS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../GUI/Inc -I../LCD/Inc -I"/home/dawid/Desktop/Programing and other/GITHUB/Digit-Recognition-on-STM32/DIGIT_REC/W25Q64" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"/home/dawid/Desktop/Programing and other/GITHUB/Digit-Recognition-on-STM32/DIGIT_REC/SDCARD" -I"/home/dawid/Desktop/Programing and other/GITHUB/Digit-Recognition-on-STM32/DIGIT_REC/SIALGORITHMS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SIALGORITHMS

clean-SIALGORITHMS:
	-$(RM) ./SIALGORITHMS/ForwardPass.cyclo ./SIALGORITHMS/ForwardPass.d ./SIALGORITHMS/ForwardPass.o ./SIALGORITHMS/ForwardPass.su ./SIALGORITHMS/NeuralNetwork.cyclo ./SIALGORITHMS/NeuralNetwork.d ./SIALGORITHMS/NeuralNetwork.o ./SIALGORITHMS/NeuralNetwork.su

.PHONY: clean-SIALGORITHMS

