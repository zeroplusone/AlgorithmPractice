#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAXN 1100
double no[MAXN],ken[MAXN];

int main()
{
	int t,tt;
	int n;
	int i,j,k,ans1,ans2;
	scanf("%d",&t);
	freopen("d.out","w",stdout);
	for(tt=1;tt<=t;++tt)
	{
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(i=0;i<n;++i)
			scanf("%lf",&no[i]);
		sort(no,no+n);	
		for(i=0;i<n;++i)
			scanf("%lf",&ken[i]);
		sort(ken,ken+n);
/*
		for(i=0,j=0;i<n && j<n;++i,++j)
		{
			while(j<n && ken[j]<no[i])
			{
				j++;
			}

		}
		
		ans1=n-i;

		for(i=0,j=0;i<n && j<n;++i,++j)
		{
			while(i<n && ken[j]>no[i])
			{
				i++;
			}

		}
		ans2=j;*/
		for(i=0,j=0,k=0;k<n;++k)
		{
			if(ken[j]<no[i])
			{
				j++;
			}
			else if(ken[j]>no[i])
			{
				i++;
				j++;
			}
		}
		
		ans1=n-i;

		for(i=0,j=0,k=0;k<n;++k)
		{
			if(i<n && ken[j]>no[i])
			{
				i++;
			}
			else if(ken[j]<no[i])
			{
				i++;
				j++;
			}
		}
		ans2=j;
		printf("%d %d\n",ans2,ans1);
	}
	return 0;
}