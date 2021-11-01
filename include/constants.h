#include <vector>
#ifndef GAMESTATE_H
#define GAMESTATE_H

enum State { Adventure, Menu, Stats, Items, Fighting, ChangeLevel, EndGame};

enum Level { level_1 = 1, level_2 = 20, level_3 = 100, level_4 = 300, end_game = 100000};

struct Armour{
  std::string armourName;
  bool armour;
  int increase;
  int cost;
  bool bought;
};
extern State gameState;
extern Level level;
extern std::vector<Armour> shopItems;

#endif