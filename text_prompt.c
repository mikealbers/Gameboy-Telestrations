#include <gb/gb.h>
#include "helper_functions.c"
#include "struct_cursor.c"
#include "map_text_editor.c"
#include "sprite_text.c"


UBYTE keydown;
UBYTE phraseEntered;
struct Cursor cursor;
const UINT8 MIN_CURSOR_X = 40;
const UINT8 MIN_CURSOR_Y = 88;
const UINT8 MAX_CURSOR_X = 136;
const UINT8 MAX_CURSOR_Y = 136;
UINT8 phraseCharacterIndex;
UINT8 phraseLineOne[13];
UINT8 phraseLineTwo[13];
UINT8 phraseLineThree[13];

UBYTE isWithinKeyboard(UINT8 x, UINT8 y){
  return x >= MIN_CURSOR_X && x <= MAX_CURSOR_X && y >= MIN_CURSOR_Y && y <= MAX_CURSOR_Y;
}

void addToPhrase(struct Cursor* cursor){
  UINT8 characterIndex = cursor->row * 7 + cursor->column + 11;

  if(phraseCharacterIndex == 39) return;

  if(phraseCharacterIndex < 13) {
    phraseLineOne[phraseCharacterIndex] = characterIndex;
    phraseCharacterIndex++;
    set_bkg_tiles(3, 3, 13, 1, phraseLineOne);
  }
  else if(phraseCharacterIndex >= 13 && phraseCharacterIndex < 26){
    phraseLineTwo[(phraseCharacterIndex - 13)] = characterIndex;
    phraseCharacterIndex++;
    set_bkg_tiles(3, 4, 13, 1, phraseLineTwo);
  } 
  else {
    phraseLineThree[(phraseCharacterIndex - 26)] = characterIndex;
    phraseCharacterIndex++;
    set_bkg_tiles(3, 5, 13, 1, phraseLineThree);
  }
}

void removeFromPhrase(){
  if(phraseCharacterIndex > 0){
    
    if(phraseCharacterIndex <= 13){
      phraseCharacterIndex--;
      phraseLineOne[phraseCharacterIndex] = 0;
      set_bkg_tiles(3, 3, 13, 1, phraseLineOne);
    }
    else if (phraseCharacterIndex >= 14 && phraseCharacterIndex < 27){
      phraseCharacterIndex--;
      phraseLineTwo[phraseCharacterIndex - 13] = 0;
      set_bkg_tiles(3, 4, 13, 1, phraseLineTwo);
    }
    else {
      phraseCharacterIndex--;
      phraseLineThree[phraseCharacterIndex - 26] = 0;
      set_bkg_tiles(3, 5, 13, 1, phraseLineThree);  
    }
  }
}


void updatePhrase(struct Cursor* cursor){
  if(cursor->column==6 && cursor->row==3){
    // delete
    removeFromPhrase();
  }
  else {
    // add to phrase
    addToPhrase(cursor);
  }
}

void textEntry() {

  cursor.x = 40;
  cursor.y = 88;
  cursor.column = 0;
  cursor.row = 0;

  set_sprite_data(0, 48, sprite_text);
  set_sprite_tile(0, 44);
  move_sprite(0, cursor.x, cursor.y);
  set_bkg_data(0, 48, sprite_text);
  set_bkg_tiles(0, 0, 20, 18, map_text_editor);
  
  SHOW_BKG;
  SHOW_SPRITES;
  DISPLAY_ON;

  while(!phraseEntered){
    if(keydown){
      waitpadup();
      keydown = 0;
    }

    switch(joypad()){
      case J_UP:
        if(isWithinKeyboard(cursor.x, cursor.y - 16)){
          cursor.y -= 16;
          scroll_sprite(0,0,-16);
          keydown = 1;
          cursor.row--;
        }
        break;
      case J_DOWN: 
        if(isWithinKeyboard(cursor.x, cursor.y + 16)){            
          cursor.y += 16;
          scroll_sprite(0,0,16);
          keydown = 1;
          cursor.row++;
        }
        break;  
      case J_LEFT: 
        if(isWithinKeyboard(cursor.x - 16, cursor.y)){
          cursor.x -= 16;
          scroll_sprite(0,-16,0);
          keydown = 1;
          cursor.column--;
        }
        break; 
      case J_RIGHT: 
        if(isWithinKeyboard(cursor.x + 16, cursor.y)){            
          cursor.x += 16;
          scroll_sprite(0,16,0);
          keydown = 1;
          cursor.column++;
        }
          break;
      case J_A:
        // &cursor passes in a point to the cursor in memory not the actual struct
        updatePhrase(&cursor);
        keydown = 1;                
        break;
      case J_B:
        removeFromPhrase();
        //drawPhrase();
        keydown = 1;
        break;
      case J_START:
        HIDE_SPRITES;
        HIDE_BKG;
        phraseEntered = 1;
    }
    performantDelay(2);
  }
}