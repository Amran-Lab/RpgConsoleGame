
#include "../include/player.h"
Player::Player(int initPosX,int initPosY,int initAtk,int initDef, int initHp) : 
  Character(initPosX,initPosY,initAtk,initDef,initHp){}

void Player::movePlayer(char option){
  switch(option) {
    case 'W':
    case 'w':
      if (posY > 0){
        posY--;
      }
      break;
    case 'A':
    case 'a':
      if (posX > 0){
        posX--;
      }
      break;
      break;
    case 'S':
    case 's':
      if (posY < 9){
        posY++;
      }
      // code block
      break;
    case 'D':
    case 'd':
      if (posX < 9){
        posX++;
      }
      break;
    default:
      printf("Incorrect Input");
      
  }
}

int Player::getHp(void){return hp;}

void Player::upAtk(void){
  if (score > 0){atk++;
  score--;
  }
  else{
    printf("Not Enough Gems");
  }
}
void Player::upDef(void){
  if (score > 0){
    score--;
    def++;
  }
  else{
    printf("Not Enough Gems");
  }
}

void Player::upHp(void){
  if (score > 0){
    score--;
    hp++;
  }
  else{
    printf("Not Enough Gems");
  }
}
  
void Player::upScore(int plus){score += plus*gemMultiplier;}

bool Player::downScore(int minus){
  if ((score - minus)>= 0 ){
    score -=minus;
    return true;
  }
  return false;
}

int Player::getScore(void){return score;}

void Player::fightOutcome(int state){fightState = state;}

int Player::getFight(void){return fightState;}

void Player::addPoison(int poison){poisonCounter += poison;}

bool Player::downPoison(void){
  if (poisonCounter > 0){
    poisonCounter--;
    return true;
  }
  return false;
}

void Player::resetPoison(void){poisonCounter=0;}

float Player::getDamReduct(void){return damReduct;}

float Player::getDamInc(void){return damInc;}

void Player::setDamReduct(float red){damReduct += red;}

void Player::setDamInc(float inc){damInc += inc;}

int Player::getMulitplier(void){return gemMultiplier;}

void Player::setMulitplier(int value){gemMultiplier = value;}