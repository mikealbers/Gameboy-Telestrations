#include <gb/gb.h>
#include <stdio.h>
#include "struct_game_state.c"
#include "text_prompt.c"
#include "canvas.c"

struct GameState gameState;

UINT8 gameMode;

// void updateGameState(struct GameState* gameState){
//   // stub function
// }

void main(){
  while(1){
    switch(gameMode){
      case 0:
        textEntry(gameMode);
        canvas();
        break;
      case 1:
        canvas();
        break;
    }

  }

}