################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDCARD/SDDrv.c 

OBJS += \
./SDCARD/SDDrv.o 

C_DEPS += \
./SDCARD/SDDrv.d 


# Each subdirectory must supply rules for building sources it contributes
SDCARD/%.o SDCARD/%.su SDCARD/%.cyclo: ../SDCARD/%.c SDCARD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../GUI/Inc -I../LCD/Inc -I"/home/dawid/Desktop/Programing and other/GITHUB/Digit-Recognition-on-STM32/DIGIT_REC/W25Q64" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"/home/dawid/Desktop/Programing and other/GITHUB/Digit-Recognition-on-STM32/DIGIT_REC/SDCARD" -I"/home/dawid/Desktop/Programing and other/GITHUB/Digit-Recognition-on-STM32/DIGIT_REC/SIALGORITHMS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SDCARD

clean-SDCARD:
	-$(RM) ./SDCARD/SDDrv.cyclo ./SDCARD/SDDrv.d ./SDCARD/SDDrv.o ./SDCARD/SDDrv.su

.PHONY: clean-SDCARD

