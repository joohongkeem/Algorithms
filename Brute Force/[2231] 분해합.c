#include <stdio.h>



int main()
{
	int N;
	int zari[7]={0};
	int i;
	scanf("%d",&N);

	for(i=1;i<=N;i++)
	{
		zari[0] = i/1000000;
		zari[1] = (i/100000)%10;
		zari[2] = (i/10000)%10;
		zari[3] = (i/1000)%10;
		zari[4] = (i/100)%10;
		zari[5] = (i/10)%10;
		zari[6] = i%10;

		if(i+zari[0]+zari[1]+zari[2]+zari[3]+zari[4]+zari[5]+zari[6] == N)
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("0");

	return 0;
}