import random

def play_game():
    player_throw = 0
    comp_throw = 0
    opi = input("Would you like to play the game? (Y/N): ").strip()

    if opi.lower() == 'y':
        while True:
            print("\nSelect your throw:")
            print("1) Rock")
            print("2) Paper")
            print("3) Scissors")
            print("4) Exit")
            try:
                player_throw = int(input("Selection: "))
            except ValueError:
                print("Invalid input, please choose a number between 1 and 4.")
                continue

            if player_throw == 1:
                print("\nPlayer throws ROCK.")
            elif player_throw == 2:
                print("\nPlayer throws PAPER.")
            elif player_throw == 3:
                print("\nPlayer throws SCISSORS.")
            elif player_throw == 4:
                print("Exiting the game.")
                break
            else:
                print("Invalid selection! Please choose a number between 1 and 4.")
                continue

            comp_throw = random.randint(1, 3)
            if comp_throw == 1:
                print("\nComputer throws ROCK.")
            elif comp_throw == 2:
                print("\nComputer throws PAPER.")
            elif comp_throw == 3:
                print("\nComputer throws SCISSORS.")

            # Determine winner
            if player_throw == 1 and comp_throw == 3:
                print("\nROCK beats SCISSORS. You WIN.\n")
            elif player_throw == 1 and comp_throw == 2:
                print("\nPAPER beats ROCK. You LOSE.\n")
            elif player_throw == 3 and comp_throw == 2:
                print("\nSCISSORS beats PAPER. You WIN.\n")
            elif player_throw == 3 and comp_throw == 1:
                print("\nROCK beats SCISSORS. You LOSE.\n")
            elif player_throw == 2 and comp_throw == 1:
                print("\nPAPER beats ROCK. You WIN.\n")
            elif player_throw == 2 and comp_throw == 3:
                print("\nSCISSORS beats PAPER. You LOSE.\n")
            elif player_throw == comp_throw:
                print("\nIt's a Draw.\n")
    else:
        print("\nOkay! Goodbye and thank you for playing.")

if __name__ == "__main__":
    play_game()
