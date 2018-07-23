#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N,K;
int Queue[100001];
int ANS[100001];
char visit[100001];
int FRONT=0, REAR=0;

void BFS()
{
	int val;
	Queue[REAR++] = N;
	ANS[N] = 0;
	visit[N] = 1;

	while(FRONT<REAR)
	{
		val = Queue[FRONT++];

		if(val == K) return;

		if(visit[val-1] == 0 && val-1 >=0) {Queue[REAR++] = val - 1; ANS[val-1]= ANS[val]+1; visit[val-1] = 1;}
		if(visit[val+1] == 0 && val+1 <=100000) {Queue[REAR++] = val + 1; ANS[val+1]= ANS[val]+1; visit[val+1] = 1;}
		if(visit[2*val] == 0 && 2*val <=100000) {Queue[REAR++] = val * 2; ANS[val*2]= ANS[val]+1; visit[val*2] = 1;}



	}
}

int main()
{
	scanf("%d %d",&N,&K);
	BFS();

	printf("%d\n",ANS[K]);


}