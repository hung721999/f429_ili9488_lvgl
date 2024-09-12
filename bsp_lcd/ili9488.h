#include <stdint.h>

/* Interface mode
 - 0: SPI mode (the lcd does not work in 16bit/pixel mode in spi, so you have to write 24bit/pixel)
 - 1: paralell mode */
#define  ILI9488_INTERFACE        0

/* Orientation:
 - 0: 320x480 micro-sd in the top (portrait)
 - 1: 480x320 micro-sd in the left (landscape)
 - 2: 320x480 micro-sd in the bottom (portrait)
 - 3: 480x320 micro-sd in the right (landscape)
 */
#define  ILI9488_ORIENTATION       3

/* Color mode
 - 0: RGB565 (R:bit15..11, G:bit10..5, B:bit4..0) (default)
 - 1: BRG565 (B:bit15..11, G:bit10..5, R:bit4..0)
 */
#define  ILI9488_COLORMODE         0

/* Touchscreen
 - 0: touchscreen disabled (default)
 - 1: touchscreen enabled
 */
#define  ILI9488_TOUCH             1

/* Touchscreen calibration data for 4 orientations */
#define  TS_CINDEX_0        {3385020, 333702, -667424, 1243070964, -458484, -13002, 1806391572}
#define  TS_CINDEX_1        {3385020, -458484, -13002, 1806391572, -333702, 667424, -163249584}
#define  TS_CINDEX_2        {3385020, -333702, 667424, -163249584, 458484, 13002, -184966992}
#define  TS_CINDEX_3        {3385020, 458484, 13002, -184966992, 333702, -667424, 1243070964}

/* For multi-threaded or intermittent use, Lcd and Touchscreen simultaneous use can cause confusion (since it uses common I/O resources)
 Lcd functions wait for the touchscreen header, the touchscreen query is not executed when Lcd is busy.
 �Note: If the priority of the Lcd is higher than that of the Touchscreen, it may end up in an infinite loop!
 - 0: multi-threaded protection disabled (default)
 - 1: multi-threaded protection enabled
 */
#define  ILI9488_MULTITASK_MUTEX   0

/* ILI9488 Size (physical resolution in default orientation) */
#define  ILI9488_LCD_PIXEL_WIDTH   320
#define  ILI9488_LCD_PIXEL_HEIGHT  480

// Lcd
void ili9488_Init(void);
uint16_t ili9488_ReadID(void);
void ili9488_DisplayOn(void);
void ili9488_DisplayOff(void);
void ili9488_SetCursor(uint16_t Xpos, uint16_t Ypos);
void ili9488_WritePixel(uint16_t Xpos, uint16_t Ypos, uint16_t RGB_Code);
uint16_t ili9488_ReadPixel(uint16_t Xpos, uint16_t Ypos);
void ili9488_SetDisplayWindow(uint16_t Xpos, uint16_t Ypos, uint16_t Width,
		uint16_t Height);
void ili9488_DrawHLine(uint16_t RGBCode, uint16_t Xpos, uint16_t Ypos,
		uint16_t Length);
void ili9488_DrawVLine(uint16_t RGBCode, uint16_t Xpos, uint16_t Ypos,
		uint16_t Length);
uint16_t ili9488_GetLcdPixelWidth(void);
uint16_t ili9488_GetLcdPixelHeight(void);
void ili9488_DrawBitmap(uint16_t Xpos, uint16_t Ypos, uint8_t *pbmp);
void ili9488_DrawRGBImage(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize,
		uint16_t Ysize, uint16_t *pdata);
void ili9488_ReadRGBImage(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize,
		uint16_t Ysize, uint16_t *pdata);
void ili9488_FillRect(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize,
		uint16_t Ysize, uint16_t RGBCode);
void ili9488_Scroll(int16_t Scroll, uint16_t TopFix, uint16_t BottonFix);

// Touchscreen
void ili9488_ts_Init();
uint8_t ili9488_ts_DetectTouch();
void ili9488_ts_GetXY(int16_t *X, int16_t *Y);
