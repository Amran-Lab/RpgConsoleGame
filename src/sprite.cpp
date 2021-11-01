#include "../include/sprite.h"

Sprite::Sprite(int initPosX,int initPosY){
  posX = initPosX;
  posY = initPosY;
}

int Sprite::getPosX(void){return posX;}

int Sprite::getPosY(void){return posY;}

void Sprite::setPos(int x,int y){posX = x;posY =y;}