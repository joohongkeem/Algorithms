

int main()
{
	int T,N,M,i;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d",&N,&M);
		printf("%d\n",Combi(M,N));
	}
}