#include "common.h"
#include "menu.h"


void (*key_tap_func)(void) = &menu_enter;






void screen_tap_press(void){
	if(key_tap_func) (*key_tap_func)();
}


