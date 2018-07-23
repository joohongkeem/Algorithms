#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

char ANS1[10][10];
char ANS2[10][10];
char board[52][52];


int checking(char (*ans)[10], char (*board)[52], int x, int y)
{
	int count = 0;
	int i, j;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
		{
			if( ans[1+i][1+j] != board[x+i][y+j] ) count ++;
		}

	return count;

}

int min(int a, int b)
{
	if(a>b) return b;
	else return a;
}


int main()
{
	int i,j;
	int N,M;
	int ANS = 0x7FFFFFFF;
	int temp1, temp2;
	scanf("%d %d", &N, &M);	
	for(i=1;i<=N;i++) scanf("%s", &board[i][1]);


	for(i=1;i<=8;i++) 
		for(j=1;j<=8;j++) 
		{
			if( (i+j)%2 == 0 )
			{
				ANS1[i][j] = 'W';
				ANS2[i][j] = 'B';
			}
			else
			{
				ANS1[i][j] = 'B';
				ANS2[i][j] = 'W';
			}
		}
	
	
	for(i=1; i+7<=N; i++)
	{
		for(j=1; j+7<=M; j++)
		{
			temp1 = checking(ANS1, board, i, j);
			temp2 = checking(ANS2, board, i, j);
			ANS = min( ANS, temp1 );
			ANS = min( ANS, temp2 );
		}
	}
	
	printf("%d\n",ANS);

}