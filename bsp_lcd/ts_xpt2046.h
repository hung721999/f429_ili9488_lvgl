/*
 * XPT2046 touch driver STM32F4
 * author: Roberto Benjami
 * v.2021.04.30
 */

//=============================================================================

/* SPI select (0, 1, 2, 3, 4, 5, 6)
   - 0: software SPI driver (the pins assign are full free)
   - 1..6: hardware SPI driver (the TS_SCK, TS_MOSI, TS_MISO pins are lock to hardware) */
#define TS_SPI            3

/* SPI write and read speed
   - software SPI: 0=none delay, 1=nop, 2=CLK pin double write, 3.. = TS_IO_Delay(TS_SPI_SPD - 3)
   - hardware SPI clock div fPCLK: 0=/2, 1=/4, 2=/8, 3=/16, 4=/32, 5=/64, 6=/128, 7=/256 */
#define TS_SPI_SPD        2

/* SPI pins alternative function assign (0..15), (only hardware SPI) */
#define TS_SPI_AFR        6

/* Lcd control pins assign (A..K, 0..15)
   - if hardware SPI: SCK, MOSI, MISO pins assign is lock to hardware */
#define TS_CS             C, 9
#define TS_SCK            C, 10
#define TS_MOSI           C, 12
#define TS_MISO           C, 11
#define TS_IRQ            C, 8  /* If not used leave it that way */
