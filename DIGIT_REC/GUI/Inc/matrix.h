#ifndef MATRIX_H_
#define MATRIX_H_

#include "stdint.h"

#define LCD_WIDTH 240
#define LCD_HEIGHT 320
#define MATRIX_RESOLUTION 28
#define NUM_PIXELS 784  //28*28
#define PIXEL_SIZE 8
struct matrix{

	uint8_t Atributs[NUM_PIXELS];

//	const uint8_t w = 22;


};



#define BLACK_THEME
//#define DEFAULT_THEME
//colors
//SHAD1 - biggest value  SHAD4 -lowest value
#ifdef BLACK_THEME
#define SHAD1 0x0000
#define SHAD2 0x4208
#define SHAD3 0x528a
#define SHAD4 0x8c51
#endif

#ifdef DEFAULT_THEME
#define SHAD1 0xF800
#define SHAD2 0xF81F
#define SHAD3 0x001F
#define SHAD4 0x07E0


#endif






void calcChunk(uint16_t,uint16_t);
void putDataToArray(uint8_t , uint8_t ,uint16_t );
void boundaryConditions(uint8_t , uint8_t);
void ColorPixel(uint16_t , uint16_t );

#endif /* MATRIX_H_ */
