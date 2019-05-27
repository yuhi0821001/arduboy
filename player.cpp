#include "gameCore.h"
#include "logo.h"  
#include "player.h"
#include "stage.h"
#include "bitmap.h"

int pla_x;
int pla_y;
int pla_vy;
int camera_x;
int camera_y;
int camera_adj = 0;
int jump_power;
byte pla_state; //stay=0, heap=1, jump=2
byte pla_collision;
byte direction; //stay=0, up=1, down=2

void PlayerUpdate(byte nowInput, byte p_init){
  
  playerCommonUpdate(nowInput);

	if(p_init == 1){playerInit();}

  jpUpdate();
  
  moveCore(nowInput);
  
  dispPlayer();

  areaCheck();
		
	playerStateChange(nowInput);

}

void playerInit(void) {
   pla_x = 50;
   pla_y = 53;
   pla_state = STAY;
   pla_collision = 1;
   jump_power = 0;
   camera_adj = 0;
}

void playerStateChange(byte nowInput){
	  if(pla_state == STAY && (nowInput == BTN_B))  {pla_state = HEAP;}
	  if(pla_state == HEAP && !(nowInput == BTN_B)) {pla_state = JUMP;}
	  if(pla_state == JUMP && (pla_collision >= 1) && (direction == 2)){pla_state = STAY;}

}

void Collision(bool x,enum ObjectTypes e) {
  if (x == true) {
    if(e = 0){ pla_collision = 1;} //grand_floor
    if(e = 1){ 
      if(direction != 1){pla_collision = 2;} //mid_floor
    }
  } else {
    pla_collision = 0;
  }
}

void playerCommonUpdate(byte nowInput){
  if(pla_collision == 0){ pla_y++;}
  camera_y = pla_y - 8;
  if((pla_state == STAY || pla_state == HEAP) && (pla_y <= 50)){camera_adj = camera_adj+2;}
  if(nowInput == BTN_B && jump_power < 11 && !(direction == 1)){ jump_power++; } //heap jump power
}

void jpUpdate(){
  switch (pla_state) {
    case STAY:
      if(jump_power >= 1){ jump_power = 0;}
      pla_vy = 0;
      direction = 0;
      break;
    case HEAP:
      break;
    case JUMP:
      if(pla_collision == 0){ pla_y = pla_y-2;}
      if(jump_power > 0){ 
        jump_power--;
        direction = 1;
      }
      pla_vy -= jump_power/2;
      pla_vy = Gravity(pla_vy);
      if(pla_vy > 0){direction = 2;}  //direction check
      break;
  }
}

void moveCore(byte nowInput){
  if(nowInput & BTN_L){ pla_x--;}
  if(nowInput & BTN_R){ pla_x++;}
  if((pla_collision == 1 && direction == 1) ||
     (pla_collision == 0 && direction == 2 )){ pla_y += pla_vy;}
  if(pla_collision == 2 && direction == 1) {pla_y += (pla_vy/8);}//surinuke
}

void dispPlayer(){
  if(jump_power == 0){ arduboy.drawBitmap(pla_x, pla_y, player1, 8, 8, 1);}
  if(jump_power > 0 && jump_power <= 10){ arduboy.drawBitmap(pla_x, pla_y, player2, 8, 8, 1);}
  if(jump_power > 10){ arduboy.drawBitmap(pla_x, pla_y, player3, 8, 8, 1);}
}

void areaCheck(){
  if(pla_x < 4){ pla_x = 4;}
	if(pla_x > SCREEN_WIDTH) { pla_x = SCREEN_WIDTH; }
  if(pla_y < 4){ pla_y = 4;}
	if(pla_y > SCREEN_HEIGHT - 4) { pla_y = SCREEN_HEIGHT - 4; }
}

int Gravity(int vy) {
  if ( vy < 2) {vy++;}
  return vy;
}
