#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void generateRandomPassword(int N);

int main()
{
	int N;
	printf("Enter the range number for password\n");
	scanf("%d",&N);
	generateRandomPassword(N);
	return 0;
} 

void generateRandomPassword(int N)
{
	int random = 0;
	
	srand((unsigned int)(time(NULL)));
	
	char numbers[10] = "0123456789";
	char symbols[8] = "!@#$^&*?";
    char letter[26] = "abcdefghijklmnoqprstuvwyzx";
    char LETTER[26] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
	
	char password[N];
	
	random = rand() % 4;
	
	for(int i=0; i<N; i++)
	{
		if(random==1)
		{
			password[i] = numbers[rand()%10];
			random = rand() % 4;
			printf("%c",password[i]);
		}
		else if(random==2)
		{	
		    password[i] = symbols[rand()%8];
			random = rand() % 4;
			printf("%c",password[i]);
		}
		else if(random==3)
		{
			password[i] = letter[rand()%26];
			random = rand() % 4;
			printf("%c",password[i]);
		}
		else
		{
			password[i] = LETTER[rand()%26];
			random = rand() % 4;
			printf("%c",password[i]);	
		}
	}
}