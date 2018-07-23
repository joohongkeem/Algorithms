#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char arr[51][51];
int x[2501];
int y[2501];
int FRONT, REAR;

int main()
{
	int T,N,M,K;
	int i,j;
	int TOTAL = 0;

	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d %d %d", &M, &N, &K);

		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++) arr[i][j] = '0';
		}

		while(K--)
		{
			int x,y;
			scanf("%d %d", &x,&y);
			arr[y][x] = '1';
		}
		REAR = 0;
		FRONT = 0;
		TOTAL = 0;
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{

				if(arr[i][j] != '1') continue;
				TOTAL ++;

				y[REAR] = i;
				x[REAR] = j;
				REAR++;

				arr[i][j] = '0';


				while(REAR>FRONT)
				{
					if(arr[y[FRONT]-1][x[FRONT]] == '1' && y[FRONT]-1 >= 0)
					{
						y[REAR] = y[FRONT]-1;
						x[REAR] = x[FRONT];
						REAR++;

						arr[y[FRONT]-1][x[FRONT]] = '0';

					}
					if(arr[y[FRONT]+1][x[FRONT]] == '1' && y[FRONT]+1 < N)
					{
						y[REAR] = y[FRONT]+1;
						x[REAR] = x[FRONT];
						REAR++;

						arr[y[FRONT]+1][x[FRONT]] = '0';
					}
					if(arr[y[FRONT]][x[FRONT]-1] == '1' && x[FRONT]-1 >= 0)
					{
						y[REAR] = y[FRONT];
						x[REAR] = x[FRONT]-1;
						REAR++;

						arr[y[FRONT]][x[FRONT]-1] = '0';
					}
					if(arr[y[FRONT]][x[FRONT]+1] == '1' && x[FRONT]+1 < M)
					{
						y[REAR] = y[FRONT];
						x[REAR] = x[FRONT]+1;
						REAR++;

						arr[y[FRONT]][x[FRONT]+1] = '0';
					}
					FRONT++;

				}

			}
		}
		printf("%d\n",TOTAL);
	}





	return 0;
}