#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[501];
int LIS[501];
int LDS[501];


int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}


int main()
{
	int N;
	int i,j;
	int LIS_MAX = 0;
	scanf("%d",&N);
	
	for(i=1;i<=N;i++)
	{
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		arr[t1] = t2;
	}

	for(i=1;i<=500;i++) 
	{
		LIS[i] = 1;
	}

	for(i=2;i<=500;i++)
	{
		if(arr[i] == 0) continue;
		for(j=1;j<i;j++)
		{
			if(arr[j] == 0) continue;
			if(arr[i] > arr[j]) LIS[i] = max(LIS[i], LIS[j]+1);
		}
	}

	for(i=1;i<=500;i++)
	{
		if(LIS[i] > LIS_MAX) LIS_MAX = LIS[i];
	}
	printf("%d\n",N-LIS_MAX);
	

	return 0;
}