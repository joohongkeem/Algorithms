#include <stdio.h>

int main()
{
	int i=0,j1,j2,j3;
	int K, tmp;
	int arr[51]={0};
	int BF[1001]={0};
	int sum;
	
	while(arr[i]<=1000)
	{
		i++;
		arr[i] = arr[i-1] + i;
	}
	arr[i--]=0;  // 지금 i가 최대 삼각수의 index

	for(j1=1;j1<=i;j1++)
	{
		for(j2=1;j2<=i;j2++)
		{
			for(j3=1;j3<=i;j3++)
			{
				sum = 0;
				sum += arr[j1] + arr[j2] + arr[j3];
				if(sum>1000) break;
				BF[sum] = 1;
			}
		}
	}

	scanf("%d", &K);
	for(i=1;i<=K;i++)
	{
		scanf("%d", &tmp);
		printf("%d\n",BF[tmp]);
	}

	return 0;
}
