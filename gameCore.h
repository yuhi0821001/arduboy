#ifndef GAMECORE_H
#define GAMECORE_H

#include <Arduboy.h>
#include <avr/pgmspace.h>

const byte TITLE = 0;
const byte GAME_MAIN = 1;
const byte GAME_OVER = 2;
const byte GAME_CLEAR = 3;

const byte BTN_U = 1;
const byte BTN_D = 2;
const byte BTN_L = 4;
const byte BTN_R = 8;
const byte BTN_B = 16;
const byte BTN_A = 32;

const byte PLAYER_HIT_AREA = 4;
const byte FALL_LINE  = 62;
const byte SCREEN_WIDTH = 128;
const byte SCREEN_HEIGHT = 64;

const byte STAGE_LIMIT= 3;

enum ObjectTypes {
  g_floor = 0, // Sprites
  mid_floor
};

extern Arduboy arduboy;
extern byte gameMode;

void setupcore();
void updatecore();
//void rnd();

#endif