#include <iostream>
#include "../include/constants.h"
#include "../include/sprite.h"
#include "../include/character.h"
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H

class Player: public Character {

  private:
    int fightState = 0;  // 0 = NoFight 1 = Won, 2= Loss
    int score = 800;      // number of gems/score
    int poisonCounter = 0; // poisons monster every round if >0
    float damReduct = 0.00; // damage modifier decrease
    float damInc = 0.00; // damage increase modifier
    int gemMultiplier = 1; // increases number of gems earned per fight and collection

  public:
    Player(int initPosX,int initPosY,int initAtk,int initDef, int initHp);

    void movePlayer(char option);

    int getHp(void);

    void upAtk(void);

    void upDef(void);

    void upHp(void);
    
    void upScore(int plus);

    bool downScore(int minus);

    int getScore(void);
    
    void fightOutcome(int state);

    int getFight(void);
    
    void addPoison(int poison);

    bool downPoison(void);

    void resetPoison(void);

    float getDamReduct(void);

    float getDamInc(void);

    void setDamReduct(float red);

    void setDamInc(float inc);

    int getMulitplier(void);

    void setMulitplier(int value);
};
#endif