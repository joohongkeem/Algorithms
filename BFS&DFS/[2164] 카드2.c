#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Queue[500002];
int FRONT = 0;
int REAR = 0;
int N=1;

int isEmpty(void)
{
	if(FRONT%(N+1) == REAR%(N+1)) return 1;
	else return 0;
}
int isFull(void)
{
	if(FRONT%(N+1) == (REAR+1)%(N+1)) return 1;
	else return 0;
}

void enqueue(int value)
{
	if(isFull()) {return;}
	Queue[(++REAR)%(N+1)] = value;
	REAR%=N;
}

int dequeue(void)
{
	int value;
	value = Queue[(++FRONT)%(N+1)];
	Queue[FRONT-1]=0;
	FRONT %= N;
	return value;
}

int size(void)
{
	return REAR%(N+1) - FRONT%(N+1);
}


int main()
{

	int i;
	scanf("%d",&N);
    if(N==1){puts("1"); return 0;}

	for(i=1;i<=N;i++) enqueue(i);


	while(size() != 1)
	{
		dequeue();
		enqueue(dequeue());

	}

	printf("%d",dequeue());
	



	return 0;
}