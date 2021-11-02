# RpgConsoleGame
Making a c++ console game

## Intro

This game took inspiration from consol based rpg games before it and a game that I have played previously called pokemon red. The aim of the game is to make your robot which has crash landed on earth to collect gems which you can then use to buy equipment and improve stats. They can also be used to go to the next level and eventually esacape the world and end the game. To make the game more challenging I've added a similar game mechanic from pokemon where you can randomly encounter a monster which you must fight. If you win you gain gems otherwise you lose gems. You can gain more gems from winning if you are on a higher level however the monster will be stronger.

To complete this goal I will be taking on OOP approach, with some functional code as well.

## Section 1 - Diagrams And Planning
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

## Phase 1
Player can move on the screen and collect gems

### How I Did It
I first created the board and player

### Code Refactors
Game Loop and Enum States

### Tests/Bugs/Fixes
Trailing Character

### Other
Some Stuff Happened

## Phase 2 MVP
Player can increase stats and fight monsters

### How I Did It
I first created the board and player

### Code Refactors
Game Loop and Enum States

### Tests/Bugs/Fixes
Text Formatting when Gems/Stats > 3 characters

### Other
Some Stuff Happened

## Phase 3 End
Player can buy armour go to next level and end game using gems.

### How I Did It
I first created the board and player

### Code Refactors
Game Loop and Enum States

### Tests/Bugs/Fixes
Live Stats not increased when stats are increased

### Other
Some Stuff Happened
