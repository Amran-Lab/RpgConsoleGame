#include "../include/sprite.h"
#include "../include/gem.h"
#include "../include/character.h"
#include "../include/function.h"
#include "../include/player.h"
#include "../include/board.h"
#include "../include/constants.h"
#include <iostream>
#include <fstream>
#include <string>

State gameState = Adventure;

Level level = level_1;

std::vector<Armour> shopItems = {{"Full Helm",true,5,25,false},{"Platebody",true,10,25,false},{"Platelegs",true,12,25,false},{"Kiteshield",true,5,25,false},{"Iron Sword",false,5,25,false},{"Mithril Sword",false,10,100},{"Adamant Sword",false,40,500,false}};

void drawBoard(Board &board,Player &player, Gem &gem){
  char option;
  board.drawItem("\U0001F48E", gem.getPosX(), gem.getPosY()); // puts gem on board
  board.drawItem("\U0001F916", player.getPosX(), player.getPosY()); // puts player on board
  printf("\033c"); // erases previous board
  board.printBoard(); // prints new board
  board.initializeBoard(); // resets board - removes previous artifacts
  displayStats(player);
  printf("\n| WASD To move character  M for Menu  |");
  printf("\n+-------------------------------------+\n");
  if (player.getFight() == 1){                    // listener if a fight happens
    printf("|  DEFEATED MONSTER - GAIN %-5d GEMS |",player.getMulitplier()*3);
    printf("\n+-------------------------------------+\n");
    player.fightOutcome(0);
  }
  else if (player.getFight() ==2){                // If player just lost a fight
    printf("|  DIED TO THE MONSTER - LOSE 1 GEMS  |");
    printf("\n+-------------------------------------+\n");
    player.fightOutcome(0);
  }

  cin >> option;
  if ((toupper(option) == 'M')){  // Go To Menu
    gameState = Menu;
  }
  else if ((toupper(option) == 'W') || (toupper(option) == 'A') || (toupper(option) == 'S') || (toupper(option) == 'D')){
    player.movePlayer(option);  // Move Player
    // Checks For Gem Collection
    if (gem.collision(player.getPosX(), player.getPosY())){
      player.upScore(1);
    }
    encounterMonster(player);
  }
}
// Draw Main Menu And Navigate to Other Menus
void drawMenu(Player &player){
  printf("\033c");
  displayStats(player);
  char option;
  printf("\n| Press A to change Weapon and Armour |");
  printf("\n+-------------------------------------+");
  printf("\n|     Press S to Increase Stats       |");
  printf("\n+-------------------------------------+");
  printf("\n|       Pres L to Change Level        |");
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
    case 'L':
    case 'l':
      gameState = ChangeLevel;
      break;
    default:
      break;
  }
}
// Draw Stats
void displayStats(Player &player){
  printf("+-------------------------------------+");
  printf("\n|           Number Of Gems: %-7d   |", player.getScore());
  printf("\n+-------------------------------------+");
  printf("\n| Health:%-4d| Attack:%-3d| Defence:%-3d|",player.getHp(),player.getAtk(),player.getDef());
  printf("\n+-------------------------------------+");
  printf("\n|         Damage Reduction| %3.2g%%      |",player.getDamReduct()*100);
  printf("\n+-------------------------------------+");
  printf("\n|          Damage Increase| %3.2g%%      |", 
  player.getDamInc()*100);
  printf("\n+-------------------------------------+");
}
// Stat Menu
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
// Chance Encounter With a Monster
bool encounterMonster(Player &player){
  int chance = (rand() % 100) + 1;
  if (chance <= 25){
    
    printf("\033c");
    displayStats(player);
    printf("\n|   You Encountered A Monster: FIGHT  |");
    printf("\n+-------------------------------------+");
    gameState = Fighting;
    return true;
  }
  return false;
}
// Fight Algorithm
void fightMonster(Player &player, Character &monster){
  // resets player and monster to full health if it is beginning of fight
  if (player.getFight() == 0){
    player.resetPoison();   // reset Poison Counter
    player.resetLiveHp();   // Reset HP
    monster.resetLiveHp();  // reset Monster
    player.fightOutcome(1);
  }
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
      modifier = (((double) rand() / (RAND_MAX)) + 0.5); // 0.5 < modifier < 1.5 - introduces randomness
      hitMonster = (playerAtk*1.2 * modifier) - (0.1*MonDef);
      modifier = (((double) rand() / (RAND_MAX)) + 0.5);
      hitPlayer = (MonAtk*1.2 * modifier) - (0.1*playerDef);
      monster.hpDamage(hitMonster*(player.getDamInc() + 1));
      player.hpDamage(hitPlayer*(1-player.getDamReduct()));
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
      monster.hpDamage(hitMonster*(player.getDamInc() + 1));
      player.hpDamage(hitPlayer*(1-player.getDamReduct()));
      printf("\n| Player Reduced Damage of | %-8.2f |",hitPlayer);
      printf("\n+-------------------------------------+");
      printf("\n|  Monster Hit With Recoil | %-8.2f |",hitMonster);
      printf("\n+-------------------------------------+");

      break;
    case '3':
      modifier = (((double) rand() / (RAND_MAX)) + 0.5);
      hitPlayer = (MonAtk*1.2 * modifier) - (0.1*playerDef);
      player.hpDamage(hitPlayer*(1-player.getDamReduct()));
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
    player.fightOutcome(2);   // Outcome On Player Loss
    gameState = Adventure;
  }

  else if (monster.getLiveHp() <= 0){
    player.upScore(3);       // Gain Gems
    player.fightOutcome(1); // Change Outcome on Player Win
    gameState = Adventure;
  } 
}
// Display Shop
void displayShop(void){
  string buy;
  string increaseMessage;
  string sign;
  int i = 1;
  for(Armour armour : shopItems){
    if(armour.bought){buy = "Bought";} else{buy ="Buy: " + to_string(armour.cost);}
    if(armour.armour){
      increaseMessage = "% damage recieved";
      sign = "-";
    } else {
      increaseMessage = "% damage dealt";
      sign = "+";
    }
    if(armour.bought){
      printf("\n|%d|%s %s%d%s Bought",i,armour.armourName.c_str(),sign.c_str(),armour.increase,increaseMessage.c_str());
    } else{
      printf("\n|%d|%s %s%d%s Buy: %d",i,armour.armourName.c_str(),sign.c_str(),armour.increase,increaseMessage.c_str(),armour.cost);
    }
    i++;
  }
  printf("\n+-------------------------------------+");
  printf("\n| Press Corresponding Number for Item |");
  printf("\n+-------------------------------------+");
  printf("\n|  Press M for Menu or Q to Adventure |");
  printf("\n+-------------------------------------+\n");
}
// Buy Item/Armour
std::string pickItem(Player &player,char option){
  float increase;
  if ((toupper(option) == 'M')){
    gameState = Menu;
    return "Return To Menu\n";
  }
  else if ((toupper(option) == 'Q')){
    gameState = Adventure;
    return "Return To Adventure\n";
  }
  std::string s(1, option);
  int number = std::atoi(s.c_str());  // Char to Int
  if((number >0) && (number-1<shopItems.size())){
    if(!shopItems[number-1].bought){  // Checks if Item is Bought
        // Tries to Purchase Item
        if (player.downScore(shopItems[number-1].cost)){
          shopItems[number-1].bought = true;  // Change Item Status
          increase = shopItems[number-1].increase / 100.00;
          // Checks if Armour or Weapon And Applies Increase
          shopItems[number-1].armour ? player.setDamReduct(increase) : player.setDamInc(increase) ;
          return "|              Item Bought            |\n+-------------------------------------+\n";
        }
        return "|            Not Enough Gem           |\n+-------------------------------------+\n";
    }
    return "|         Item Already Bought         |\n+-------------------------------------+\n";
  }
  return "|       No Valid Input Try Again      |\n+-------------------------------------+\n";  // Validation
}
// Display Level Menu
std::string drawLevel(Player &player,Character &monster){
  char option;
  printf("\033c");
  displayStats(player);
  showLevel(player);
  printf("\npress Y for yes and N for No: ");
  cin >> option;
  if ((toupper(option) == 'Y')){
    if(nextLevel(player,monster)){
      return "\nBought";
    }
    return "\nNot Enough Gems";
  }
  gameState = Menu;
  return "";
}
// Show Current Level
void showLevel(Player &player){
  printf("\nCurrent Gem Multiplier %d",player.getMulitplier());
  switch(level) {
    case level_1:
      printf("\nYou Are in Level 1\nPay %d Gems to go to Level 2",Level::level_2);
      break;
    case level_2:
      printf("\nYou Are in Level 2\nPay %d Gems to go to Level 3",Level::level_3);
      break;
    case level_3:
        printf("\nYou Are in Level 3\nPay %d Gems to go to Level 4",Level::level_4);
      break;
    case level_4:
      printf("\nYou Are in Level 4\nPay %d Gems to fix the ship and end the game",Level::end_game);
      break;
    default:
      break;
  }
}
// Try to purchase Next Level
bool nextLevel(Player &player,Character &monster){
  switch(level) {
    case level_1:
      if(player.downScore(Level::level_2)){
        level = level_2;
        player.setMulitplier(10);
        monster = Character(0,0,10,10,100);
        return true;
      }
      return false;
      break;
    case level_2:
      if(player.downScore(Level::level_3)){
        level = level_3;
        player.setMulitplier(100);
        monster = Character(0,0,50,50,300);
        return true;
      }
      return false;
      break;
    case level_3:
      if(player.downScore(Level::level_4)){
        level = level_4;
        player.setMulitplier(1000);
        monster = Character(0,0,80,80,900);
        return true;
      }
      return false;
      break;
    case level_4:
      if(player.downScore(Level::end_game)){
        level = end_game;
        gameState = EndGame;
        player.setMulitplier(1);
        monster = Character(0,0,5,5,50);
        return true;
      }
      return false;
      break;
    case end_game:
      level = level_1;
      gameState = Adventure;
      return true;
      break;
    default:
      break;
  }
}