### **Minesweeper Game**

### Introduction:
This is a simple implementation of the classic Minesweeper game in C++. The game allows players to uncover cells on a grid while avoiding mines. The objective is to uncover all cells without detonating any mines.

### Features
Three difficulty levels:
 Easy
 Medium
 Hard.
Dynamic grid size based on the selected difficulty level.
Random placement of mines for each game.
Interactive gameplay with user input.

### How to Play
Run the program.
Choose the difficulty level (0 for Easy, 1 for Medium, 2 for Hard).
The game will generate a grid with mines placed randomly.
Enter your moves by providing the coordinates (x, y) of the cell you want to uncover.
Avoid uncovering cells with mines.
The game ends when all safe cells are uncovered or when a mine is detonated.

### Difficulty Levels:
###### Easy: 9x9 grid with 10 mines.
###### Medium: 16x16 grid with 40 mines.
###### Hard: 24x24 grid with 99 mines.

### Compiling and Running
Ensure you have a C++ compiler installed. Compile the code using the following commands:

bash
Copy code
#### g++ minesweeper.cpp -o minesweeper
Run the compiled executable:

bash
Copy code
./minesweeper
