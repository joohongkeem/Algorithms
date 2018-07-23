#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int arr[100001];
int max[100001];

int main()
{
	int N,i=1,j,temp,ANS = 0;
	
	scanf("%d",&N);

	for(i=1;i<=N;i++)
	{
		scanf("%d",&arr[i]);
	}

	
	for(i=1;i<=N;i++)
	{
		if(arr[i] == 0) continue;
		max[i] = arr[i];
		temp = arr[i];
		for(j=i+1;j<=N;j++)
		{
			if(arr[i]>arr[j]) break;
			max[i] += temp;
		}
		for(j=i-1;j>=1;j--)
		{
			
			if(arr[i]>arr[j]) break;
			max[i] += temp;
		}

	}

	for(i=1;i<=N;i++)
		ANS = ANS<max[i] ? max[i] : ANS;

	printf("%d\n",ANS);
	return 0;
}