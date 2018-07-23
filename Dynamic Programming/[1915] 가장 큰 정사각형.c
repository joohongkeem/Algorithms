#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char board[1002][1002];
short dp[2][1001];
int MAX = 0;

#define max(x,y) ((x)>(y) ? (x) : (y))
#define min(x,y) ((x)>(y) ? (y) : (x))



int main()
{
	int N,M;
	int i,j;
	int MIN;

	scanf("%d %d",&N,&M);

	for(i=1;i<=N;i++) for(j=1;j<=M;j++) scanf("%1d", &board[i][j]);
	
	for(j=1;j<=M;j++) 
	{ 
		if(board[1][j] == 1) {dp[0][j] = 1; MAX = 1;}
	}

	for(i=2;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			if(board[i][j] != 0)
			{
				if(board[i-1][j-1] ==0 || board[i-1][j] ==0|| board[i][j-1]==0 )
					dp[1][j] = 1;
				else
				{
					MIN = min(dp[0][j-1],min(dp[0][j],dp[1][j-1]));

					dp[1][j] = MIN+1;
					MAX = max(dp[1][j],MAX); 
				}
			}
		}

		for(j=1;j<=M;j++) dp[0][j] = dp[1][j];
	}


	printf("%d\n",MAX*MAX);
	return 0;

}