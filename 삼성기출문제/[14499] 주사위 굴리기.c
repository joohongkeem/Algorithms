#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int N,M;
int board[22][22];


struct dice{
	char nowR;
	char nowC;
	
	char bottom_val;
	char up_val;
	char east_val;
	char west_val;
	char north_val;
	char south_val;
};
typedef struct dice DICE;

void makingboard(DICE *dice);

void movingwest(DICE * dice)
{
	char temp;
	if(dice->nowC-1 < 0) return;

	
	
	dice->nowC -= 1;
	
	temp = dice->west_val;
	dice->west_val = dice->up_val;
	dice->up_val = dice->east_val;
	dice->east_val = dice->bottom_val;
	dice->bottom_val= temp;

	makingboard(dice);
}
void movingeast(DICE * dice)
{
	char temp;
	if(dice->nowC+1 >= M) return;

	dice->nowC += 1;

	temp = dice->east_val;
	dice->east_val = dice->up_val;
	dice->up_val = dice->west_val;
	dice->west_val = dice->bottom_val;
	dice->bottom_val = temp;

	makingboard(dice);
}
void movingnorth(DICE * dice)
{
	char temp;
	if(dice->nowR-1 < 0) return;

	
	
	dice->nowR -= 1;
	
	temp = dice->north_val;
	dice->north_val = dice->up_val;
	dice->up_val = dice->south_val;
	dice->south_val = dice->bottom_val;
	dice->bottom_val = temp;

	makingboard(dice);
}
void movingsouth(DICE * dice)
{
	char temp;
	if(dice->nowR+1 >= N) return;

	
	
	dice->nowR += 1;
	
	temp = dice->bottom_val;
	dice->bottom_val=dice->south_val;
	dice->south_val = dice->up_val;
	dice->up_val = dice->north_val;
	dice->north_val= temp;

	makingboard(dice);
}

void makingboard(DICE *dice)
{
	if(board[dice->nowR][dice->nowC] == 0)
	{
		board[dice->nowR][dice->nowC] = dice->bottom_val;
	}
	else
	{
		dice->bottom_val = board[dice->nowR][dice->nowC];
		board[dice->nowR][dice->nowC] = 0;
	}
	printf("%d\n",dice->up_val);
}
int main()
{
	int x,y,K,i,j;
	DICE A={0,0,0,0,0,0,0,0};

	scanf("%d %d %d %d %d",&N,&M,&x,&y,&K);
	A.nowR = x;
	A.nowC = y;


	for(i=0;i<N;i++)
		for (j=0;j<M;j++) 
			scanf("%d",&board[i][j]);
	
	for(i=1; i<=K; i++)
	{
		int command;
		scanf("%d",&command);
		
		switch(command)
		{

		case 1:
			movingeast(&A);
			break;
		case 2:
			movingwest(&A);
			break;
		case 3:
			movingnorth(&A);
			break;
		case 4:
			movingsouth(&A);
			break;
		}

	}

}