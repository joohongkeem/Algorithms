#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int cost[101];
int memory[101];
int N,M;
int MIN = 0x7FFFFFFF;

int dp[10001]={0};
int min(int a, int b)
{
	if(a>b) return b;
	else return a;
}

int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	int i,j,k;


	scanf("%d %d",&N,&M);
	for(i=1;i<=N;i++) scanf("%d",&memory[i]);
	for(i=1;i<=N;i++) scanf("%d",&cost[i]);
	
	for(i=1;i<=N*100;i++) dp[i] = 0x7FFFFFFF;
	dp[cost[1]] = memory[1];
	


	for(i=2;i<=N;i++)
	{
		for(j=N*100;j>=0;j--)
		{
			if(dp[j] != 0x7FFFFFFF) 
			{
				if(dp[j+cost[i]] == 0x7FFFFFFF) dp[j+cost[i]] = dp[j]+memory[i];
				else dp[j + cost[i]] = max(dp[j+cost[i]],dp[j]+memory[i]);
				
				//맞는위치
				//if(dp[j+cost[i]] >= M) MIN = min(MIN,j+cost[i]);
			}
			//틀린위치
			//if(dp[j+cost[i]] >= M) MIN = min(MIN,j+cost[i]);
			

		}

		//puts("-------------------------------------");
		//for(k=0;k<=M;k++).
		//{
		//	if(dp[k]!=0x7FFFFFFF) printf("dp[%d] = %d\n", k,dp[k]);
		//}
		//puts("-------------------------------------");
	}
	

	for(i=0;i<=N*100;i++)
	{
		if(dp[i]>=M && dp[i] != 0x7FFFFFFF) MIN = min(MIN,i);
	}
	
	printf("%d\n",MIN);

	return 0;
}