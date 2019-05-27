#include "gameCore.h"
#include "title.h"

void TitleDisp(){
  
    arduboy.clear();
    arduboy.setCursor(5, 5);
    arduboy.setTextSize(2);
    arduboy.print("Squid JUMP\n");
    arduboy.setCursor(6, 35);
    arduboy.setTextSize(1);
    arduboy.print("Press A or B Button");
    arduboy.display();
    
}