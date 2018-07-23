#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char dev[4][9];
int SUM = 0;
char temp[6];
char MOVE[4];

void makingtemp(void)
{

	temp[0] = dev[0][2];
	temp[1] = dev[1][6];
	temp[2] = dev[1][2];
	temp[3] = dev[2][6];
	temp[4] = dev[2][2];
	temp[5] = dev[3][6];
}

void clockwise(char *p)
{
	char temp;
	int i;
	temp = p[7];
	for(i=6;i>=0;i--)
		p[i+1] = p [i];
	p[0] = temp;
}

void anticlockwise(char *p)
{
	char temp;
	int i;
	temp = p[0];
	for(i=1;i<=7;i++)
		p[i-1] = p[i];
	p[7] = temp;
}

int main()
{
	int i,j,K,num,move;

	for(i=0;i<=3;i++) scanf("%s",&dev[i]);
	
	
	scanf("%d",&K);
	while(K--)
	{

		scanf("%d %d", &num, &move);
		
		makingtemp();

		MOVE[num-1] = move;


		
		for(i=num-1; i<=2; i=i+1)
		{
			if(temp[i*2+1] == temp[i*2]) MOVE[i+1] = 0;
			else MOVE[i+1] = -MOVE[i];
		}

		for(i=num-2; i>=0; i=i-1)
		{
			if(temp[i*2] == temp[(i+1)*2-1]) MOVE[i] = 0;
			else MOVE[i] = -MOVE[i+1];
		}
		for(i=0;i<=3;i++)
		{
			if(MOVE[i] == 1) clockwise(dev[i]);
			else if(MOVE[i] == -1) anticlockwise(dev[i]);
			else ;
		}



	}

	if(dev[0][0] == '1') SUM+=1;
	if(dev[1][0] == '1') SUM+=2;
	if(dev[2][0] == '1') SUM+=4;
	if(dev[3][0] == '1') SUM+=8;

	printf("%d\n",SUM);

	
	return 0;
}
