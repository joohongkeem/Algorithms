#include <stdio.h>

int arr[301][301];
int main()
{
	int N,M,K,k;
	int i,j,x,y;
	int n,m;

	scanf("%d %d",&N,&M);
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++) { 
			scanf("%d",&arr[i][j]); 
			arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
		}

	scanf("%d",&K);

	for(k=1;k<=K;k++)
	{
		scanf("%d %d %d %d",&i,&j,&x,&y);

		for(n=i;n<=x;n++)
			for(m=j;m<=y;m++) 
				printf("%d\n",arr[x][y]-arr[x][j-1]-arr[i-1][y] + arr[i-1][j-1]);
	}
	

}