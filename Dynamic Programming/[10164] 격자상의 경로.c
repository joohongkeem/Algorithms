#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int path(int (*dp)[16],int x, int y)
{
	int i,j;
	for(i=1;i<=x;i++) for(j=1;j<=y;j++) dp[i][j] = 0;
	for(j=1;j<=y;j++) dp[1][j] = 1;
	for(i=1;i<=x;i++) dp[i][1] = 1;
	
	for(i=2; i<=x; i++)
	{
		for(j=2; j<=y; j++)
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
	}


	return dp[x][y];

}

int N,M,K;
int dp[16][16];


int main()
{
	int x1,y1,x2,y2;

	scanf("%d %d %d",&N, &M, &K);
	



	if(K==0)
	{
		printf("%d", path(dp,N,M)); 
	}

	if(K!=0)
	{
		x1=(K-1)/M + 1;
		if(K%M==0) y1 = M;
		else y1 = K%M;
		
		x2 = N+1 - x1;
		y2 = M+1 - y1;
		//printf("(%d %d) (%d %d)", x1,y1,x2,y2);
		printf("%d", path(dp,x1,y1)*path(dp,x2,y2));
	}

	return 0;
}