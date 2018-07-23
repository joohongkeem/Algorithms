#include <stdio.h>


int main()
{
	int N,K,n,k,t;
	int dp[201]={0};

	scanf("%d %d", &N,&K);

	for(k=0;k<=K;k++) dp[k] = 1;

	dp[0]=0;
	for(n=1;n<=N;n++) 
		for(k=1;k<=K;k++) {dp[k] += dp[k-1]; dp[k]%=1000000000;}

	printf("%d",dp[K]);
	

	return 0;
}