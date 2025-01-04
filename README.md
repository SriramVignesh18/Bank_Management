# Snake and Ladder Game (C Program)
This is a simple implementation of the classic Snake and Ladder game written in C. The player rolls a dice and moves on the board based on the roll outcome. The objective is to reach the 100th square, with some squares containing ladders to climb up and snakes to slide down.
# Features:
1) Snake and Ladder Mechanics: The board contains snakes and ladders that change the player's position.
2) Dice Rolling: The player rolls a dice to move forward. If they roll a 6, they get an additional chance to roll again.
3) Game Ending: The game ends when the player reaches or exceeds position 100.
# Game Rules:
a) Start: The game begins at square 1.
b) Objective: Reach the 100th square first.
c) Movement: Players roll a dice (1-6) and move forward by the number rolled.
d) Ladders: If you land on a ladder's start position, you climb up to the ladder's end position.
e) Snakes: If you land on a snake's mouth, you slide down to the snake's tail.
f) Rolling a 6: If you roll a 6, you get another turn.
g) Exceeding 100: If your move causes you to go beyond square 100, you remain in the same position.
h) Counting Throws: Each dice throw is counted. However, throws of 6 are not counted toward the total throws. Additionally, if a player's position exceeds 100 after a roll, that throw is not counted either.
# How to Play:
1) Download or clone the repository.
2) Compile the C program using your preferred C compiler (e.g., gcc).
3) Run the compiled program to start playing.
4) Follow the on-screen instructions to roll the dice and play the game.
# Code Details:
a) Board Representation: The board is represented as a 10x10 grid of numbers from 1 to 100.
b) Position Handling: If the player lands on a ladder, their position is updated to the top of the ladder. If they land on a snake, they slide down to the tail of the snake.
c) Dice Mechanics: The dice is rolled using rand(). The result is a random number between 1 and 6. If the roll is a 6, the player gets an extra chance to roll again.
d) Throw Counting: The game tracks the number of dice throws. However, rolls of 6 do not count towards the throw count. Additionally, if a player's position exceeds 100 after a dice roll, that throw is not counted.
# Color Definitions:
We've defined some ANSI color escape codes using #define macros for better readability:
a) RESET_COLOR → Resets the text color back to default.
b) RED_COLOR → For snakes (bad spots).
c) GREEN_COLOR → For ladders (good spots).
d) YELLOW_COLOR → For the player's current position.
e) WHITE_COLOR → For all other grid positions.
# Display Function (displayBoard):
Each grid square is colored differently based on its content:
1) Ladders (Green): Positions like 4, 9, 21, etc.
2) Snakes (Red): Positions like 17, 46, 62, etc.
3) Current Position (Yellow): The player's current position.
4) Empty Squares (White): All other squares.
