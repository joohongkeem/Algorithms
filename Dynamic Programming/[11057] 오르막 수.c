#include <stdio.h>


int main()
{
	int N;
	int i,j,k,sum=0;
	int dp[10] = {1,1,1,1,1,1,1,1,1,1};

	scanf("%d",&N);

	for(i=2;i<=N;i++)
	{
		for(j=9;j>=1;j--)
		{
			for(k=j-1;k>=0;k--)
			{
				dp[j] += dp[k];
				dp[j] %= 10007;
			}
		}
	}


	for(i=0;i<=9;i++) {sum+= dp[i]; sum %= 10007;}

	printf("%d\n",sum);

	return 0;
}