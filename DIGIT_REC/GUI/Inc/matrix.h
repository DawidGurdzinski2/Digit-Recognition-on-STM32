#ifndef MATRIX_H_
#define MATRIX_H_

#include "stdint.h"
#include "ST7789V_GFX.h"



typedef struct _ChunkMatrix{
	uint8_t ChunkSize;
	uint8_t MatrixRes;
	uint16_t ChunkNum;
	uint16_t Color1;
	uint16_t Color2;
	uint16_t Color3;
	uint16_t Color4;
	uint8_t * Chunks;
}ChunkMatrix;



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





ChunkMatrix CreateChunkMatrix(uint8_t * buff);
void CalcChunk(ST7789V *this,ChunkMatrix * cmtx,uint16_t X ,uint16_t Y);
void  FillChunks(ST7789V *this,ChunkMatrix * cmtx,uint8_t row , uint8_t column);
void PutDataToArray(ST7789V *this,ChunkMatrix * cmtx,uint8_t row , uint8_t column,uint16_t value);
void ColorChunks(ST7789V *this,ChunkMatrix * cmtx,uint16_t row , uint16_t column);


#endif /* MATRIX_H_ */
