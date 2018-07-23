#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[1001][1001];
int x[1000001];
int y[1000001];
int FRONT=1, REAR=1;

int main()
{
	int N,M,i,j;
	int zero_count=0;

	scanf("%d %d", &M, &N);

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j] == 0) zero_count++;
			else if(arr[i][j] == -1) continue;
			else
			{
				y[REAR] = i;
				x[REAR] = j;		// 배열 인덱스 맞추기위해 x,y 반대로
				REAR++;
				arr[i][j] = 1;
			}
		}
	}
	if(zero_count == 0)
	{
		puts("0");
		return 0;
	}

	while(FRONT<REAR)
	{


		if(arr[y[FRONT]-1][x[FRONT]] == 0 && y[FRONT]-1 >= 1)
		{
			y[REAR] = y[FRONT] -1;
			x[REAR] = x[FRONT];
			arr[y[FRONT]-1][x[FRONT]]= arr[y[FRONT]][x[FRONT]] + 1;
			zero_count--;
			REAR++;

		}
		if(arr[y[FRONT]+1][x[FRONT]] == 0 && y[FRONT]+1 <=N)
		{
			y[REAR] = y[FRONT] +1;
			x[REAR] = x[FRONT];
			arr[y[FRONT]+1][x[FRONT]] = arr[y[FRONT]][x[FRONT]] + 1;
			zero_count--;
			REAR++;

		}
		if(arr[y[FRONT]][x[FRONT]-1] == 0 && x[FRONT]-1 >=1)
		{
			y[REAR] = y[FRONT];
			x[REAR] = x[FRONT]-1;
			arr[y[FRONT]][x[FRONT]-1] = arr[y[FRONT]][x[FRONT]] + 1;
			zero_count--;
			REAR++;

		}
		if(arr[y[FRONT]][x[FRONT]+1] == 0 && x[FRONT]+1 <=M)
		{
			y[REAR] = y[FRONT];
			x[REAR] = x[FRONT]+1;
			arr[y[FRONT]][x[FRONT]+1] = arr[y[FRONT]][x[FRONT]] + 1;
			zero_count--;
			REAR++;
		}


		FRONT++;
	}



	if(zero_count != 0) puts("-1");
	else
	{
		int max =0;
		for(i=1;i<=N;i++)
			for(j=1;j<=M;j++)
				max = max < arr[i][j] ? arr[i][j] : max; 
		printf("%d\n",max-1);
	}




	return 0;
}