#include <string.h>

#include <stdio.h>

#include "menu.h"
#include "menu_callbacks.h"
#include "menu_GUI.h"

menu_t menu1 ;
menu_t menu2 ;
menu_t menu3 ;
menu_t menu4 ;

// name,up,down,left,right, child,parent , print_function , menu_function
menu_t menu1 = { "ACVI ON", NULL, &menu3, NULL, &menu2, NULL,NULL,print_S1,ACVISITION_ON };
menu_t menu2 = { "ACVI OFF", NULL, &menu4, &menu1, NULL, NULL,NULL,print_S2,ACVISITION_OFF };
menu_t menu3 = { "RESET", &menu1, NULL, NULL, &menu4, NULL,NULL,print_S3, RSTACV };
menu_t menu4 = { "PRINT STH", &menu2, NULL, &menu3, NULL, NULL ,NULL,print_S4,PRINT};

menu_t * structarray[MENU_HEIGHT*MENU_WIDTH];
menu_t *currentPointer = &menu1;

//menu level  (if struct have child or parent struct)
uint16_t StrPosYLVL1[MENU_HEIGHT];
uint16_t StrPosXLVL1[MENU_WIDTH];
uint8_t currentlevel=1;

uint8_t StructXfunc=0;
uint8_t StructYfunc=0;

extern volatile uint16_t X,Y;

void reset_CP_position(){
	while(currentPointer->up){
		currentPointer=currentPointer->up;
	}
	while(currentPointer->left){
		currentPointer=currentPointer->left;
	}

}

void refresh_structarray(){
	reset_CP_position();
	menu_t * temp=currentPointer;
	for(uint8_t j=0;j<MENU_HEIGHT;j++ ){
		for(uint8_t i=0;i<MENU_WIDTH;i++){
			structarray[MENU_WIDTH*j+i]=temp;
			if(temp->right)
				temp=temp->right;
		}
		while(temp->left){
			temp=temp->left;
		}
		if(temp->down)
			temp=temp->down;
	}
}

void refreshStructPos(){
	if(currentlevel==1){
		refreshStructPosLVL1();
	}

}

void refreshStructPosLVL1(){
	for(uint8_t j=0;j<MENU_HEIGHT;j++){
		if(Y_OFFSET+STRUCT_HEIGHT*j<SCREEN_HEIGHT){
			StrPosYLVL1[j]=Y_OFFSET+STRUCT_HEIGHT*j;
		}
	}
	for(uint8_t i=0;i<MENU_WIDTH;i++){
		if(X_OFFSET+STRUCT_WIDTH*i<SCREEN_WIDTH){
			StrPosXLVL1[i]=X_OFFSET+STRUCT_WIDTH*i;
		}
	}
}

void menu_refresh(){
	for(uint8_t j=0;j<MENU_HEIGHT;j++){
		for(uint8_t i=0 ;i<MENU_WIDTH;i++){
			structarray[MENU_WIDTH*j+i]->print_function(StrPosXLVL1[i],StrPosXLVL1[i]+STRUCT_WIDTH,
					StrPosYLVL1[j],StrPosYLVL1[j]+STRUCT_HEIGHT	);
		}
	}

}

void checkTapArea(){
	if(X<StrPosXLVL1[1]){
		StructXfunc=1;
	}
	else{
		StructXfunc=2;
	}

	if(Y>StrPosYLVL1[0] && Y<StrPosYLVL1[1]){
		StructYfunc=1;
	}
	else if(Y>StrPosYLVL1[1]){
		StructYfunc=2;
	}
	else{
		StructYfunc=0;
	}

}


void menu_enter(void) {
	if(!currentPointer->menu_function && currentPointer->child)
	{
		currentPointer=currentPointer->child;
		currentlevel++;
		refresh_structarray();
		refreshStructPos();
		refreshStructPos();
	}
	else if(currentPointer->menu_function)
	{	checkTapArea();
	  	if(0!=StructXfunc && 0!= StructYfunc){
	  		structarray[MENU_WIDTH*(StructYfunc-1)+StructXfunc-1]->menu_function();
	  		refresh_taskbar();
	  	}

	}


}


