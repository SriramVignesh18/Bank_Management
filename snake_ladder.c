#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BOARD_SIZE 100
#define BOARD_DIM 10
#define TILE_SIZE 3

int dice;
char key,choice;
int checkposition(),position,newposition,count=0;

#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define WHITE_COLOR "\033[37m"

void displayBoard() {
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
            if (num == 4 || num == 9 || num == 21 || num == 28 || num == 38 || num == 51 || num == 72) {
                // Ladders (Green)
                printf(GREEN_COLOR "%3d " RESET_COLOR, num);
            } else if (num == 17 || num == 46 || num == 62 || num == 54 || num == 64 || num == 80 || num == 95 || num == 98) {
                // Snakes (Red)
                printf(RED_COLOR "%3d " RESET_COLOR, num);
            } else if (num == position) {
                // Current player position (Yellow)
                printf(YELLOW_COLOR "%3d " RESET_COLOR, num);
            } else {
                // Empty spaces (White)
                printf(WHITE_COLOR "%3d " RESET_COLOR, num);
            }
        }
        printf("\n");
    }
    printf("\n");
} 

int main()
{
	srand(time(0));
	printf("Would you like to Play the game?(Click Y or y if you want)\n\n");
	scanf("%s",&choice);
	if(choice=='Y' || choice=='y')
	{
		displayBoard();
		printf("**WINNER WILL BE THE ONE WHO GETS TO 100 FIRST.THAT IS WITH MINIMUM NUMBER OF DICE THROWS..\n");
		
		do
		{
			printf("\n\nPress any key to roll the dice\n\n");
			scanf("%s",&key);
			printf("The dice is rolled\n");
			dice=(rand()%6)+1;
			printf("The Number is %d",dice);
			position+=dice;
			if(dice==6 && position<100)
			{
				checkposition();
				position=newposition;
				displayBoard();
				printf("\n6 came upto here You will get one more chance..");
				continue;
			}
			if(position>100 && dice<=6)
			{
				position=position-dice;
				displayBoard();
				printf("You are still at %d",position);
				continue;
			}
			printf("\nYou are landed on %d.\n",position);
			count++;
			checkposition();
			position=newposition;
			displayBoard();
		}while(position<100);
		printf("\nCONGRATULATIONS,You have won the game in %d throws",count);
	}
	else
	{
		printf("\nOK Go to Another Game!!");
		return 1;
	}
	return 0;
}
int checkposition()
{
	switch(position)
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
		case 37:
			   newposition=61;
			   printf("\nWell done you are landed on a ladder.Now you are on %d",newposition);
			   break;
		case 54:
			   newposition=25;
			   printf("\nBad Luck you are landed on a snake.Now you are on %d",newposition);
			   break;
		case 51:
			   newposition=67;
			   printf("\nWell done you are landed on a ladder.Now you are on %d",newposition);
			   break;
		case 87:
			   newposition=36;
			   printf("\nBad Luck you are landed on a snake.Now you are on %d",newposition);
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
			return newposition=position;
			break;
	    
	}
	return 0;
} 
