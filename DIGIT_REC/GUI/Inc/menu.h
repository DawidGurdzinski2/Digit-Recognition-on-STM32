#ifndef MENU_H_
#define MENU_H_
#include <stdint.h>
#include "ST7789V_GFX.h"
#include "matrix.h"
#include <string.h>
#include "tim.h"



#define THEME

#ifdef THEME
#define BACKGROUNDCOL 0X4E6C
#define BUTTONCOL 0X8765
#define RELOADCOL 0X420a
#define MATRIXCOL 0xffff
#endif

void RefreshMenu(ST7789V *this,ChunkMatrix * cmtx);
uint8_t LoopScreen(ST7789V *this,ChunkMatrix * cmtx,uint16_t X ,uint16_t Y);
void Print_Result(ST7789V *this,uint8_t result);
void Print_Info_Calc(ST7789V *this);
void Print_Info_MEM_CL(ST7789V *this);
void Print_Info_MEM_WR(ST7789V *this);
void Print_Proc_10(ST7789V *this,uint8_t number);
#endif /* MENU_H_ */
