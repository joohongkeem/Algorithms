#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int T[20];
int P[20];
int sum,max;

void process(int idx,int sum)
{
	if (idx > N) return;

	process(idx + 1, sum);
	if (idx + T[idx] - 1 <= N)
	{
		sum += P[idx];
		if(sum>max) max = sum;
        process(idx + T[idx], sum);
	}


}
int main(void)
{
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &T[i], &P[i]);
	}
	process(1, 0);
	printf("%d", max);
	return 0;
}