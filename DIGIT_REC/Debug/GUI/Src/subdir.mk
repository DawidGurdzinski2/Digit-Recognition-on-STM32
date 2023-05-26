################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GUI/Src/matrix.c \
../GUI/Src/menu.c 

OBJS += \
./GUI/Src/matrix.o \
./GUI/Src/menu.o 

C_DEPS += \
./GUI/Src/matrix.d \
./GUI/Src/menu.d 


# Each subdirectory must supply rules for building sources it contributes
GUI/Src/%.o GUI/Src/%.su GUI/Src/%.cyclo: ../GUI/Src/%.c GUI/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../GUI/Inc -I../LCD/Inc -I"/home/dawid/Desktop/Programing and other/GITHUB/Digit-Recognition-on-STM32/DIGIT_REC/W25Q64" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-GUI-2f-Src

clean-GUI-2f-Src:
	-$(RM) ./GUI/Src/matrix.cyclo ./GUI/Src/matrix.d ./GUI/Src/matrix.o ./GUI/Src/matrix.su ./GUI/Src/menu.cyclo ./GUI/Src/menu.d ./GUI/Src/menu.o ./GUI/Src/menu.su

.PHONY: clean-GUI-2f-Src

