#include <stdio.h>
#include <string.h>
int main()
{
	int dp[2][3] = {1,1,1};
	int N,i,j;

	scanf ("%d", &N);
	
	for(i=2;i<=N;i++)
	{
		dp[1][0] = dp[0][1]+dp[0][2];
		dp[1][1] = dp[0][0]+dp[0][2];
		dp[1][2] = dp[0][0]+dp[0][1]+dp[0][2];

		dp[0][0] = dp[1][0]%9901;
		dp[0][1] = dp[1][1]%9901;
		dp[0][2] = dp[1][2]%9901;
	}

	printf("%d\n",(dp[0][0]+dp[0][1]+dp[0][2])%9901);
	



	return 0;
}