#include "gameCore.h"
#include "gameModeChange.h"
#include "player.h"


void gameModeChange(byte nowInput){
  
  switch (gameMode) {
	case TITLE:
    if(nowInput == BTN_A || nowInput == BTN_B ){
      gameMode = GAME_MAIN;
    }
		break;
	case GAME_MAIN:
	  fallCheck();
	case GAME_OVER:
	case GAME_CLEAR:
	  break;
  }
}

void fallCheck(void){
 if( pla_y+PLAYER_HIT_AREA > FALL_LINE ){gameMode = GAME_OVER;} 
}