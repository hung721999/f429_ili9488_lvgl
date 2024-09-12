################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.c \
../lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.c \
../lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_letter.c 

OBJS += \
./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.o \
./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.o \
./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_letter.o 

C_DEPS += \
./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.d \
./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.d \
./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_letter.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/nema_gfx/%.o lvgl/src/draw/nema_gfx/%.su lvgl/src/draw/nema_gfx/%.cyclo: ../lvgl/src/draw/nema_gfx/%.c lvgl/src/draw/nema_gfx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/bsp_lcd" -I../Core/Inc -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/lvgl/src" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.15/F429_ILI9488_LVGL/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-draw-2f-nema_gfx

clean-lvgl-2f-src-2f-draw-2f-nema_gfx:
	-$(RM) ./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.cyclo ./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.d ./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.o ./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.su ./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.cyclo ./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.d ./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.o ./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.su ./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_letter.cyclo ./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_letter.d ./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_letter.o ./lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_letter.su

.PHONY: clean-lvgl-2f-src-2f-draw-2f-nema_gfx

