#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int generateRandomNum(int a)
{
	srand(time(NULL));
	return rand() % a;
}

int greater(char ch1, char ch2)
{
	if(ch1==ch2)
	{
		return 1;
	}
	else if(ch1 == 'R'&& ch2 == 'P')
	{
		return 1;
	}
	else if(ch1 == 'P'&& ch2 == 'R')
	{
		return 0;
	}
	else if(ch1 == 'R'&& ch2 == 'S')
	{
		return 1;
	}
        else if(ch1 == 'S'&& ch2 == 'R')
	{
		return 0;
	}
	else if(ch1 == 'P'&& ch2 == 'S')
	{
		return 1;
	}
	else if(ch1 == 'S'&& ch2 == 'P')
	{
		return 0;
	}
}

int main()
{
	char player1, Computer;
	int player1Score = 0, ComputerScore =0;
	int temp;
	char out[] = {'R','P','S'};
	for(int i=0; i<3; i++)
	{
	    printf("\nPlayer1's turn\n");
	    printf("Enter the number between 1 to 3:\n");
	    scanf("%d", &temp);
	    player1 = out[temp-1];
	    printf("Entered character by player 1 is %c\n",player1);
	    
	    printf("\nComputer's turn\n");
	    temp = generateRandomNum(3) + 1;
	    Computer = out[temp-1];
	    printf("Computer selected %c\n",Computer);  
	    
	if(greater(player1, Computer)==1)
        {
    	    player1Score +=1;
    	    printf("You got it!\n");
	}
	else if(greater(player1, Computer)==-1)
	{
	    ComputerScore +=1;
	    player1Score +=1;
	    printf("It's draw!\n");
	}
	else
	{
	    ComputerScore +=1;
	    printf("Computer got it!\n");	
	}
	    
	printf("You score %d and Computer Score %d\n",player1Score,ComputerScore);  
	    
    }
       
	if(player1Score>ComputerScore)
	{
	     printf("Congratulations! Hurray! You Won the game!\n");
	}
	else if(player1Score<ComputerScore)
	{
	     printf("Computer Won! Better luck next time\n");
	}
	else 
	     printf("It's draw\n");
	    
	return 0;
} 
