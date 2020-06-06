#include <gb/gb.h>
#include "helper_functions.c"

UBYTE keydown;
const UINT8 MIN_CURSOR_X = 0;
const UINT8 MIN_CURSOR_Y = 0;
const UINT8 MAX_CURSOR_X = 0;
const UINT8 MAX_CURSOR_Y = 0;

UBYTE isWithinKeyboard(UINT8 x, UINT8 y){
  
}

void textEntry() {
  
  SHOW_BKG;
  SHOW_SPRITES;
  DISPLAY_ON;

  while(1){
    if(keydown){
      waitpadup();
      keydown = 0;
    }

    switch(joypad()){
      case J_UP:
        //placeholder arguments
        if(isWithinKeyboard(MIN_CURSOR_X, MIN_CURSOR_X)){
          keydown = 1;
        }
        break;
      case J_DOWN:
        //placeholder arguments
        if(isWithinKeyboard(MIN_CURSOR_X, MIN_CURSOR_X)){
          keydown = 1;
        }
        break;
      case J_LEFT:
        //placeholder arguments
        if(isWithinKeyboard(MIN_CURSOR_X, MIN_CURSOR_X)){
          keydown = 1;
        }
        break;
      case J_RIGHT:
        //placeholder arguments
        if(isWithinKeyboard(MIN_CURSOR_X, MIN_CURSOR_X)){
          keydown = 1;
        }
        break;
      case J_SELECT:
        //placeholder arguments
        if(isWithinKeyboard(MIN_CURSOR_X, MIN_CURSOR_X)){
          keydown = 1;
        }
        break;
      case J_START:

        break;
    }

    performantDelay(2);
  }
}