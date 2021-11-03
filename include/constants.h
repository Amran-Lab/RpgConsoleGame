#include <vector>
#ifndef GAMESTATE_H
#define GAMESTATE_H
// Game State
enum State { Adventure, Menu, Stats, Items, Fighting, ChangeLevel, EndGame};
// Level State
enum Level { level_1 = 1, level_2 = 20, level_3 = 100, level_4 = 300, end_game = 100000};
// Armour properties 
struct Armour{
  std::string armourName;
  bool armour;
  int increase;
  int cost;
  bool bought;
};
// Global used throughout code
extern State gameState;
// Golbal used throughout game
extern Level level;
// Constant and used in multiple place
extern std::vector<Armour> shopItems;

#endif