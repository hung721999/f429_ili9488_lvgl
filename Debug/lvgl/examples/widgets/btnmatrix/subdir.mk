################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_1.c \
../lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_2.c \
../lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_3.c 

OBJS += \
./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_1.o \
./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_2.o \
./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_3.o 

C_DEPS += \
./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_1.d \
./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_2.d \
./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_3.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/btnmatrix/%.o lvgl/examples/widgets/btnmatrix/%.su lvgl/examples/widgets/btnmatrix/%.cyclo: ../lvgl/examples/widgets/btnmatrix/%.c lvgl/examples/widgets/btnmatrix/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/bsp_lcd" -I../Core/Inc -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/lvgl/src" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-btnmatrix

clean-lvgl-2f-examples-2f-widgets-2f-btnmatrix:
	-$(RM) ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_1.cyclo ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_1.d ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_1.o ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_1.su ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_2.cyclo ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_2.d ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_2.o ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_2.su ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_3.cyclo ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_3.d ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_3.o ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_3.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-btnmatrix

