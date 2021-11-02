#include "../include/sprite.h"
// Initalise Object
Sprite::Sprite(int initPosX,int initPosY){
  posX = initPosX;
  posY = initPosY;
}
// Following Functions get and set Pos
int Sprite::getPosX(void){return posX;}

int Sprite::getPosY(void){return posY;}

void Sprite::setPos(int x,int y){posX = x;posY =y;}