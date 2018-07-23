#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int min(int a, int b)
{
	if(a>b) return b;
	else return a;
}


int sum[501][501];
int dp[501][501];
int arr[501];

int main()
{
	int T,N;
	int n,i,j;
	int tmp;
	int gap;
	int min;
	scanf("%d",&T);

	while(T--)
	{
		

		scanf("%d",&N);
		
	
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++) {sum[i][j] = 0; dp[i][j] = 0;}

		for(n=1;n<=N;n++)
		{
			scanf("%d",&arr[n]);
			dp[n][n] = arr[n];
		}

		
		

		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				for(tmp=i;tmp<=j;tmp++) sum[i][j] += arr[tmp];
		
		for(i=1;i<=N-1;i++)
		{
			dp[i][i+1] = arr[i] + arr[i+1];
		}

		for(gap=2; gap<=N-1; gap++)
		{
			for(i=1; i+gap <=N; i++)
			{
				j = i+gap;
				
				min = 0x7FFFFFFF;
				for(tmp=i; tmp<=j-1; tmp++)
				{

					if( tmp == i && dp[tmp+1][j] < min)
					{
						min = dp[tmp+1][j];
						continue;
					}
					if( tmp == (j-1) && dp[i][tmp]< min)
					{
						min = dp[i][tmp];
						continue;
					}
					if( (dp[i][tmp] + dp[tmp+1][j]) < min)
					{
						min = (dp[i][tmp] + dp[tmp+1][j]);
					}
				
				}

				dp[i][j] = min+sum[i][j];
								
			}
		}
        printf("%d\n",dp[1][N]);


	}
}