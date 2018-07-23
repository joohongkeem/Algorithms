#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int max(int a, int b)
{
	if(a>=b) return a;
	else return b;
}

char carr1[1001];
char carr2[1001];
char arrcmp[1001][1001]; 
int dp[2][1001];


int main()
{
	int i,j,k;
	int len1,len2;
	int maxval;
	scanf("%s",carr1);
	scanf("%s",carr2);
	
	len1 = strlen(carr1);
	len2 = strlen(carr2);

	for(i=0;i<len1;i++)
		for(j=0;j<len2;j++) if(carr1[i] == carr2[j]) arrcmp[j][i]=1;


	for(i=0;i<len1;i++)
	{
		for(j=0;j<len2;j++)
		{
			if(arrcmp[j][i] == 1)
			{
				maxval=0;
				for(k=0;k<j;k++)
				{
					maxval = max(dp[0][k],maxval);

				}
				dp[1][k] = maxval+1;

			}

			else dp[1][j] = dp[0][j];


		}
		for(k=0;k<len2;k++)
		{
			dp[0][k] = dp[1][k];
		}


	}

	maxval=0;
	for(k=0;k<len2;k++)
	{
		maxval = max(dp[1][k],maxval);
	}

	printf("%d",maxval);

	


	return 0;
}

