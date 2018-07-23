#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int cost[101];
int memory[101];
int N,M;
int MIN = 0x7FFFFFFF;

int dp[10000001]={0};
int min(int a, int b)
{
	if(a>b) return b;
	else return a;
}

int main()
{
	int i,j;


	scanf("%d %d",&N,&M);
	for(i=1;i<=N;i++) scanf("%d",&memory[i]);
	for(i=1;i<=N;i++) scanf("%d",&cost[i]);
	
	for(i=1;i<=M;i++) dp[i] = 0x7FFFFFFF;
	


	for(i=1;i<=N;i++)
	{
		if(memory[i] >= M) {MIN = min(cost[i], MIN); continue;}


		for(j=M;j>=1;j--)
		{
			if(dp[j] != 0x7FFFFFFF) 
			{
				if(j+memory[i] >= M) { MIN = min(dp[j]+cost[i],MIN); continue;}

				dp[j+memory[i]] = min(dp[j+memory[i]], dp[j]+cost[i]);
			}
		}

		if(dp[memory[i]] == 0x7FFFFFFF) dp[memory[i]] = cost[i];
		else 
		{
			dp[memory[i]] = min(dp[memory[i]], cost[i]);
		}

	}
	printf("%d\n",MIN);

	return 0;
}