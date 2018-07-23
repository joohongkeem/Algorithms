#include <stdio.h>



int main()
{
	int N;	
	int height[51];
	int weight[51];
	int i,j;
	int rank;

	scanf("%d",&N);

	for(i=1;i<=N;i++)
	{
		scanf("%d %d", &weight[i],&height[i]);
	}
	
	for(i=1;i<=N;i++)
	{
		rank =1;
		for(j=1;j<=N;j++)
		{
			if(weight[i]<weight[j]&&height[i]<height[j]) rank++;
		}
		printf("%d ",rank);
	}
	return 0;
}