#include "gameCore.h"
#include "altlogo.h"

void altlogo() {

  for(int i = -8; i < 28; i = i + 2)
  {
    arduboy.clear();
    arduboy.setCursor(21, i);
    arduboy.setTextSize(2);
    arduboy.print("ALTech.");
    arduboy.display();
    delay(100);
  }
  arduboy.tunes.tone(987, 160);
  delay(160);
  arduboy.tunes.tone(1318, 400);
  delay(2000);
}
