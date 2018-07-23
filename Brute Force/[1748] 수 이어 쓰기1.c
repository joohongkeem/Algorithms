#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int pow(int x, int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	else return x*pow(x,y-1);
}

int main()
{
	int N;
	int i;
	int T=0;
	int LEN=9;
	int TEMP = 100000000;


	scanf("%d",&N);
	while(LEN)
	{ 
		if(N>=TEMP) break;
		else TEMP /= 10;
		LEN--;
	}
	
	TEMP=1;
	for(i=1; i<=LEN; i++)
	{
		T += i * (pow(10,i) - TEMP);
		TEMP = pow(10,i);
	}
	

	
	for(i = pow(10,LEN)-1 ; i>N ; i--)
	{
		T -= LEN;
	
	}

	
		

	printf("%d\n",T);
	

	return 0;
}