#include <stdio.h>
#include <string.h>

int dp[3];

int main()
{
	int N,i;
	scanf("%d",&N);

	if(N==1) {puts("1"); return 0;}
	if(N==2) {puts("2"); return 0;}

	dp[0] = 1;
	dp[1] = 2;

	for(i=1;i<=N-2;i++)]
	{
		dp[2] = dp[1]+dp[0];
		dp[2] %= 15746;

		dp[0] = dp[1];
		dp[0] %= 15746;
		dp[1] = dp[2];
		dp[1] %= 15746;
	}

	printf("%d\n",dp[2]);
	return 0;
}