/**
 * @file XPT2046.h
 *
 */

#ifndef XPT2046_H
#define XPT2046_H

#define USE_XPT2046 1

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#ifndef LV_DRV_NO_CONF
#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lv_drv_conf.h"
#else
#include "lv_drv_conf.h"
#endif
#endif

#if USE_XPT2046

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/
#define XPT2046_HOR_RES     320
#define XPT2046_VER_RES     480
#define XPT2046_X_MIN       200
#define XPT2046_Y_MIN       300
#define XPT2046_X_MAX       3800
#define XPT2046_Y_MAX       3800
#define XPT2046_AVG         4
#define XPT2046_X_INV       0
#define XPT2046_Y_INV       0
#define XPT2046_XY_SWAP     1

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void xpt2046_init(void);
void xpt2046_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);

/**********************
 *      MACROS
 **********************/

#endif /* USE_XPT2046 */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* XPT2046_H */
