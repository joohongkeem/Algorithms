#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int N;
char arr[1000];

void checking(int tempnum, int i, int strike, int ball)
{
	char tnum[3];
	char inum[3];
	int STRIKE=0, BALL=0;
	int j;

	if(arr[i] == 0 ) return;

	tnum[0] = tempnum/100;
	tnum[1] = (tempnum - tnum[0]*100)/10;
	tnum[2] = (tempnum - tnum[0]*100 - tnum[1]*10);

	inum[0] = i/100;
	inum[1] = (i - inum[0]*100)/10;
	inum[2] = (i - inum[0]*100 - inum[1]*10);

	for(j=0;j<=2;j++) if(inum[j] == tnum[j]) STRIKE ++;
	if(tnum[0] == inum[1]) BALL++;
	if(tnum[0] == inum[2]) BALL++;
	if(tnum[1] == inum[0]) BALL++;
	if(tnum[1] == inum[2]) BALL++;
	if(tnum[2] == inum[0]) BALL++;
	if(tnum[2] == inum[1]) BALL++;

	if(STRIKE != strike) arr[i] = 0;
	if(BALL != ball) arr[i] = 0;

	return;
}
void init_num(int i)
{
	char num[3];

	num[0] = i/100;
	num[1] = (i-num[0]*100)/10;
	num[2] = (i-num[0]*100-num[1]*10);

	if(num[0] == 0) { arr[i] = 0; return;}
	if(num[1] == 0) { arr[i] = 0; return;}
	if(num[2] == 0) { arr[i] = 0; return;}
	if(num[0] == num[1]) { arr[i] = 0; return;}
	if(num[1] == num[2]) { arr[i] = 0; return;}
	if(num[0] == num[2]) { arr[i] = 0; return;}
}


int main()
{
	int i;
	int tempnum;
	int strike, ball;
	int ANSWER = 0;

	for(i=123; i<=999; i++) arr[i] = 1;
	for(i=123; i<=999; i++) init_num(i);
	
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d %d %d", &tempnum, &strike, &ball);
		for(i=123;i<=999; i++) checking(tempnum, i,strike, ball);
	}
	for(i=123;i<=999;i++) if(arr[i]!=0) ANSWER++;

	printf("%d\n",ANSWER);



	return 0;
}