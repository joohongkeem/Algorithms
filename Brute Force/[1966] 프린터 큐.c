#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
	int value;
	int check;
};

struct data DATA[10001];
int N, M;
int FRONT, REAR;
int REMAIN, COUNT;

void enqueue(struct data newvar)
{
	DATA[++REAR] = newvar;
}

struct data dequeue()
{
	return DATA[++FRONT];
}

struct data ONESTEP()
{
	int i,max,maxidx = FRONT+1;

	max = DATA[FRONT+1].value;
	for(i=FRONT+2;i<=REAR;i++)
	{
		if(max < DATA[i].value) {max = DATA[i].value; maxidx = i;}
	}

	while(FRONT+1 < maxidx)
	{
		enqueue(dequeue());
	}
	
	COUNT++;
	return dequeue();

}

int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		int temp;
		scanf("%d %d",&N, &M);
		FRONT = -1, REAR = -1;
		COUNT = 0;


		for(i=0;i<N;i++)
		{
			scanf("%d",&temp);
			DATA[i].value = temp;
			DATA[i].check = 0;
		}
		DATA[M].check = 1;
		REAR = N-1;

		while(ONESTEP().check!=1);
		printf("%d\n",COUNT);
	}




}