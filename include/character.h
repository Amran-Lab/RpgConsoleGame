#include <iostream>
#include "../include/gamestate.h"
#include "../include/sprite.h"
#include "../include/gem.h"
using namespace std;
#ifndef CHARACTER_H
#define CHARACTER_H

class Character: public Sprite {
  public:
    Character(int initPosX,int initPosY,int initAtk,int initDef, int initHp) : Sprite(initPosX,initPosY){
      atk = initAtk;
      def = initDef;
      hp = initHp;
      liveHp = initHp;
    }
    void resetLiveHp(){liveHp = hp;}
    void hpDamage(float damage){liveHp -= damage;}
    int getAtk(void){return atk;}
    int getDef(void){return def;}
    float getLiveHp(void){return liveHp;}

  protected:
    int atk = 1;
    int def = 1;
    int hp = 10;
    float liveHp;
};
#endif