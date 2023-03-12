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

void calcChunk(uint16_t,uint16_t);
void putDataToArray(uint8_t , uint8_t ,uint8_t );
void boundaryConditions(uint8_t , uint8_t);


#endif /* MATRIX_H_ */
