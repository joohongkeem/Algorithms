#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}

char arr1[1002];
char arr2[1002];
char arrcmp[1002][1002];
char FINAL[1002];
int dp[1001][1001];

int main()
{

	int len1, len2;
	int i,j,k;
	int ANS=0;
	int jstart,jend;

	scanf("%s",&arr1[1]);
	scanf("%s",&arr2[1]);

	len1 = strlen(&arr1[1]);
	len2 = strlen(&arr2[1]);

	for(i=1;i<=len1;i++) for(j=1;j<=len2;j++) if(arr1[i] == arr2[j]) arrcmp[i][j] = 1;
	for(j=1;j<=len2;j++) if(arrcmp[1][j]==1) {dp[1][j] = 1;}


	for(i=2;i<=len1;i++)
	{

		for(j=1;j<=len2;j++)
		{
			if(arrcmp[i][j] != 0)
			{
				
				int temp = 0;
				int idx = 0;
				for(k = 1; k<j; k++)
				{
					if(temp<dp[i-1][k])
					{
						temp = dp[i-1][k];
						idx = k;
					}
				}
				dp[i][j] = temp+1;

			}
			else dp[i][j] = dp[i-1][j];

		}
				
	}
	

	for(j=1;j<=len2;j++) ANS = max(ANS,dp[len1][j]);
	printf("%d\n",ANS);

	i = len1;
	jstart = len2;
	while(ANS)
	{

		for(j=jstart;j>=1;j--)
		{
			if(dp[i][j] == ANS)
			{
				FINAL[ANS] = arr2[j];
				jstart = j-1;
				break;
			}
		}

		k=1;
		while(dp[i-k][j] == dp[i][j])
		{k++;}
		i=i-k+1;
		ANS--;
	}

	puts(&FINAL[1]);

	return 0;
}
