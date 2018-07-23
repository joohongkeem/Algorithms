#include <stdio.h>


int main()
{
	int N,L,i,j,sum,check=0;
	int min;
	scanf("%d %d",&N,&L);

	for(i=L;i<=100;i++)
	{
		sum = 0;
		for(j=0;j<i;j++) {sum +=j+1;}

		if((N-sum)%i==0) {min = (N-sum)/i + 1;  if(min<0) continue; else {check=1; break;}}
		
	}

	if(i==101 && check==0) printf("-1");
	else for(j=min; j<min+i;j++) printf("%d ",j);



	return 0;
}