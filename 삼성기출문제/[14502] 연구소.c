#include <stdio.h>

int backup[10][10];
int N,M;
int candidate, max;
void _backup(int arr[][10])
{
	int i,j;
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			arr[i][j] = backup[i][j];
}

void viruscheck(int i, int j,int arr[][10])
{
	if(i>N || i<=0) return ;
	if(j>M || j<=0) return ;
	if(arr[i][j] == 1) return ;

	if(arr[i-1][j]!=0 && arr[i+1][j]!=0 && arr[i][j-1]!=0&&arr[i][j+1]!=0) return ;
	if(arr[i][j] == 2)
	{
		if(i-1>=0&&arr[(i-1)][j] == 0) {arr[i-1][j] = 2; viruscheck((i-1),j,arr);}
		if(i+1<=N&&arr[(i+1)][j] == 0) {arr[i+1][j] = 2; viruscheck((i+1),j,arr);}
		if(j-1>=0&&arr[i][(j-1)] == 0) {arr[i][j-1] = 2; viruscheck(i,(j-1),arr);}
		if(j+1<=M&&arr[i][(j+1)] == 0) {arr[i][j+1] = 2; viruscheck(i,(j+1),arr);}

	}
}



int main()
{
	int i,j;
	int a,b,c,d,e,f;
	int count;
	int arr[10][10];

	scanf("%d %d", &N, &M);
	for(i=1;i<=N;i++){
		for(j=1;j<=M;j++) 
		{
			scanf("%d",&arr[i][j]);
			backup[i][j] = arr[i][j];
		}
	}




	
	for(a=0;a<100;a++)
	{
		if(a%10 == 9 || a%10 == 0) continue;
		for(b=a+1;b<100;b++)
		{
			if(b%10 == 9 || b%10 == 0) continue;
			for(c=b+1;c<100;c++)
			{
				if(c%10 == 9 || c%10 == 0) continue;
				count = 0;
				if(*(*arr+a)==0) {*(*arr+a)=1; count++;}
				if(*(*arr+b)==0) {*(*arr+b)=1; count++;}
				if(*(*arr+c)==0) {*(*arr+c)=1; count++;}

				if(count==3)
				{
					for(i=1;i<=N;i++)
					{
						for(j=1;j<=M;j++)
							viruscheck(i,j,arr);
					}
					
				
					candidate = 0;
					for(i=1;i<=N;i++)
					{
						for(j=1;j<=M;j++)
						{
							if(arr[i][j]==0) candidate ++;
						}
					}
					if(max<candidate) max = candidate;	

				}
				_backup(arr);
			}
		}


	}
	



	printf("%d",max);
	return 0;
}
