#include "gameCore.h"
#include "stage.h"  
#include "player.h" 
#include "gameModeChange.h"
#include "bitmap.h"

int block_x[INIT];
int block_y[INIT];
int rnd_interval[BLOCK_NUM];
int rnd_x[BLOCK_NUM];
int star_interval[STAR_NUM];
int star_x[STAR_NUM];

void StageUpdate(byte stageNum,byte s_init){

  stageCommonUpdate(stageNum);

	if(s_init == 1){stageInit();}
  for(int i=1; i<BLOCK_NUM; i++){
    blockSet(rnd_x[i], rnd_interval[i] - camera_y + camera_adj,mid_floor,stageNum);
  } 
  for(int i=0; i<STAR_NUM; i++){
    arduboy.drawBitmap(star_x[i], star_interval[i]- camera_y + camera_adj, star, 8, 8, 1);
  }
}

void blockSet(int x, int y, ObjectTypes floorType,int stageNum) {
  for(int i=0; i<(BLOCK_DISP_LENGTH/stageNum); i++){arduboy.drawBitmap(x+i+4, y+4, std_block, 1, 1, 1);}
  for(int i=0; i<(BLOCK_LENGTH/stageNum); i++){
    if(pla_x == (x+i) && pla_y >= y-5 && pla_y <= y-3){ //hit
      if(floorType == mid_floor){Collision(true,mid_floor);}
      if(floorType == g_floor){gameMode = GAME_CLEAR;}
    }
  } 
}

void stageInit() {
  star_interval[0] = 100;
  for(int i=1; i<BLOCK_NUM; i++){
  	rnd_interval[i] = random(12,35)*(-1) + rnd_interval[i-1];
    rnd_x[i] = random(18,75);
  }
  for(int i=1; i<STAR_NUM; i++){
  	star_interval[i] = random(15,30)*(-1) + star_interval[i-1];
    star_x[i] = random(5,120);
  }
}

void stageCommonUpdate(int stageNum){
  Collision(false,0);
  rnd_interval[0] = 100;
  rnd_x[0] = 45;
  blockSet(45,104 - camera_y + camera_adj,mid_floor,stageNum); //start_block
  blockSet(45,-300 - camera_y + camera_adj,g_floor,stageNum);  //goal_block
  arduboy.drawBitmap(27, -300 - camera_y + camera_adj, star, 8, 8, 1);
  arduboy.drawBitmap(30, -300 - camera_y + camera_adj, star, 8, 8, 1);
  arduboy.drawBitmap(70, -300 - camera_y + camera_adj, star, 8, 8, 1);
  arduboy.drawBitmap(73, -300 - camera_y + camera_adj, star, 8, 8, 1);
}