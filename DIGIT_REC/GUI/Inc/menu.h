#ifndef MENU_H_
#define MENU_H_
#include <stdint.h>



#define LCD_WIDTH 240
#define LCD_HEIGHT 320

#define THEME

#ifdef THEME
#define BACKGROUNDCOL 0X4E6C
#define BUTTONCOL 0X8765
#define RELOADCOL 0X420a
#define MATRIXCOL 0xffff
#endif

void refreshMenu(void);
void updateScreen(uint16_t ,uint16_t );



#endif /* MENU_H_ */
