# Snake & Ladder's Game
In this Project,A simple game implementation was done.
# How to Play:
1) The player is prompted whether they want to play.
2) The player rolls a dice by pressing any key. The dice roll determines the number of steps they move forward.
3) If they land on a snake, they move backwards; if they land on a ladder, they move forwards.
4) The goal is to reach position 100 as quickly as possible.
# Key Points to Note:
1) Input/Output: In C, there are scanf and printf for input and output, respectively. In Python, input() is used for getting user input and print() for displaying messages.
2) Random Dice Rolls: In C, rand() is used to generate random numbers, while in Python, random.randint(1, 6) is the equivalent.
3) Game Loop: The game loop continues while the player's position is less than 100. The player's position updates based on the dice roll and the ladder or snake positions.
4) Ladders and Snakes: The check_position() function in Python handles updating the player's position if they land on a ladder or snake.
5) Throw Counting: The game tracks the number of dice throws. However, rolls of 6 do not count towards the throw count. Additionally, if a player's position exceeds 100 after a dice roll, that throw is not counted. But, if you are on 94 then you rolled 6,then that throw is counted.
