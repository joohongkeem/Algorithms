main(){
	int a[10001],n,k,c[100],i,j,temp;
    scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)scanf("%d",&c[i]);a[0]=0;
    for(i=1;i<=k;i++){a[i]=10001;for(j=0;j<n;j++){
		if(i-c[j]>=0)if(a[i]>a[i-c[j]]+1)
			a[i]=a[i-c[j]]+1;
	}}
		

		for(i=1;i<=K;i++) printf("%d ",a[i]);
		puts("");


    if(a[k]==10001)puts("-1");
    else printf("%d",a[k]);
}