#include <stdio.h>


int pow(int x, int y)
{
	
	if(y==1)return x;
	if(y==0) return 1;
	else return x*pow(x,y-1);
}

int main()
{

	int n,sum=0,i;

	scanf("%d",&n);

	for(i=1;i<6;i++)
		sum += n/pow(5,i);
	
	if(n==0) printf("%d",0);
	else printf("%d",sum);


	return 0;
}
