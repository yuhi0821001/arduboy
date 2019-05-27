#ifndef PLAYER_H
#define PLAYER_H
//#include "gameCore.h"

void PlayerUpdate(byte,byte);
int Gravity(int);
void playerInit(void);
void playerStateChange(byte);
void Collision(bool,enum ObjectTypes);
void playerCommonUpdate(byte);
void jpUpdate(void);
void moveCore(byte);
void dispPlayer(void);
void areaCheck(void);

const byte STAY = 0;
const byte HEAP = 1;
const byte JUMP = 2;

extern int pla_x;
extern int pla_y;
extern byte pla_collision;
extern int camera_x;
extern int camera_y;
extern int camera_adj;
#endif