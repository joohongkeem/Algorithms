#include <stdio.h>

int N,M;
int stick_vert(int (*p)[501],int i, int j)
{
	if(j+3>M) return 0;
	return p[i][j]+p[i][j+1]+p[i][j+2]+p[i][j+3];
}
int stick_hori(int (*p)[501],int i, int j)
{
	if(i+3>N) return 0;

	return p[i][j]+p[i+1][j]+p[i+2][j]+p[i+3][j];
}
int square(int (*p)[501],int i, int j)
{
	if(i+1>N||j+1>M) return 0;
	return p[i][j]+p[i+1][j]+p[i][j+1]+p[i+1][j+1];
}
int L_1(int (*p)[501],int i, int j)
{
	if(i+2>N||j+1>M) return 0;
	return p[i][j]+p[i+1][j]+p[i+2][j]+p[i+2][j+1];
}
int L_2(int (*p)[501],int i, int j)
{
	if(i+1>N||j+2>M) return 0;
	return p[i][j]+p[i][j+1]+p[i][j+2]+p[i+1][j];
}
int L_3(int (*p)[501],int i, int j)
{
	if(i+2>N||j+1>M) return 0;
	return p[i][j]+p[i][j+1]+p[i+1][j+1]+p[i+2][j+1];
}
int L_4(int (*p)[501],int i, int j)
{
	if(i+1>N||j+2>M) return 0;
	return p[i][j+2]+p[i+1][j]+p[i+1][j+1]+p[i+1][j+2];
}
int Lrev_1(int (*p)[501],int i, int j)
{
	if(i+2>N||j+1>M) return 0;
	return p[i][j+1]+p[i+1][j+1]+p[i+2][j]+p[i+2][j+1];
}
int Lrev_2(int (*p)[501],int i, int j)
{
	if(i+1>N||j+2>M) return 0;
	return p[i][j]+p[i][j+1]+p[i][j+2]+p[i+1][j+2];
}
int Lrev_3(int (*p)[501],int i, int j)
{
	if(i+2>N||j+1>M) return 0;
	return p[i][j]+p[i][j+1]+p[i+1][j]+p[i+2][j];
}
int Lrev_4(int (*p)[501],int i, int j)
{
	if(i+1>N||j+2>M) return 0;
	return p[i][j]+p[i+1][j]+p[i+1][j+1]+p[i+1][j+2];
}
int Z_1(int (*p)[501],int i, int j)
{
	if(i+2>N||j+1>M)  return 0;
	return p[i][j]+p[i+1][j]+p[i+1][j+1]+p[i+2][j+1];
}
int Z_2(int (*p)[501],int i, int j)
{
	if(i+1>N||j+2>M) return 0;
	return p[i][j+1]+p[i][j+2]+p[i+1][j]+p[i+1][j+1];
}
int Zrev_1(int (*p)[501],int i, int j)
{
	if(i+2>N||j+1>M)  return 0;
	return p[i][j+1]+p[i+1][j]+p[i+1][j+1]+p[i+2][j];
}
int Zrev_2(int (*p)[501],int i, int j)
{
	if(i+1>N||j+2>M) return 0;
	return p[i][j]+p[i][j+1]+p[i+1][j+1]+p[i+1][j+2];
}
int T_1(int (*p)[501],int i, int j)
{
	if(i+1>N||j+2>M) return 0;
	return p[i][j]+p[i][j+1]+p[i][j+2]+p[i+1][j+1];
}
int T_2(int (*p)[501],int i, int j)
{
	if(i+2>N||j+1>M) return 0;
	return p[i][j+1]+p[i+1][j]+p[i+1][j+1]+p[i+2][j+1];
}
int T_3(int (*p)[501],int i, int j)
{
	if(i+1>N||j+2>M) return 0;
	return p[i][j+1]+p[i+1][j]+p[i+1][j+1]+p[i+1][j+2];
}
int T_4(int (*p)[501],int i, int j)
{
	if(i+2>N||j+1>M) return 0;
	return p[i][j]+p[i+1][j]+p[i+2][j]+p[i+1][j+1];
}
int main()
{
	int arr[501][501]={0};
	int i,j,max=0;


	scanf("%d %d",&N,&M);

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
			scanf("%d",&arr[i][j]);
	}
	
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			if(max<=stick_vert(arr,i,j)) max = stick_vert(arr,i,j);
			if(max<=stick_hori(arr,i,j)) max = stick_hori(arr,i,j);
			if(max<=square(arr,i,j)) max = square(arr,i,j);
			if(max<=L_1(arr,i,j)) max = L_1(arr,i,j);
			if(max<=L_2(arr,i,j)) max = L_2(arr,i,j);
			if(max<=L_3(arr,i,j)) max = L_3(arr,i,j);
			if(max<=L_4(arr,i,j)) max = L_4(arr,i,j);
			if(max<=Lrev_1(arr,i,j)) max = Lrev_1(arr,i,j);
			if(max<=Lrev_2(arr,i,j)) max = Lrev_2(arr,i,j);
			if(max<=Lrev_3(arr,i,j)) max = Lrev_3(arr,i,j);
			if(max<=Lrev_4(arr,i,j)) max = Lrev_4(arr,i,j);
			if(max<=Z_1(arr,i,j)) max = Z_1(arr,i,j);
			if(max<=Z_2(arr,i,j)) max = Z_2(arr,i,j);
			if(max<=Zrev_1(arr,i,j)) max = Zrev_1(arr,i,j);
			if(max<=Zrev_2(arr,i,j)) max = Zrev_2(arr,i,j);
			if(max<=T_1(arr,i,j)) max = T_1(arr,i,j);
			if(max<=T_2(arr,i,j)) max = T_2(arr,i,j);
			if(max<=T_3(arr,i,j)) max = T_3(arr,i,j);
			if(max<=T_4(arr,i,j)) max = T_4(arr,i,j);

		}
	}
	
	printf("%d",max);

	return 0;
}