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

  // encounterMonster();
  cin >> option;
  if ((toupper(option) == 'M')){
    gameState = Menu;
  }
  else if ((toupper(option) == 'W') || (toupper(option) == 'A') || (toupper(option) == 'S') || (toupper(option) == 'D')){
    player.movePlayer(option);
    if (gem.collision(player.getPosX(), player.getPosY())){
      player.upScore();
      printf("You Gained A Gem\n");
    }
    if(encounterMonster()){
          fightMonster(player);
    }
  }
}

void drawMenu(Player &player){
  printf("\033c");
  printf("Number of Gems: %d", player.getScore());
  char option;
  printf("\nPress A to change Weapon and Armour");
  printf("\nPress S to Increase Stats ");
  printf("\nPres Q to quit: ");
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
  printf("\n|           Number Of Gems: %d         |", player.getScore());
  printf("\n+-------------------------------------+");
  printf("\n| Health: %d | Attack: %d | Defence: %d |",player.getHp(),player.getAtk(),player.getDef());
  printf("\n+-------------------------------------+");
}

void statMenu(Player &player){
  char option;
  printf("\033c");
  displayStats(player);
  printf("\nSpend Gems to increase stats");
  printf("\nPress 1 to Increase Attack");
  printf("\nPress 2 to Increase Defence");
  printf("\nPress 3 to Increase Health");
  printf("\nPress M for Menu or Q to Adventure: ");
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

bool encounterMonster(void){
  int chance = (rand() % 100) + 1;
  if (chance <= 40){
    printf("\nYou Encountered A Monster: FIGHT");
    //string myText;

    // Read from the text file
    //std::ifstream f("ascii.txt");

    // Use a while loop together with the getline() function to read the file line by line
    //if (f.is_open())
      //  std::cout << f.rdbuf();
    return true;
  }
  return false;
}

void fightMonster(Player &player){
  float playerHp = player.getHp();
  int playerDef = player.getDef();
  int playerAtk = player.getAtk();
  float MonHp = level * 20;
  int MonAtk = level * 5;
  int MonDef = level * 1;
  int poisonCounter = 0;
  float modifier;
  float hitMonster,hitPlayer;
  char option;
  while((playerHp > 0) && (MonHp > 0)){
    printf("\nPlayer Health: %.2f",playerHp);
    printf("\nMonster Health: %.2f",MonHp);
    printf("\nPress 1 to Attack");
    printf("\nPress 2 to Defend");
    printf("\nPress 3 to Poison");
    cin >> option;
    printf("\n------------------");
    switch(option) {
      case '1':
        modifier = (((double) rand() / (RAND_MAX)) + 0.5); // 0.5 < r < 1.5
        hitMonster = playerAtk*1.2 * modifier;
        modifier = (((double) rand() / (RAND_MAX)) + 0.5);
        hitPlayer = MonAtk*1.2 * modifier;
        MonHp -= hitMonster;
        playerHp -= hitPlayer;
        printf("\nPlayer Got Hit With %.2f",hitPlayer);
        printf("\nMonster Got Hit With %.2f",hitMonster);

        break;
      case '2':
        modifier = (((double) rand() / (RAND_MAX)) + 0.5);
        hitMonster = playerDef*0.2 * modifier;
        modifier = (((double) rand() / (RAND_MAX)) + 0.5);
        hitPlayer = MonAtk*0.75 * modifier;
        MonHp -= hitMonster;
        playerHp -= hitPlayer;
        printf("\nPlayer Defend majority of Attack You Recieve Hit of %.2f",hitPlayer);
        printf("\nMonster Got Hit With Recoil Of %.2f",hitMonster);

        break;
      case '3':
        modifier = (((double) rand() / (RAND_MAX)) + 0.5);
        hitPlayer = MonAtk*1.2 * modifier;
        playerHp -= hitPlayer;
        printf("\nPlayer Got Hit With %.2f",hitPlayer);
        poisonCounter += 3;
        break;
      default:
        break;
    }
    if (poisonCounter > 0) {
      poisonCounter--;
      MonHp -= 1;
      printf("\nMonster Poisoned Loses 1 Health");
    }
  }
  if (playerHp>0){
    player.upScore();
    player.upScore();
    player.upScore();
    player.fightOutcome(1);
  }
  else{
    player.downScore();
    player.fightOutcome(2);
  }
  
}