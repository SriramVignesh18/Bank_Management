#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 100
#define BOARD_DIM 10
#define TILE_SIZE 3
#define MAX_PLAYERS 4

int dice, choice;
int positions[MAX_PLAYERS];  // Array to store positions of players
char key;
int checkposition(int player);
int newposition, count[MAX_PLAYERS];  // Array to count number of turns for each player

#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define WHITE_COLOR "\033[37m"

void displayBoard(int num_players) {
    int i, j;
    int board[BOARD_DIM][BOARD_DIM];

    // Fill the board array (10x10 grid with values 1 to 100)
    for (i = 0; i < BOARD_DIM; i++) {
        for (j = 0; j < BOARD_DIM; j++) {
            board[i][j] = (i * BOARD_DIM) + (j + 1);
        }
    }

    // Print the board in reverse (from 100 to 1)
    printf("\n### Snake and Ladder Board ###\n");
    for (i = BOARD_DIM - 1; i >= 0; i--) {
        for (j = 0; j < BOARD_DIM; j++) {
            int num = board[i][j];
            int is_player_position = 0;
            int p;
            // Check if any player is on this position
            for (p = 0; p < num_players; p++) {
                if (positions[p] == num) {
                    printf(YELLOW_COLOR "%3d " RESET_COLOR, num);
                    is_player_position = 1;
                    break;
                }
            }

            if (!is_player_position) {
                if (num == 4 || num == 9 || num == 21 || num == 28 || num == 38 || num == 51 || num == 72) {
                    // Ladders (Green)
                    printf(GREEN_COLOR "%3d " RESET_COLOR, num);
                } else if (num == 17 || num == 46 || num == 62 || num == 54 || num == 64 || num == 80 || num == 95 || num == 98) {
                    // Snakes (Red)
                    printf(RED_COLOR "%3d " RESET_COLOR, num);
                } else {
                    // Empty spaces (White)
                    printf(WHITE_COLOR "%3d " RESET_COLOR, num);
                }
            }
        }
        printf("\n");
    }
    printf("\n");
} 

int main()
{
	srand(time(0));
	int num_players;

    printf("Welcome to Snake and Ladder!\n");
    printf("Enter the number of players (max 4): ");
    scanf("%d", &num_players);
    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    // Initialize players' positions and turn counts
    int i;
    for (i = 0; i < num_players; i++) {
        positions[i] = 0;  // All players start at position 0
        count[i] = 0;      // All players start with 0 turns
    }

    printf("**WINNER WILL BE THE ONE WHO GETS TO 100 FIRST.THAT IS WITH MINIMUM NUMBER OF DICE THROWS..\n");

    int current_player = 0;
	printf("Would you like to Play the game?(Click Y or y if you want)\n\n");
	scanf("%s",&choice);
	if(choice=='Y' || choice=='y')
	{
		displayBoard(num_players);
		
		do
		{
			printf("\nPlayer %d's turn. Press any key to roll the dice.\n", current_player + 1);
			scanf("%s",&key);
			printf("The dice is rolled\n");
			dice=(rand()%6)+1;
			printf("The Number is %d",dice);
			positions[current_player]+=dice;
			if(dice==6 && positions[current_player]<100)
			{
				checkposition(current_player);
				positions[current_player]=newposition;
				displayBoard(num_players);
				printf("\n6 came upto here You will get one more chance..");
				continue;
			}
			if(positions[current_player]>100 && dice<=6)
			{
				positions[current_player]-=dice;
				displayBoard(num_players);
				printf("You are still at %d",positions[current_player]);	
			}
			printf("\nYou are landed on %d.\n",positions[current_player]);
			count[current_player]++;
			checkposition(current_player);
			positions[current_player]=newposition;
			displayBoard(num_players);
			if(positions[current_player]==100){
				printf("\nCONGRATULATIONS! Player %d has won the game in %d throws.\n", current_player + 1, count[current_player]);
				break;
			}
			current_player = (current_player + 1) % num_players;
		}while(positions[current_player]<100);	
	}
	else
	{
		printf("\nOK Go to Another Game!!");
		return 1;
	}
	return 0;
}
int checkposition(int player)
{
	switch(positions[player])
	{
		case 4:
			   newposition=14;
			   printf("\nWell done you are landed on a ladder.Now you are on %d",newposition);
			   break;
		case 9:
			   newposition=31;
			   printf("\nWell done you are landed on a ladder.Now you are on %d",newposition);
			   break;
		case 17:
			   newposition=7;
			   printf("\nBad Luck you are landed on a snake.Now you are on %d",newposition);
			   break;
		case 21:
			   newposition=42;
			   printf("\nWell done you are landed on a ladder.Now you are on %d",newposition);
			   break;
		case 46:
			   newposition=13;
			   printf("\nBad Luck you are landed on a snake.Now you are on %d",newposition);
			   break;
		case 28:
			   newposition=84;
			   printf("\nWow!!! you are landed on a Big ladder.Now you are on %d",newposition);
			   break;
		case 62:
			   newposition=19;
			   printf("\nBad Luck you are landed on a snake.Now you are on %d",newposition);
			   break;
		case 54:
			   newposition=25;
			   printf("\nBad Luck you are landed on a snake.Now you are on %d",newposition);
			   break;
		case 51:
			   newposition=67;
			   printf("\nWell done you are landed on a ladder.Now you are on %d",newposition);
			   break;
		case 72:
			   newposition=91;
			   printf("\nWell done you are landed on a ladder.Now you are on %d",newposition);
			   break;
		case 64:
			   newposition=44;
			   printf("\nBad Luck you are landed on a snake.Now you are on %d",newposition);
			   break;
		case 80:
			   newposition=23;
			   printf("\nOh! you are landed on a Big snake.Now you are on %d",newposition);
			   break;
		case 38:
			   newposition=71;
			   printf("\nWell done you are landed on a ladder.Now you are on %d",newposition);
			   break;
		case 95:
			   newposition=75;
			   printf("\nBad Luck you are landed on a snake.Now you are on %d",newposition);
			   break;
		case 98:
			   newposition=79;
			   printf("\nBad Luck you are landed on a snake.Now you are on %d",newposition);
			   break;
		default:
			return newposition=positions[player];
			break;
	    
	}
	return 0;
}