#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char board[21][101][101];
int N;
int startx,starty,endx,endy;
char LASTBOARD[101][101];

void makingboard(int c,int t)
{
	int i,j,tx,ty;
	
	for(i=0;i<=100;i++)
		for(j=0;j<=100;j++)
		{
			if(board[c][i][j]!=0 && board[c][i][j] <= t)
			{
				if(board[c][endy-endx+j][endx+endy-i]==0)board[c][endy-endx+j][endx+endy-i]=t+1;
				// 여기서 if문 조건을 안주면, 
				// 기존에 한단계 더 진행해야 할 점을 빠뜨리게 될 수 있다.
		
			}
		}

	tx = endx;
	ty = endy;
	endx = tx+ty-starty;
	endy = ty-tx+startx;
}

int main()
{
	int x,y,d,g,i,j,n,t;
	int COUNT = 0;

	scanf("%d",&N);

	for(n=1;n<=N;n++)
	{
		scanf("%d %d %d %d", &x,&y,&d,&g);
		
		board[n][y][x] = 1;		// start point
		startx = x;
		starty = y;
		switch(d)
		{
		case 0:
			board[n][y][x+1] = 1;	// end point
			endx=x+1;
			endy=y;
			break;
		case 1:
			board[n][y-1][x] = 1;
			endx=x;
			endy=y-1;
			break;
		case 2:
			board[n][y][x-1] = 1;
			endx=x-1;
			endy=y;
			break;
		case 3:
			board[n][y+1][x] = 1;
			endx=x;
			endy=y+1;
			break;

		}
		t=1;
		while(g--) {makingboard(n,t++);}
		
		for(i=0;i<=100;i++)
			for(j=0;j<=100;j++)
				if(board[n][i][j]!=0)
					LASTBOARD[i][j] = 1;
	}

	for(i=0;i<=99;i++)
		for(j=0;j<=99;j++)
			if(LASTBOARD[i][j] != 0 && LASTBOARD[i+1][j] != 0 && LASTBOARD[i][j+1] != 0 && LASTBOARD[i+1][j+1]!=0)
				COUNT++;

	printf("%d\n",COUNT);
	return 0;
}