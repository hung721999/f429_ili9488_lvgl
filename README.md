## This project runs LVGL with STM32F429 Nucleo and LCD ILI9488.
To run rgb mixer, uncomment this in main.c.
To run demo widget, uncomment this in main.c.
To run demo benchmark, uncomment this in main.c.
This project also use DMA to transfer data SPI.
SPI1 is used to transmit data image, SPI3 to transmit data touchpad.

## Connection:
### SPI 1 <-------> LCD:
LCD_RST 	PD14  <br>
LCD_RS 		PD15  <br>
LCD_CS 		PF12  <br>
LCD_SCK 	PA5   <br>
LCD_MOSI 	PA7  <br>
LCD_MISO 	PA6  <br>

### SPI 3 <-------> LCD:
TS_CS             PC9    <br>
TS_SCK            PC10   <br>
TS_MOSI           PC12   <br>
TS_MISO           PC11   <br>
TS_IRQ            PC8    <br>


![CN on STM32F429 Nucleo](connector.png)
 
Demo widget: https://youtu.be/YhzNdz8crOY
 
Demo benchmark with DMA: https://youtu.be/qHp6eaYccfI

Demo benchmark without DMA: https://youtu.be/wb4hWXlK-wU

Demo RGB mixer: https://youtu.be/-JJ_3IZXAUo
