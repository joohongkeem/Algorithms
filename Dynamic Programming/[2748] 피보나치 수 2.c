#define _CRT_SECURE_NO_WARININGS

#include <stdio.h>

int main()
{
	unsigned long long int dp[3] = {0,1};
	int i;
	int N;

	scanf("%d",&N);
	for(i=1;i<=N-1;i++)
	{
		dp[2] = dp[1]+dp[0];
		dp[0] = dp[1];
		dp[1] = dp[2];
	}

	printf("%llu\n",dp[1]);


	return 0;
}