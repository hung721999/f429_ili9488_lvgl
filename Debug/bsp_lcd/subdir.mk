################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bsp_lcd/ili9488.c \
../bsp_lcd/lcd_io_spi.c \
../bsp_lcd/lv_port_disp.c \
../bsp_lcd/lv_port_indev.c \
../bsp_lcd/ts_xpt2046.c 

OBJS += \
./bsp_lcd/ili9488.o \
./bsp_lcd/lcd_io_spi.o \
./bsp_lcd/lv_port_disp.o \
./bsp_lcd/lv_port_indev.o \
./bsp_lcd/ts_xpt2046.o 

C_DEPS += \
./bsp_lcd/ili9488.d \
./bsp_lcd/lcd_io_spi.d \
./bsp_lcd/lv_port_disp.d \
./bsp_lcd/lv_port_indev.d \
./bsp_lcd/ts_xpt2046.d 


# Each subdirectory must supply rules for building sources it contributes
bsp_lcd/%.o bsp_lcd/%.su bsp_lcd/%.cyclo: ../bsp_lcd/%.c bsp_lcd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/bsp_lcd" -I../Core/Inc -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/lvgl/src" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-bsp_lcd

clean-bsp_lcd:
	-$(RM) ./bsp_lcd/ili9488.cyclo ./bsp_lcd/ili9488.d ./bsp_lcd/ili9488.o ./bsp_lcd/ili9488.su ./bsp_lcd/lcd_io_spi.cyclo ./bsp_lcd/lcd_io_spi.d ./bsp_lcd/lcd_io_spi.o ./bsp_lcd/lcd_io_spi.su ./bsp_lcd/lv_port_disp.cyclo ./bsp_lcd/lv_port_disp.d ./bsp_lcd/lv_port_disp.o ./bsp_lcd/lv_port_disp.su ./bsp_lcd/lv_port_indev.cyclo ./bsp_lcd/lv_port_indev.d ./bsp_lcd/lv_port_indev.o ./bsp_lcd/lv_port_indev.su ./bsp_lcd/ts_xpt2046.cyclo ./bsp_lcd/ts_xpt2046.d ./bsp_lcd/ts_xpt2046.o ./bsp_lcd/ts_xpt2046.su

.PHONY: clean-bsp_lcd

