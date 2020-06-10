#include <gb/gb.h>

typedef struct GameState
{
  UINT8 playerCount;
  UINT8 currentPlayer;
  UINT8 gameMode;
  // In here I was thinking we could store the 
  // player drawings, player phrases, and the current
  // stage of the game. This would be instantiated in 
  // the main.c and updated in each stage of the game.
};