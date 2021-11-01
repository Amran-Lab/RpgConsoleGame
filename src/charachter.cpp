#include "../include/character.h"

Character::Character(int initPosX,int initPosY,int initAtk,int initDef, int initHp) : Sprite(initPosX,initPosY){
  atk = initAtk;
  def = initDef;
  hp = initHp;
  liveHp = initHp;
}

void Character::resetLiveHp(void){liveHp = hp;}

void Character::hpDamage(float damage){liveHp -= damage;}

int Character::getAtk(void){return atk;}

int Character::getDef(void){return def;}

float Character::getLiveHp(void){return liveHp;}