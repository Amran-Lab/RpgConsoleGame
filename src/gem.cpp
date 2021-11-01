#include "../include/gem.h"

Gem::Gem(int initPosX,int initPosY) :Sprite(initPosX,initPosY){

}
bool Gem::collision(int x,int y){
    if ((posX == x ) && (posY==y)){
      setPos(rand() % 10,rand() % 10);
      return true;
    }
    return false;
}