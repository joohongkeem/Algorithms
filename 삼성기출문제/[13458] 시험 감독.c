#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N,B,C;
int people[1000001];

int main()
{
	int i,temp;
	long long int COUNT=0;
	
	scanf("%d",&N);
	for(i=1;i<=N;i++) scanf("%d",&people[i]);
	scanf("%d %d", &B, &C);

	for(i=1;i<=N;i++)
	{
		people[i] -= B;
		COUNT ++;


		if(people[i]<=0) continue;
		
		COUNT += people[i] / C;
		if(people[i] % C != 0) COUNT++; 
		
	}
	printf("%lld\n",COUNT);				// lld �� �����ؾ��Ѵ�. �鸸���� ���ǽǿ� �鸸��, B =1, C=1 �϶� ����


	return 0;

}