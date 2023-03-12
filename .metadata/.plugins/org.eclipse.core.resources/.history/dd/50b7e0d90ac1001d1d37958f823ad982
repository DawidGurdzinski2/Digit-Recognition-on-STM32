#ifndef MENU_H_
#define MENU_H_
#include <stdint.h>

typedef struct menu_struct menu_t;

#define MENU_WIDTH 2
#define MENU_HEIGHT 2

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define STRUCT_WIDTH 120
#define STRUCT_HEIGHT 140

#define Y_OFFSET 40
#define X_OFFSET 0

// name,up,down,left,right, child,parent , print_function , menu_function
struct menu_struct {

	const char * name;
	menu_t * up;
	menu_t * down;
	menu_t * left;
	menu_t * right;
	menu_t * child;
	menu_t * parent;
	void (*print_function)(uint16_t,uint16_t,uint16_t,uint16_t);
	void (*menu_function)(void);
};



void reset_CP_position(void);
void refresh_structarray(void);

void refreshStructPos(void);
void refreshStructPosLVL1(void);

void menu_refresh(void);

void menu_enter(void);
void checkTapArea(void);




#endif /* MENU_H_ */
