import random

# Constants
BOARD_DIM = 10
RESET_COLOR = "\033[0m"
RED_COLOR = "\033[31m"
GREEN_COLOR = "\033[32m"
YELLOW_COLOR = "\033[33m"
WHITE_COLOR = "\033[37m"

# Global variables
position = 0
newposition = 0
count = 0
dice = 0
key = ''
choice = ''

def display_board():
    board = [[(i * BOARD_DIM) + (j + 1) for j in range(BOARD_DIM)] for i in range(BOARD_DIM)]

    print("\n### Snake and Ladder Board ###")
    for i in range(BOARD_DIM - 1, -1, -1):
        for j in range(BOARD_DIM):
            num = board[i][j]
            if num == 4 or num == 9 or num == 21 or num == 28 or num == 38 or num == 51 or num == 72:
                # Ladders (Green)
                print(GREEN_COLOR + f"{num:3} " + RESET_COLOR, end="")
            elif num == 17 or num == 46 or num == 62 or num == 54 or num == 64 or num == 80 or num == 95 or num == 98:
                # Snakes (Red)
                print(RED_COLOR + f"{num:3} " + RESET_COLOR, end="")
            elif num == position:
                # Current player position (Yellow)
                print(YELLOW_COLOR + f"{num:3} " + RESET_COLOR, end="")
            else:
                # Empty spaces (White)
                print(WHITE_COLOR + f"{num:3} " + RESET_COLOR, end="")
        print("\n")
    print("\n")

def check_position():
    global newposition
    if position == 4:
        newposition = 14
        print(f"\nWell done you are landed on a ladder. Now you are on {newposition}")
    elif position == 9:
        newposition = 31
        print(f"\nWell done you are landed on a ladder. Now you are on {newposition}")
    elif position == 17:
        newposition = 7
        print(f"\nBad Luck you are landed on a snake. Now you are on {newposition}")
    elif position == 21:
        newposition = 42
        print(f"\nWell done you are landed on a ladder. Now you are on {newposition}")
    elif position == 46:
        newposition = 13
        print(f"\nBad Luck you are landed on a snake. Now you are on {newposition}")
    elif position == 28:
        newposition = 84
        print(f"\nWow!!! you are landed on a Big ladder. Now you are on {newposition}")
    elif position == 62:
        newposition = 19
        print(f"\nBad Luck you are landed on a snake. Now you are on {newposition}")
    elif position == 37:
        newposition = 61
        print(f"\nWell done you are landed on a ladder. Now you are on {newposition}")
    elif position == 54:
        newposition = 25
        print(f"\nBad Luck you are landed on a snake. Now you are on {newposition}")
    elif position == 51:
        newposition = 67
        print(f"\nWell done you are landed on a ladder. Now you are on {newposition}")
    elif position == 87:
        newposition = 36
        print(f"\nBad Luck you are landed on a snake. Now you are on {newposition}")
    elif position == 72:
        newposition = 91
        print(f"\nWell done you are landed on a ladder. Now you are on {newposition}")
    elif position == 64:
        newposition = 44
        print(f"\nBad Luck you are landed on a snake. Now you are on {newposition}")
    elif position == 80:
        newposition = 23
        print(f"\nOh! you are landed on a Big snake. Now you are on {newposition}")
    elif position == 38:
        newposition = 71
        print(f"\nWell done you are landed on a ladder. Now you are on {newposition}")
    elif position == 95:
        newposition = 75
        print(f"\nBad Luck you are landed on a snake. Now you are on {newposition}")
    elif position == 98:
        newposition = 79
        print(f"\nBad Luck you are landed on a snake. Now you are on {newposition}")
    else:
        newposition = position

def main():
    global position, count
    random.seed()
    
    choice = input("Would you like to Play the game?(Click Y or y if you want)\n\n")
    
    if choice.lower() == 'y' or 'Y':
        display_board()
        print("**WINNER WILL BE THE ONE WHO GETS TO 100 FIRST. THAT IS WITH MINIMUM NUMBER OF DICE THROWS..\n")

        while position < 100:
            input("\n\nPress any key to roll the dice\n\n")
            print("The dice is rolled")
            dice = random.randint(1, 6)
            print(f"The Number is {dice}")
            position += dice

            if dice == 6 and position < 100:
                check_position()
                position = newposition
                display_board()
                print("\n6 came upto here. You will get one more chance..")
                continue
            
            if position > 100:
                position -= dice
                display_board()
                print(f"You are still at {position}")
                continue

            print(f"\nYou are landed on {position}.\n")
            count += 1
            check_position()
            position = newposition
            display_board()

        print(f"\nCONGRATULATIONS, You have won the game in {count} throws")
    
    else:
        print("\nOK Go to Another Game!!")

if __name__ == "__main__":
    main()
