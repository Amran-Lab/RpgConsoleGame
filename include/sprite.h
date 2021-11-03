#include <iostream>
using namespace std;
#ifndef SPRITE_H
#define SPRITE_H
// Base Class
class Sprite {
  protected:
  int posX,posY;

  public:
  Sprite(int initPosX,int initPosY);

  int getPosX(void);

  int getPosY(void);
  
  void setPos(int x,int y);
};
#endif