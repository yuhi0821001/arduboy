#ifndef STAGE_H
#define STAGE_H


const byte INIT = 32;
const int BLOCK_NUM = 19;
const int BLOCK_LENGTH = 20;
const int BLOCK_DISP_LENGTH = 16;
const int STAR_NUM = 40;

PROGMEM const unsigned char std_block[] = { 0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };	// 3	Empty

void StageUpdate(byte,byte);
void blockSet(int,int,ObjectTypes,int);
void stageInit(void);
void stageCommonUpdate(int);

#endif