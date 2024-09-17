/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev.h"
#include "lvgl.h"
#include "ts_xpt2046.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void touchpad_init(void);
static void touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
static bool touchpad_is_pressed(void);
static void touchpad_get_xy(lv_coord_t *x, lv_coord_t *y);

/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t *indev_touchpad;
extern int32_t ts_cindex[];

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void) {
	/**
	 * Here you will find example implementation of input devices supported by LittelvGL:
	 *  - Touchpad
	 *  - Mouse (with cursor support)
	 *  - Keypad (supports GUI usage only with key)
	 *  - Encoder (supports GUI usage only with: left, right, push)
	 *  - Button (external buttons to press points on the screen)
	 *
	 *  The `..._read()` function are only examples.
	 *  You should shape them according to your hardware
	 */

	static lv_indev_drv_t indev_drv;

	/*------------------
	 * Touchpad
	 * -----------------*/

	/*Initialize your touchpad if you have*/
	touchpad_init();

	/*Register a touchpad input device*/
	lv_indev_drv_init(&indev_drv);
	indev_drv.type = LV_INDEV_TYPE_POINTER;
	indev_drv.read_cb = touchpad_read;
	indev_touchpad = lv_indev_drv_register(&indev_drv);

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*------------------
 * Touchpad
 * -----------------*/

/*Initialize your touchpad*/
static void touchpad_init(void) {
	/*Your code comes here*/
	ili9488_ts_Init();
}

/*Will be called by the library to read the touchpad*/
static void touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data) {
	static lv_coord_t last_x = 0;
	static lv_coord_t last_y = 0;

	/*Save the pressed coordinates and the state*/
	if (touchpad_is_pressed()) {
		touchpad_get_xy(&last_x, &last_y);
		data->state = LV_INDEV_STATE_PR;
	} else {
		data->state = LV_INDEV_STATE_REL;
	}

	/*Set the last pressed coordinates*/
	data->point.x = last_x;
	data->point.y = last_y;
}

/*Return true is the touchpad is pressed*/
static bool touchpad_is_pressed(void) {
	/*Your code comes here*/
	return ili9488_ts_DetectTouch();
}

/*Get the x and y coordinates if the touchpad is pressed*/
static void touchpad_get_xy(lv_coord_t *x, lv_coord_t *y) {
	/*Your code comes here*/
	int16_t a, b;
	int32_t x1, y1, x2, y2;
	ili9488_ts_GetXY(&a, &b);
	x1 = a;
	y1 = b;
	x2 = ts_cindex[1] * x1 / ts_cindex[0] + ts_cindex[2] * y1 / ts_cindex[0]
			+ ts_cindex[3] / ts_cindex[0];
	y2 = ts_cindex[4] * x1 / ts_cindex[0] + ts_cindex[5] * y1 / ts_cindex[0]
			+ ts_cindex[6] / ts_cindex[0];

	if (x2 < 0)
		x2 = 0;
	else if (x2 >= ILI9488_LCD_PIXEL_HEIGHT)
		x2 = ILI9488_LCD_PIXEL_HEIGHT - 1;

	if (y2 < 0)
		y2 = 0;
	else if (y2 >= ILI9488_LCD_PIXEL_WIDTH)
		y2 = ILI9488_LCD_PIXEL_WIDTH - 1;

	*x = (lv_coord_t) x2;
	*y = (lv_coord_t) y2;
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
