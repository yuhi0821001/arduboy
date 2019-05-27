#include "altlogo.h"
#include "gameCore.h"
#include "gameModeChange.h"
#include "player.h"
#include "stage.h"
#include "title.h"
Arduboy arduboy; //coreArduboy

byte nowInput; //byte 0～255
byte gameMode = TITLE; //coreGamemode
byte stageNum = 1;
byte counter = 0;
byte s_init = 0;
byte p_init = 0;
int score = 0;
int upper_pla_y = 54;
int upper_camera_adj = 0;

void setupcore() {
	arduboy.beginNoLogo();
	arduboy.setFrameRate(60);
	arduboy.initRandomSeed();
  altlogo();
}

void updatecore() {
  
	nowInput = 0;
	if (arduboy.pressed(UP_BUTTON)) { nowInput |= BTN_U; }
	if (arduboy.pressed(DOWN_BUTTON)) { nowInput |= BTN_D; }
	if (arduboy.pressed(LEFT_BUTTON)) { nowInput |= BTN_L; }
	if (arduboy.pressed(RIGHT_BUTTON)) { nowInput |= BTN_R; }
	if (arduboy.pressed(A_BUTTON)) { nowInput |= BTN_A; }
	if (arduboy.pressed(B_BUTTON)) { nowInput |= BTN_B; }
  gameModeChange(nowInput);

	switch (gameMode) {
	case TITLE:
    TitleDisp();
    p_init = 1;
    s_init = 1;
    stageNum = 1;
    score = 0;
		break;
		
	case GAME_MAIN:
	
	  upper_camera_adj = camera_adj;
    StageUpdate(stageNum,s_init);
    PlayerUpdate(nowInput,p_init);
    
    if(camera_adj > upper_camera_adj){score++;}
    arduboy.setCursor(1, 1);
    arduboy.print("SCORE:");
    arduboy.print(score);
    s_init = 0;
    p_init = 0;
	  break;
	  
	case GAME_OVER:
	  if(counter < 100){
      arduboy.setCursor(1, 9);
      arduboy.print("GAME OVER\n");
      arduboy.setCursor(1, 1);
      arduboy.print("SCORE:");
      arduboy.print(score);
	  }else{
	    counter = 0;
	    gameMode = TITLE;
	  }
	  counter++;
		break;
		
	case GAME_CLEAR:
    if(stageNum < STAGE_LIMIT ){
  	  arduboy.setCursor(4, 9);
      arduboy.print("STAGE ");
      arduboy.print(stageNum);
      arduboy.print(" CLEAR\n");
      counter++;
	    if(counter > 100){
        gameMode = GAME_MAIN;
        p_init = 1;
        s_init = 1;
        stageNum++;
        counter = 0;
      }
    }else{
  	  if(counter < 120){
        arduboy.setCursor(1, 9);
        arduboy.print("All STAGE CLEAR!\n");
        arduboy.print("SCORE:");
        arduboy.print(score);
  	  }else{
	      counter = 0;
	      gameMode = TITLE;
	    }
  	  counter++;
    }
    break;
	}
}