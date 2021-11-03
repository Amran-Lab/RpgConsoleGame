# RpgConsoleGame

# Intro

This game took inspiration from console based rpg games before it and a game that I have played previously called pokemon red. The aim of the game is to make your robot which has crash landed on earth to collect gems which you can then use to buy equipment and improve stats. They can also be used to go to the next level and eventually esacape the world and end the game. To make the game more challenging I've added a similar game mechanic from pokemon where you can randomly encounter a monster which you must fight. If you win you gain gems otherwise you lose gems. You can gain more gems from winning if you are on a higher level however the monster will be stronger.

To complete this goal I will be taking on OOP approach, with some functional code as well. I will be using OOP tools such as inheritence, polymorphism, abstraction and encapsulation. I will try and make as many variables private and protected when possible.

## Diagrams And Planning
![Blank diagram (7)](https://user-images.githubusercontent.com/52491921/139874489-cb343e91-6e86-4209-ab47-e4598a7c21de.png)

If you look at the figure on the left you cann see my class diagram. The plan is to have a sprite object acting similaryly to an abstract class in that it doesn't get instantiated. Underneath that would be the gem class and character class. A key differentiating characteristic between them is the character class objects having health and attack atributes among others. The child class of the character class is player. This object would have much more functionality such as the ability to move and keep track of a score. If there are any monsters this would be instantiated with the character class however a player would be instantiated with the player class.

On the right you can see the general logic behind my game. Once the game start the map or board would be printed and the player can interact with the character on the screen through buttons. If it is WASD the player character would move, if not and they pressed M they would get sent to the menu which they can then navigate through.

Below you can see another flow diagram this is an event that would happen at random where the player fights the monster. They get given the option to attack defend and poison. After each round health would be calculated to check if anyone won the fight.

![Blank diagram (10)](https://user-images.githubusercontent.com/52491921/139876890-996e1d57-3993-4c59-8a86-18f6695aac27.png)

## Tasks
### Task Game Board
-   Create Game Loop
-   Create Board Class
-   Print Board
-   Ability to go to game Menu from Board
### Task Player
-   Create Player Class
-   Allow for user input to move Player
-   Print player on board
### Task Gem
-   Create Gem class
-   Print Gem on Board
-   Allow for Player and Gem collisions
-   Track Gems collected and display them
-   Place Gem randomly once collected on Board
### Task Stats
-   Create Stat Menu
-   Display Stats and Stat Menu
-   Create purchase of stats from Stat Menu
### Task Monster
-   Create Monster object
-   Create Monster encounter
-   Create Fight state between Player and Monster
### Task Shop
-   Create Shop to buy Armour and Weapons
-   Allow purchase of items from Shop
### Task Level
-   Create Level Menu
-   Display Level Menu
-   Allow to go to next level
### Task Finishing Touch
-   Start Game and Endgame message
### Task Cleaning
-   Refactor Code

Those are some of the tasks I set out to complete my project.
As you can see I created epic style tasks underneath of which I had goals I would need to accomplish for that task to be completed. For example the player must be able to move and be displayed on the board for that task. Some of these goals or mini tasks can be seen in my code commits.
For example an early commit of [print board](https://github.com/Amran-Lab/RpgConsoleGame/commit/104ab32b58e7e0ac503a5a7dd46eea674a67160d) 
prints the board. However this piece of code was refactored several time later to better fit with future features and to reduce bugs.

# Good Standards

- I used lower camel case for my variables e.g goodStandards
and I used camel case for my structs and classes e.g GoodStandards
- I tried not to reuse code whenever possible to reduce code smells
- Used OOP principles such as inheritence and polymorphism abstaction and ecapsulation
  - Inheritence and polymorphism was done by having a family of classes: sprite,gem,character and player. It can be seen in the diagram
  - Abstraction was done by hiding complexity by declaring function function in the header files and defining them in the src folder and making variables private whenever possible. You can see the encapsulation by the use of getters and setters to access private and protected variables
- Added security by making variables private when possible and limiting global variables when possible
- Tried to use case statements instead of long nested if statements where possible
- Got rid of nested loops by using enums to keep track of state and change the game mode
- Aim for high cohesion and low coupling. I believe I achieved this as for example the sprite class and it's child class are not dependant on the board class.
# Phases Of The Game
## Phase 1
### Aim
The aim of this was to print the board and get the player able
to move around the board and collide with gems to get gems. This [commit](https://github.com/Amran-Lab/RpgConsoleGame/commit/4735de25e3ac4c8454799bdee9e9a700afe6c032) can be seen as the end of phase 1. The board,player and gem are printed with emojis and player can move around the board. Also the player can navigate to the menu screen and then back to the adventure screen.

### How I Did It
Once I created the initial classes and instantiated objects I created the game loop. Here is where the game would be played.
Once in the game loop the board would be rendered followed by the player and gem. Everytime the player made a move the game would be cleared and re-rendered. I also created the option of if the player pressed M or m they would be sent to the Menu loop.

### Code Refactors
One major piece of refactoring I did which affected my throughout the project was removing the Menu while loop.
With the starting approach I would have a main game loop then within that I would have a Menu loop. The plan would be to have other screens such as the Stat Menu having there own loop. However I did not like the idea of having so many nested loops as it would become hard to keep track of and create many problems down the line. To fix this I used an enum as a state maching that told my program what state the game is in. E.g Adventure state, Menu state, Stats state. This change considerably tidied up my code. The change can also be seen in this [commit](https://github.com/Amran-Lab/RpgConsoleGame/commit/4735de25e3ac4c8454799bdee9e9a700afe6c032)

### Tests/Bugs/Fixes
When testing the game I found a bug in this phase. When moving the player a trail would be left behind. For example if the player started at (0,0) moved to (0,1) then (1,1) you would see the player at all three spots. To fix the problem I initialised the board after every move which would clear the old state of the game leaving only the newest state.The fix can be seen in this [commit](https://github.com/Amran-Lab/RpgConsoleGame/commit/eb64662648e9bb08498fea7f364108864b177abc)



| Task        |    How I tested   |  Outcome  | Fix |
| ----------- | ------------ | ----------- |--------|
| Print Board | Ran the game | Printed Board | Null |
| Move Player   | Press WASD | Player moved as intended but left trail | Cleared board after every move |
| Go to Menu   | Press M during Adventure| Went to Menu Screen | Null |
| Go to Adventure   | Press Q during Menu | Went to Adventure screen | Null|
| Gem Collection | Collide with gem | Gained gem/score  | Null |

## Phase 2 MVP
The aim of this stage and which I consider to be the MVP is for the game to be able to enounter a monster, fight the monster, gain gems, open a stats menu, buy stats.

### How I Did It
I instantiated a monster character and then created a function called encounter monster. This function would make you meet a monster given a certain probability if found you would fight that monster. In the fight the player can attack defend and posion the monster. The calulation used would vary depending the move the player makes and the attack and defence of the player and monster. I made the fighting of the monster its own gamestate and once I had created the stats menu I made that it's own gamestate as well. The stats menu would only be accessible through the main menu.

### Code Refactors
One refactor that happened at his stage is my player,monster and gem objects all belonged to one class I refactored it to split it up. This tidied up my code and allowed for use of inheritence and polymorphism to reduce code reusage. The refactor can be seen in this [commit](https://github.com/Amran-Lab/RpgConsoleGame/commit/c5984460d808735da02a8beb8bc850e0f3aadf0d). Another refactor I made was moving my functions which up till that point had been in my main.cpp file and moving it to a src file. This reduced the large amounts of code in that file and abstracted it away. The commit cleaned that cleaned up the code can be found [here](https://github.com/Amran-Lab/RpgConsoleGame/commit/5d12be2230f532c4fe3efe3248929da81147a514).

### Tests/Bugs/Fixes
One bug I found in this stage through testing the game was if certain field such as number of gems or stats were more than 3 digits long it would mess up the formatting.
 E.g | 10 | -> |1000000|. I fixed this by using printf's formatting tool making the text left aligned and taking 8 spaces. This can be seen [here](https://github.com/Amran-Lab/RpgConsoleGame/commit/d624dd9d58f6863176d700bf580aec2aa85d91d3).

| Task        |    How I tested   |  Outcome  | Fix |
| ----------- | ------------ | ----------- |--------|
| Encounter Monster | Ran around the map | Encountered Monster | Null |
| Fight Monster Win | Fought Monster with weaker stats | Won fight and gained gems| Null |
| Fight Monster Lose | Fought stronger Monster |Lost fight and lost gems | Null |
| Go To Stat Menu | Press S during Menu | Displayed Stats | Null |
| Buy Attack | Press 1 during Stat Menu |Increase attack lose 1 gem | Null |
| Buy Defence | Press 2 during Stat Menu |Increase defence lose 1 gem | Null |
| Buy Health | Press 3 during Stat Menu |Increase health lose 1 gem | Null |
| Go to Menu   | Press M during Stat Menu | Went to Menu Screen | Null |
| Go to Adventure   | Press Q during Stat Menu | Went to Adventure screen | Null|
| Buy 100 Attack | Press 1 during Stat Menu 100 times | Format of stats breaks| Left align stats with fixed spacing e.g %-3d would left align and allow for 3 digits without breaking. Repeated for all stats and gem score |

## Phase 3 End
This is what I would call the end stages of my game.
The player can buy armour which affect their performance in battle. They would also be able to use gems to go to the next level and eventually finish the game.

### How I Did It
I created a game state for bot the armour shop and level shop.
For the armour shop I used a structure for each piece of armour and a vector array to contain all the armour. For the level shop I used an enum to keep track of what state or level the game is in. Each level would reward the player differently and give different monsters.

### Code Refactors
I made two major refactors on this stage. The first one being splitting the classes to different files, found [here](https://github.com/Amran-Lab/RpgConsoleGame/commit/8c32d84b96ec3cd4c33fca303726aad6b7f771e6). The second one being declaring the functions in the header files but defining them in the src files. This change can be found [here](https://github.com/Amran-Lab/RpgConsoleGame/commit/369ccba524dc744ea983f6e81b363263607385c2) 

### Tests/Bugs/Fixes
A bug that I found at this stage was that when you increase the players stats or the monster evolves and becomes stronger when you go to the next stage the new hp is not used in the next fight only in the fight after it. The fix can be found [here on line 160](https://github.com/Amran-Lab/RpgConsoleGame/commit/369ccba524dc744ea983f6e81b363263607385c2). It makes sure to reset the live hp to the new hp at the beginning of the battle only. For clarification the hp stat is fixed e.g 300 and the live hp has a maximum of 300 in this case but it can go down, once it goes down to 0 the player loses the battle. After the battle it will now be reset back to 300.

| Task        |    How I tested   |  Outcome  | Fix |
| ----------- | ------------ | ----------- |--------|
| Go to armour shop | Press A during main menu | Displayed armour menu | Null |
| Purchase Armour | Press 1/2/3 for Armour | Armour displayed as bought | Null |
| Fight Monster With Armour | Buy Armour then fight monster | Defeat stronger monster | Null |
| Go to level shop | Press L during main menu | display current level and price for next level | Null |
| Go to next Level | Press Y during level menu | go to next level and lose gems equivalent to cost | Null |
| Fight Monster on next level | Fight monster on level 2 | Monster does not gain healt | reset live hp for player and monster during beginning of fight  |
| End Game | Keep pressing Y during level menu | game ends | Null |

# Evaluation

In the previous step in the phases I mentioned some code smells and refactoring I had to do.
Of the above examples the two that I think made the largest differenes is moving the functions to a seperate file and defining the classes elsewhere. For the first one found [here](https://github.com/Amran-Lab/RpgConsoleGame/commit/5d12be2230f532c4fe3efe3248929da81147a514), it immensely reduced the code in the main file making it more readable and abstracted away some of the logic.
The other example I mentioned was moving the logic of the class functions to the src file. The commit found [here](https://github.com/Amran-Lab/RpgConsoleGame/commit/369ccba524dc744ea983f6e81b363263607385c2) made the classes more readable and maintainable.

Some programming practises I implemented was using OOP and using inheritence, polymorphism and encapsulation. As shown in my class diagram I had a family of classes with sprite having two child classes and character having it's own child class. I also had getters and setter to retrieve my variables that I had declared as private and protected for added security. I also tried to implement as many pure functions as I can, however this proved somewhat difficult on certain functions as it is a console based game there are several functions that must print out an output.

There are several key moments in my development of the project which I believed to be innovative and helpful in creating a good project. One of the first things would be using an enum as a state machine. This allowed me to change game states without having multiple game loops for each state as I was originally doing. This also reduced massively the amount of code I was dealing with because I would not have to precautions to stop and start loops, as well as keep track of them. Another thing that made my game much more comfortable to play was the ability to erase the screen. This simple change made the playing experience much better. It allowed for having a fixed board and displayal of stats below it.
Finally I took care in creating an algorithm that would be enjoyable and balanced when fighting a monster. There are several variables that need to accounted for including the player move that was used against the monster. The code can be found under the fightMonster function. The code below is for when the player chooses to attack.
```
      modifier = (((double) rand() / (RAND_MAX)) + 0.5);
      hitMonster = (playerAtk*1.2 * modifier) - (0.1*MonDef);
      modifier = (((double) rand() / (RAND_MAX)) + 0.5);
      hitPlayer = (MonAtk*1.2 * modifier) - (0.1*playerDef);
      monster.hpDamage(hitMonster*(player.getDamInc() + 1));
      player.hpDamage(hitPlayer*(1-player.getDamReduct()));
```
The modifier acts to create randomness so everyfight is not the same. I have also made it so the player and monster get a different modifier so the randomness is not cancelled out.
After this you can see the player attack is multiplied by 1.2, this is because the player chose to attack so there is an increase in attack power. Finally the attribute of damInc and damReduction are based on the armour and weapons the player has on.

## Review
Overall I believe the project went well, I have completed the MVP and have a fully playable game. If I had to improve some things in a future update I would introduce a roaming monster rather than one that is meant by chance. I would also allow for the player to purchase multiple stat points at once. After this I would make it such that every time you go up another level the biome changes e.g the trees turn into water or rocks to represent the sea or a cave.
