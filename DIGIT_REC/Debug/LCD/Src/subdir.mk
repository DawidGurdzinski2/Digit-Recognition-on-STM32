################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD/Src/ST7789V.c \
../LCD/Src/ST7789V_GFX.c \
../LCD/Src/XPT2046.c \
../LCD/Src/fonts.c 

OBJS += \
./LCD/Src/ST7789V.o \
./LCD/Src/ST7789V_GFX.o \
./LCD/Src/XPT2046.o \
./LCD/Src/fonts.o 

C_DEPS += \
./LCD/Src/ST7789V.d \
./LCD/Src/ST7789V_GFX.d \
./LCD/Src/XPT2046.d \
./LCD/Src/fonts.d 


# Each subdirectory must supply rules for building sources it contributes
LCD/Src/%.o LCD/Src/%.su LCD/Src/%.cyclo: ../LCD/Src/%.c LCD/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../GUI/Inc -I../LCD/Inc -I"/home/dawid/Desktop/Programing and other/GITHUB/Digit-Recognition-on-STM32/DIGIT_REC/W25Q64" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"/home/dawid/Desktop/Programing and other/GITHUB/Digit-Recognition-on-STM32/DIGIT_REC/SDCARD" -I"/home/dawid/Desktop/Programing and other/GITHUB/Digit-Recognition-on-STM32/DIGIT_REC/SIALGORITHMS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LCD-2f-Src

clean-LCD-2f-Src:
	-$(RM) ./LCD/Src/ST7789V.cyclo ./LCD/Src/ST7789V.d ./LCD/Src/ST7789V.o ./LCD/Src/ST7789V.su ./LCD/Src/ST7789V_GFX.cyclo ./LCD/Src/ST7789V_GFX.d ./LCD/Src/ST7789V_GFX.o ./LCD/Src/ST7789V_GFX.su ./LCD/Src/XPT2046.cyclo ./LCD/Src/XPT2046.d ./LCD/Src/XPT2046.o ./LCD/Src/XPT2046.su ./LCD/Src/fonts.cyclo ./LCD/Src/fonts.d ./LCD/Src/fonts.o ./LCD/Src/fonts.su

.PHONY: clean-LCD-2f-Src

