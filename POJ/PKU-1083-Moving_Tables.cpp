#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	int t,n,from,to,max;
	scanf("%d",&t);
	int road[200];
	
	for(int i=0;i<t;++i)
	{
		max=0;
		memset(road,0,sizeof(road));
		scanf("%d",&n);
		for(int j=0;j<n;++j)
		{
			scanf("%d %d",&from,&to);
			if(from>to)
				swap(from,to);			
			for(int k=(from-1)/2;k<=(to-1)/2;++k)							
				road[k]++;			
		}
		for(int l=0;l<200;++l)
			if(road[l]>max)
				max=road[l];
		printf("%d\n",max*10);
	}
	return 0;
}