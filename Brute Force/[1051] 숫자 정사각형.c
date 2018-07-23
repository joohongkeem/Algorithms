#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

char board[52][52];

int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}



int main()
{
	int i,j,k;
	int minvalue;
	int N,M;
	int ANS = 1;
	
	scanf("%d %d", &N, &M);	
	for(i=1;i<=N;i++) scanf("%s", &board[i][1]);

	minvalue = -max(-N,-M);

	for(k=minvalue-1 ; k>=1; k--)
	{
		for(i=1;i+k<=N;i++)
		{
			for(j=1;j+k<=M;j++)
			{
				if(board[i][j] != board[i][j+k]) continue;
				if(board[i][j] != board[i+k][j]) continue;
				if(board[i][j] != board[i+k][j+k]) continue;

				printf("%d\n", (k+1)*(k+1));
				return 0;
			}
		}
	}

	printf("%d\n",ANS);

}