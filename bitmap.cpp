#include "bitmap.h"
#include "gameCore.h"

PROGMEM const unsigned char player1[] = {
	//width = 8, height = 8
  0b00001000,
  0b11111100,
  0b11100110,
  0b01111111,
  0b01111111,
  0b11100110,
  0b11111100,
  0b00001000
};

PROGMEM const unsigned char player2[] = {
	//width = 8, height = 8
  0b00100000,
  0b10110000,
  0b11011000,
  0b01111100,
  0b01001100,
  0b11011000,
  0b10110000,
  0b00100000
};

PROGMEM const unsigned char player3[] = {
	//width = 8, height = 8
  0b10000000,
  0b11000000,
  0b10100000,
  0b11110000,
  0b11110000,
  0b10100000,
  0b11000000,
  0b10000000
};

PROGMEM const unsigned char star[] = {
	//width = 8, height = 8
  0b00000000,
  0b00000000,
  0b00000000,
  0b00010000,
  0b00111000,
  0b00010000,
  0b00000000,
  0b00000000
};