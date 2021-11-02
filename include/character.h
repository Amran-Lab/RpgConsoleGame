#include <iostream>
#include "../include/sprite.h"
using namespace std;
#ifndef CONSTANTS_H
#define CONSTANTS_H

class Character: public Sprite {
  public:
    Character(int initPosX,int initPosY,int initAtk,int initDef, int initHp);
    void resetLiveHp(void); // Used During Fights - At Start liveHp=Hp
    void hpDamage(float damage);
    int getAtk(void);
    int getDef(void);
    float getLiveHp(void);

  protected:
    int atk = 1;
    int def = 1;
    int hp = 10;
    float liveHp;
};
#endif