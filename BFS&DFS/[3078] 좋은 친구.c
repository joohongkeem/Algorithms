#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[300001];
int count[21];
unsigned long long int ANS;
int REAR=0,FRONT=0;

int main()
{
	int i,j, N, K;
	
	scanf("%d %d",&N,&K);
	
	for(i=1;i<=N;i++)
	{
		char temp[22];
		scanf("%s",temp);
		arr[i] = strlen(temp);
	}
	for(i=1;i<=N;i++)
	{
		if(i>1+K)
		{
			count[arr[++FRONT]]--;
		}
		//if(i+K>N) break;
		count[arr[++REAR]]++;
		ANS += count[arr[REAR]] - 1;

	}
	printf("%llu\n",ANS);
}