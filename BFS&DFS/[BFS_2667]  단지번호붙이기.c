#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


char arr[26][26];
int N;
int x[625];
int y[625];
int COUNT[314];
int FRONT, REAR;


//void show(void)				// 배열과 Queue의 진행을 확인
//{
//	int i, j;
//	puts("------------------");
//	for(i=0;i<N;i++)
//	{
//		for(j=0;j<N;j++)
//		{
//			printf("%c",arr[i][j]);
//		}
//		puts("");
//	}
//	printf("FRONT = %d & REAR = %d \n", FRONT,REAR);
//	for(i=0;i<=REAR;i++)printf("%3d",x[i]);
//	puts("");
//	for(i=0;i<=REAR;i++)printf("%3d",y[i]);
//	puts("");
//	for(i=0;i<=FRONT;i++)printf("%3d",x[i]);
//	puts("");
//	for(i=0;i<=FRONT;i++)printf("%3d",y[i]);
//	puts("");
//}

int main()
{
	int i,j;
	int TOTAL = 0;
	

	scanf("%d",&N);

	for(i=0;i<N;i++)
	{
		scanf("%s",&arr[i][0]);
	}
	

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			
			if(arr[i][j] != '1') continue;
			TOTAL ++;
			
			y[REAR] = i;
			x[REAR] = j;
			REAR++;
			
			COUNT[TOTAL]++;
			arr[i][j] = '0';


			while(REAR>FRONT)
			{
				if(arr[y[FRONT]-1][x[FRONT]] == '1' && y[FRONT]-1 >= 0)
				{
					y[REAR] = y[FRONT]-1;
					x[REAR] = x[FRONT];
					REAR++;
					COUNT[TOTAL]++;
					arr[y[FRONT]-1][x[FRONT]] = '0';
					
				}
				if(arr[y[FRONT]+1][x[FRONT]] == '1' && y[FRONT]+1 < N)
				{
					y[REAR] = y[FRONT]+1;
					x[REAR] = x[FRONT];
					REAR++;
					COUNT[TOTAL]++;
					arr[y[FRONT]+1][x[FRONT]] = '0';
				}
				if(arr[y[FRONT]][x[FRONT]-1] == '1' && x[FRONT]-1 >= 0)
				{
					y[REAR] = y[FRONT];
					x[REAR] = x[FRONT]-1;
					REAR++;
					COUNT[TOTAL]++;
					arr[y[FRONT]][x[FRONT]-1] = '0';
				}
				if(arr[y[FRONT]][x[FRONT]+1] == '1' && x[FRONT]+1 < N)
				{
					y[REAR] = y[FRONT];
					x[REAR] = x[FRONT]+1;
					REAR++;
					COUNT[TOTAL]++;
					arr[y[FRONT]][x[FRONT]+1] = '0';
				}
				FRONT++;
				//show();
			}

		}
	}
	printf("%d\n",TOTAL);
	for(i=1;i<=TOTAL;i++)
	{
		int min = 0x7FFFFFFF;
		int minidx;
		for(j=1;j<=TOTAL;j++)
		{
			if(COUNT[j] < min) 
			{
				min = COUNT[j];
				minidx = j;
			}
		}
		printf("%d\n",min);
		COUNT[minidx] = 0x7FFFFFFF;
	}


	return 0;
}