################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bsp_f4x/lcd/ili9488.c \
../bsp_f4x/lcd/lcd_io_spi.c 

OBJS += \
./bsp_f4x/lcd/ili9488.o \
./bsp_f4x/lcd/lcd_io_spi.o 

C_DEPS += \
./bsp_f4x/lcd/ili9488.d \
./bsp_f4x/lcd/lcd_io_spi.d 


# Each subdirectory must supply rules for building sources it contributes
bsp_f4x/lcd/%.o bsp_f4x/lcd/%.su bsp_f4x/lcd/%.cyclo: ../bsp_f4x/lcd/%.c bsp_f4x/lcd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/lvgl/src" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/lvgl" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/bsp_f4x/tsc" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/bsp_f4x/lvgl" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/bsp_f4x/lcd" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-bsp_f4x-2f-lcd

clean-bsp_f4x-2f-lcd:
	-$(RM) ./bsp_f4x/lcd/ili9488.cyclo ./bsp_f4x/lcd/ili9488.d ./bsp_f4x/lcd/ili9488.o ./bsp_f4x/lcd/ili9488.su ./bsp_f4x/lcd/lcd_io_spi.cyclo ./bsp_f4x/lcd/lcd_io_spi.d ./bsp_f4x/lcd/lcd_io_spi.o ./bsp_f4x/lcd/lcd_io_spi.su

.PHONY: clean-bsp_f4x-2f-lcd

