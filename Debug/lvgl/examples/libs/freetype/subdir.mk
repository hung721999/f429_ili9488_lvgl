################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/libs/freetype/lv_example_freetype_1.c 

OBJS += \
./lvgl/examples/libs/freetype/lv_example_freetype_1.o 

C_DEPS += \
./lvgl/examples/libs/freetype/lv_example_freetype_1.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/libs/freetype/%.o lvgl/examples/libs/freetype/%.su lvgl/examples/libs/freetype/%.cyclo: ../lvgl/examples/libs/freetype/%.c lvgl/examples/libs/freetype/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/bsp_lcd" -I../Core/Inc -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/lvgl/src" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-libs-2f-freetype

clean-lvgl-2f-examples-2f-libs-2f-freetype:
	-$(RM) ./lvgl/examples/libs/freetype/lv_example_freetype_1.cyclo ./lvgl/examples/libs/freetype/lv_example_freetype_1.d ./lvgl/examples/libs/freetype/lv_example_freetype_1.o ./lvgl/examples/libs/freetype/lv_example_freetype_1.su

.PHONY: clean-lvgl-2f-examples-2f-libs-2f-freetype

