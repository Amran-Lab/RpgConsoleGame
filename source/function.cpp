#include "../include/function.h"
#include "../include/player.h"
#include "../include/board.h"
#include "../include/gamestate.h"
#include <iostream>
#include <fstream>

State gameState = Adventure;
Level level = Lvl_1;

void drawBoard(Board &board,Player &player, Gem &gem){
  char option;
  board.drawItem("\U0001F48E", gem.getPosX(), gem.getPosY());
  board.drawItem("\U0001F916", player.getPosX(), player.getPosY());
  printf("\033c"); // erases previous board
  board.printBoard();
  board.initiliazeBoard(); // resets board - removes previous artifacts
  displayStats(player);
  printf("\n| WASD To move character  M for Menu  |");
  printf("\n+-------------------------------------+\n");
  if (player.getFight() == 1){                    // listener if a fight happens
    printf("|    DEFEATED MONSTER - GAIN 3 GEMS   |");
    printf("\n+-------------------------------------+\n");
    player.fightOutcome(0);
  }
  else if (player.getFight() ==2){
    printf("|  DIED TO THE MONSTER - LOSE 1 GEMS  |");
    printf("\n+-------------------------------------+\n");
    player.fightOutcome(0);
  }

  cin >> option;
  if ((toupper(option) == 'M')){
    gameState = Menu;
  }
  else if ((toupper(option) == 'W') || (toupper(option) == 'A') || (toupper(option) == 'S') || (toupper(option) == 'D')){
    player.movePlayer(option);
    if (gem.collision(player.getPosX(), player.getPosY())){
      player.upScore(1);
      printf("You Gained A Gem\n");
    }
    encounterMonster(player);
  }
}

void drawMenu(Player &player){
  printf("\033c");
  displayStats(player);
  char option;
  printf("\n| Press A to change Weapon and Armour |");
  printf("\n+-------------------------------------+");
  printf("\n|     Press S to Increase Stats       |");
  printf("\n+-------------------------------------+");
  printf("\n|           Pres Q to quit:           |");
  printf("\n+-------------------------------------+\n");
  cin >> option;
  switch(option) {
    case 'A':
    case 'a':
      gameState = Items;
      break;
    case 'S':
    case 's':
      gameState = Stats;
      break;
    case 'Q':
    case 'q':
      gameState = Adventure;
      break;
    default:
      break;
  }
}
void displayStats(Player &player){
  printf("+-------------------------------------+");
  printf("\n|           Number Of Gems: %-5d     |", player.getScore());
  printf("\n+-------------------------------------+");
  printf("\n| Health: %d | Attack: %d | Defence: %d |",player.getHp(),player.getAtk(),player.getDef());
  printf("\n+-------------------------------------+");
}

void statMenu(Player &player){
  char option;
  printf("\033c");
  displayStats(player);
  printf("\n|     Spend Gems to increase stats    |");
  printf("\n+-------------------------------------+");
  printf("\n|     Press 1 to Increase Attack      |");
  printf("\n+-------------------------------------+");
  printf("\n|     Press 2 to Increase Defence     |");
  printf("\n+-------------------------------------+");
  printf("\n|     Press 3 to Increase Health      |");
  printf("\n+-------------------------------------+");
  printf("\n|  Press M for Menu or Q to Adventure |");
  printf("\n+-------------------------------------+\n");
  cin >> option;
  switch(option) {
    case 'M':
    case 'm':
      gameState = Menu;
      break;
    case 'Q':
    case 'q':
      gameState = Adventure;
      break;
    case '1':
      player.upAtk();
      break;
    case '2':
      player.upDef();
      break;
    case '3':
      player.upHp();
      break;
    default:
      break;
  }
}

bool encounterMonster(Player &player){
  int chance = (rand() % 100) + 1;
  if (chance <= 60){
    
    //string myText;
    //std::ifstream f("ascii.txt");
    //if (f.is_open())
      //  std::cout << f.rdbuf();
    printf("\033c");
    displayStats(player);
    printf("\n|   You Encountered A Monster: FIGHT  |");
    printf("\n+-------------------------------------+");
    gameState = Fighting;
    return true;
  }
  return false;
}

void fightMonster(Player &player, Character &monster){
  float playerHp = player.getLiveHp();
  int playerDef = player.getDef();
  int playerAtk = player.getAtk();

  float MonHp = monster.getLiveHp();
  int MonAtk = monster.getAtk();
  int MonDef = monster.getDef();

  float modifier;
  float hitMonster,hitPlayer;
  char option;

  printf("\n|         Player Health | %-8.2f    |",player.getLiveHp());
  printf("\n+-------------------------------------+");
  printf("\n|        Monster Health | %-8.2f    |",monster.getLiveHp());
  printf("\n+-------------------------------------+");
  printf("\nPress 1 to Attack");
  printf("\nPress 2 to Defend");
  printf("\nPress 3 to Poison");
  cin >> option;
  printf("\n+-------------------------------------+");
  switch(option) {
    case '1':
      modifier = (((double) rand() / (RAND_MAX)) + 0.5); // 0.5 < r < 1.5
      hitMonster = (playerAtk*1.2 * modifier) - (0.1*MonDef);
      modifier = (((double) rand() / (RAND_MAX)) + 0.5);
      hitPlayer = (MonAtk*1.2 * modifier) - (0.1*playerDef);
      monster.hpDamage(hitMonster);
      player.hpDamage(hitPlayer);
      printf("\n|      Player Got Hit With | %-8.2f |",hitPlayer);
      printf("\n+-------------------------------------+");
      printf("\n|     Monster Got Hit With | %-8.2f |",hitMonster);
      printf("\n+-------------------------------------+");

      break;
    case '2':
      modifier = (((double) rand() / (RAND_MAX)) + 0.5);
      hitMonster = (playerDef*0.9 * modifier)  - (0.1*MonDef);
      modifier = (((double) rand() / (RAND_MAX)) + 0.5);
      hitPlayer = (MonAtk*1.2 * modifier) -(0.4*playerDef);
      monster.hpDamage(hitMonster);
      player.hpDamage(hitPlayer);
      printf("\n| Player Reduced Damage of | %-8.2f |",hitPlayer);
      printf("\n+-------------------------------------+");
      printf("\n|  Monster Hit With Recoil | %-8.2f |",hitMonster);
      printf("\n+-------------------------------------+");

      break;
    case '3':
      modifier = (((double) rand() / (RAND_MAX)) + 0.5);
      hitPlayer = (MonAtk*1.2 * modifier) - (0.1*playerDef);
      player.hpDamage(hitPlayer);
      printf("\n|      Player Got Hit With | %-8.2f |",hitPlayer);
      printf("\n+-------------------------------------+");
      player.addPoison(3);
      break;
    default:
      break;
  }
  if (player.downPoison()) {
      monster.hpDamage(1);
      printf("\n|   Monster Poisoned Loses 1 Health   |");
      printf("\n+-------------------------------------+");
  }
printf("\n+-------------------------------------+");
  if (player.getLiveHp() <= 0){
    player.downScore(1);
    player.fightOutcome(2);   // Player Loss
    player.resetPoison();
    player.resetLiveHp();   // Reset HP
    monster.resetLiveHp();
    gameState = Adventure;
  }

  else if (monster.getLiveHp() <= 0){
    player.upScore(3);       // More Gems
    player.fightOutcome(1); // Player Win
    player.resetPoison();   // reset Poison Counter
    player.resetLiveHp();   // Reset HP
    monster.resetLiveHp();
    gameState = Adventure;
  } 
}
void displayShop(void){
  string buy;
  string increaseMessage;
  string sign;
  for(Armour armour : shopItems){
    if(armour.bought){buy = "Bought";} else{buy ="Buy: " + to_string(armour.cost);}
    if(armour.armour){
      increaseMessage = "% damage recieved";
      sign = "-";
    } else {
      increaseMessage = "% damage dealt";
      sign = "+";
    }
    printf("\n%s %s%d%s %s",armour.armourName.c_str(),sign.c_str(),armour.increase,increaseMessage.c_str(),buy.c_str());
  }
  for (int i = 0; i!=shopItems.size(); i++){
    printf("\nPress %d for %s",i+1,shopItems[i].armourName.c_str());
  }
  printf("\nOr Press M for Menu or Q to Adventure");
}
void pickItem(Player &player,char option){
    switch(option) {
    case '1':
      if(!shopItems[0].bought){
        if (player.downScore(20)){
          shopItems[0].bought = true;
        }
      }
      break;
    case '2':
      if(!shopItems[1].bought){
        if (player.downScore(shopItems[1].cost)){
          shopItems[1].bought = true;
        }
      }
      break;
    case '3':
      if(!shopItems[2].bought){
        if (player.downScore(shopItems[2].cost)){
          shopItems[2].bought = true;
        }
      }
      break;
    case '4':
      if(!shopItems[3].bought){
        if (player.downScore(shopItems[3].cost)){
          shopItems[3].bought = true;
        }
      }
      break;
    case '5':
      if(!shopItems[4].bought){
        if (player.downScore(shopItems[4].cost)){
          shopItems[4].bought = true;
        }
      }
      break;
    case '6':
      if(!shopItems[5].bought){
        if (player.downScore(shopItems[5].cost)){
          shopItems[5].bought = true;
        }
      }
      break;
    case '7':
      if(!shopItems[6].bought){
        if (player.downScore(shopItems[6].cost)){
          shopItems[6].bought = true;
        }
      }
      break;
    case 'M':
    case 'm':
      gameState = Menu;
      break;
    case 'Q':
    case 'q':
      gameState = Adventure;
      break;
    default:
      break;
  }
}