#ifndef GAMESTATE_H
#define GAMESTATE_H

enum State { Adventure, Menu, Stats, Items, Fighting};
enum Level { Lvl_1 = 1, Lvl_2 = 5, Lvl_3 = 20, Lvl_4 = 100};
extern State gameState;
extern Level level;

#endif