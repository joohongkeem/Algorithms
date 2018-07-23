#include <stdio.h>

int dp[100001];

int min(int a, int b)
{
	if(a<b) return a;
	else return b;
}
int main()
{
	int N,i,j,k;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		dp[i] = 100001;
	}

	
	for(i=1;i*i<=N;i++)
	{
		for(j=i*i;j<=N;j++)	dp[j] = min(dp[j],dp[j-i*i]+1);
	}
	printf("%d",dp[N]);
	
	return 0;
}