#ifndef XPT2046_H
#define XPT2046_H

#include "main.h"
#include <stdbool.h>



#define XPT2046_SPI_PORT hspi4
extern SPI_HandleTypeDef XPT2046_SPI_PORT;



#define TOUCH_ORIENTATION_PORTRAIT 			(0U)
#define TOUCH_ORIENTATION_LANDSCAPE 		(1U)
#define TOUCH_ORIENTATION_PORTRAIT_MIRROR 	(2U)
#define TOUCH_ORIENTATION_LANDSCAPE_MIRROR 	(3U)

#define ORIENTATION	(TOUCH_ORIENTATION_PORTRAIT)


#if (ORIENTATION == 0)
#define XPT2046_SCALE_X 240
#define XPT2046_SCALE_Y 320
#elif (ORIENTATION == 1)
#define XPT2046_SCALE_X 320
#define XPT2046_SCALE_Y 240
#elif (ORIENTATION == 2)
#define XPT2046_SCALE_X 240
#define XPT2046_SCALE_Y 320
#elif (ORIENTATION == 3)
#define XPT2046_SCALE_X 320
#define XPT2046_SCALE_Y 240
#endif

#define XPT2046_MIN_RAW_X 3400
#define XPT2046_MAX_RAW_X 29000
#define XPT2046_MIN_RAW_Y 3300
#define XPT2046_MAX_RAW_Y 30000




extern bool XPT2046_TouchPressed(void);
extern bool XPT2046_TouchGetCoordinates(uint16_t* x, uint16_t* y);


#endif /* XPT2046_H_ */
