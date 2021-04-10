#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin();
void board(char name1[],char name2[]);
int main()
{
	hi:
    int player = 1, i, choice;
    char c;
    
    char mark,pl1[10],pl2[10],select[10];
    system("COLOR FC");
    printf("\nEnter Player 1 name : ");
    gets(pl1);
    printf("Enter Player 2 name : ");
    gets(pl2);
    do
    {
        board(pl1,pl2);//passing argument to board//
        player = player % 2;
        if(player==1)
        {for(i=0;i<10;i++) // for altering the player name on the board //
            {
                select[i]=pl1[i];
            }
        }
        else
        {for(i=0;i<10;i++)
            {
                select[i]=pl2[i];
            }
        }
        printf("%s, enter a number:  ", select);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1') //marking with X and O by alternating the players in the board//
            square[1] = mark;
            
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
            
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
            
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
            
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
            
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
            
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
            
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
            
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
            
        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = checkwin();
        player++;
    }while (i ==  -1); 
    
    board(pl1,pl2);
    
    if (i == 1) //for win condition of printing which player have won the game//
        {
            if(player!=1)
            printf("==>%s wins the game! congratulations!!! ",pl1);
            else
            printf("==>%s wins the game! congratulations!!! ",pl2);
        }
    else //print for draw condition //
        printf("==>\aoops! its a draw");
		printf("do you wanna play again:y/n");
		scanf("%c",&c);
		if(c=="y")
		goto hi;
    	getch();

    	return 0;
}

/*
FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
*/

int checkwin() //  win condition //
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}


/*
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK

*/


void board(char name1[],char name2[]) //printing the board and displaying the choices of the players//
{
    system("cls");
    printf("\n\n\t WELCOME\n\n");
    printf("\n\n\tTic Tac Toe\n\n");
    printf("%s ->(X)  -  %s -> (O)\n\n\n",name1,name2);

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
 
}

/*
END
*/
