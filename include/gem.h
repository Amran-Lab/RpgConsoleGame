#include <iostream>
#include "../include/sprite.h"
using namespace std;
#ifndef GEM_H
#define GEM_H

class Gem: public Sprite {
  public:
  Gem(int initPosX,int initPosY);
  
  bool collision(int x,int y);
};
#endif