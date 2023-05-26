################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../W25Q64/DataConversion.c \
../W25Q64/W25Q64Drv.c 

OBJS += \
./W25Q64/DataConversion.o \
./W25Q64/W25Q64Drv.o 

C_DEPS += \
./W25Q64/DataConversion.d \
./W25Q64/W25Q64Drv.d 


# Each subdirectory must supply rules for building sources it contributes
W25Q64/%.o W25Q64/%.su W25Q64/%.cyclo: ../W25Q64/%.c W25Q64/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../GUI/Inc -I../LCD/Inc -I"/home/dawid/Desktop/Programing and other/GITHUB/Digit-Recognition-on-STM32/DIGIT_REC/W25Q64" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-W25Q64

clean-W25Q64:
	-$(RM) ./W25Q64/DataConversion.cyclo ./W25Q64/DataConversion.d ./W25Q64/DataConversion.o ./W25Q64/DataConversion.su ./W25Q64/W25Q64Drv.cyclo ./W25Q64/W25Q64Drv.d ./W25Q64/W25Q64Drv.o ./W25Q64/W25Q64Drv.su

.PHONY: clean-W25Q64

