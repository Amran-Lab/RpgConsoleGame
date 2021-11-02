#include "../include/gem.h"
// Initalise Object
Gem::Gem(int initPosX,int initPosY) :Sprite(initPosX,initPosY){}
// Checks For Collision
bool Gem::collision(int x,int y){
    if ((posX == x ) && (posY==y)){
      setPos(rand() % 10,rand() % 10);
      return true;
    }
    return false;
}