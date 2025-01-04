import random

# Global variables
dice = 0
key = ''
choice = ''
position = 0
newposition = 0
count = 0

def check_position(position):
    global newposition
    if position == 4:
        newposition = 14
        print(f"\nWell done! You landed on a ladder. Now you are on {newposition}.")
    elif position == 9:
        newposition = 31
        print(f"\nWell done! You landed on a ladder. Now you are on {newposition}.")
    elif position == 17:
        newposition = 7
        print(f"\nBad luck! You landed on a snake. Now you are on {newposition}.")
    elif position == 21:
        newposition = 42
        print(f"\nWell done! You landed on a ladder. Now you are on {newposition}.")
    elif position == 46:
        newposition = 13
        print(f"\nBad luck! You landed on a snake. Now you are on {newposition}.")
    elif position == 28:
        newposition = 84
        print(f"\nWow! You landed on a big ladder. Now you are on {newposition}.")
    elif position == 62:
        newposition = 19
        print(f"\nBad luck! You landed on a snake. Now you are on {newposition}.")
    elif position == 37:
        newposition = 61
        print(f"\nWell done! You landed on a ladder. Now you are on {newposition}.")
    elif position == 54:
        newposition = 25
        print(f"\nBad luck! You landed on a snake. Now you are on {newposition}.")
    elif position == 51:
        newposition = 67
        print(f"\nWell done! You landed on a ladder. Now you are on {newposition}.")
    elif position == 87:
        newposition = 36
        print(f"\nBad luck! You landed on a snake. Now you are on {newposition}.")
    elif position == 72:
        newposition = 91
        print(f"\nWell done! You landed on a ladder. Now you are on {newposition}.")
    elif position == 64:
        newposition = 44
        print(f"\nBad luck! You landed on a snake. Now you are on {newposition}.")
    elif position == 80:
        newposition = 23
        print(f"\nOh! You landed on a big snake. Now you are on {newposition}.")
    elif position == 38:
        newposition = 71
        print(f"\nWell done! You landed on a ladder. Now you are on {newposition}.")
    elif position == 95:
        newposition = 75
        print(f"\nBad luck! You landed on a snake. Now you are on {newposition}.")
    elif position == 98:
        newposition = 79
        print(f"\nBad luck! You landed on a snake. Now you are on {newposition}.")
    else:
        newposition = position
    
    return newposition

def main():
    global dice, position, newposition, count, key, choice
    
    # Initial greetings
    print("Would you like to Play the game???(click Y or y if you want)")
    choice = input().strip().lower()

    if choice == 'y' or choice=='Y':
        print(" ### Welcome to Snake and Ladders Game !!!!!        | Rules Are::                             |")
        print("|  100  99  98  97  96  95  94  93  92  91  |       | 1=START                  4=Ladder to 14 |")
        print("|  81   82  83  84  85  86  87  88  89  90  |       | 9=Ladder to 31           17=Snake to 7  |")
        print("|  80   79  78  77  76  75  74  73  72  71  |       | 21=Ladder to 42          46=Snake to 13 |")
        print("|  61   62  63  64  65  66  67  68  69  70  |       | 28=Ladder to 84          62=Snake to 19 |")
        print("|  60   59  58  57  56  55  54  53  52  51  |       | 37=Ladder to 61          54=Snake to 25 |")
        print("|  41   42  43  44  45  46  47  48  49  50  |       | 51=Ladder to 67          87=Snake to 36 |")
        print("|  40   39  38  37  36  35  34  33  32  31  |       | 72=Ladder to 91          64=Snake to 44 |")
        print("|  21   22  23  24  25  26  27  28  29  30  |       | 80=Snake to 23           95=Snake to 75 |")
        print("|  20   19  18  17  16  15  14  13  12  11  |       | 38=Ladder to 71          98=Snake to 79 |")
        print("|  1    2   3   4   5   6   7   8   9   10  |       | 100=END                                 |")
        print("**WINNER WILL BE THE ONE WHO GETS TO 100 FIRST.THAT IS WITH MINIMUM NUMBER OF DICE THROWS..\n")
        
        # Start the game loop
        while position < 100:
            input("\nPress any key to roll the dice\n")
            print("Player rolled a dice.")
            dice = random.randint(1, 6)
            print(f"The number is {dice}.")
            position += dice
            
            # If you roll a 6, you get another chance to roll
            if dice == 6 and position<100:
                newposition = check_position(position)
                position = newposition
                print("\n6 came up! You get another chance to roll.")
                continue
            if dice<=6 and position>100:
                position=position-dice
                print(f"You are still at {dice}.")
                continue
            # Check the position for ladders or snakes
            print(f"\nYou are landed on {position}.")
            count+=1	
            newposition = check_position(position)
            position = newposition

        print(f"\nCONGRATULATIONS, you have won the game in {count} throws!")
    
    else:
        print("\nOK, Go to Another Game!")

if __name__ == "__main__":
    main()
