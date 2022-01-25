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
		
		if(c== 'y' || c== 'Y')
		goto hi;
    	getch();

    	return 0;
}

/*
END
*/
