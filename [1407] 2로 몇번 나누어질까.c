#include <stdio.h>


unsigned long long int pow(int x, int y)
{
 	if(y==0) return 1;
	if(y==1) return x;
 
    else return x*pow(x,y-1);
 
}

int main(void)
{
	unsigned long long int a,b,sum1=0,sum2=0;
	int i;
	unsigned long long int arr[52]={0};

	scanf("%lld %lld",&a,&b);
	
	a= a-1;

	for(i=1;pow(2,i-1)<=a;i++)
	{
		arr[i] = a / pow(2,i-1);
	}
	for(i=1;pow(2,i-1)<=a;i++)
	{
		arr[i] = arr[i]-arr[i+1];
		sum1 += arr[i]*pow(2,i-1);
		arr[i]=0;
	}





	for(i=1;pow(2,i-1)<=b;i++)
	{
		arr[i] = b / pow(2,i-1);
	}

	for(i=1;pow(2,i-1)<=b;i++)
	{
		arr[i] = arr[i]-arr[i+1];
		sum2 += arr[i]*pow(2,i-1);
	}

	printf("%lld",sum2-sum1);

	return 0;
}
