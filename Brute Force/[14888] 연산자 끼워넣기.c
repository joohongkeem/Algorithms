#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int N;
int num[12];
int MIN = 0x7FFFFFFF, MAX=0x80000001;

int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
void makingANS(int cplus, int cminus, int cmul, int cdiv, int value, int idx)
{
	int tmp;
	if(cplus ==0 && cminus ==0 && cmul == 0 && cdiv == 0)
	{
		if(idx <= N) return;
		else
		{
			MAX = max(MAX,value);
			MIN = -max(-MIN, -value);
			return;
		}
	}
	if(cplus > 0) { tmp = value + num[idx]; makingANS(cplus-1,cminus,cmul,cdiv,tmp,idx+1);}
	if(cminus> 0) { tmp = value - num[idx]; makingANS(cplus,cminus-1,cmul,cdiv,tmp,idx+1);}
	if(cmul> 0) { tmp = value * num[idx]; makingANS(cplus,cminus,cmul-1,cdiv,tmp,idx+1);}
	if(cdiv> 0) { tmp = value / num[idx]; makingANS(cplus,cminus,cmul,cdiv-1,tmp,idx+1);}
}

int main()
{
	int i;
	int cplus,cminus,cmul,cdiv;


	scanf("%d",&N);
	for(i=1;i<=N;i++) scanf("%d",&num[i]);
	scanf("%d %d %d %d", &cplus,&cminus,&cmul,&cdiv);


	makingANS(cplus, cminus, cmul, cdiv, num[1], 2);
	

	if(N==1)
	{
		printf("%d\n%d\n",num[1],num[1]);
		return 0;
	}
	else printf("%d\n%d\n",MAX,MIN);

	
	
	
	return 0;
}