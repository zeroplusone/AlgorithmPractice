#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

//#define MAXN 500000

/*struct num
{
	int x,y;
	bool operator<(const num& t)const
	{
		return x<t.x; 
	}
};

int main()
{
	int n;
	num p1[MAXN],p2[MAXN];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d %d",&p1[i].x,&p1[i].y);
			p2[i].y=p1[i].x;
			p2[i].x=p1[i].y;
		}
		sort(p1,p1+n);
		sort(p2,p2+n);
		int flag=0;
		for(int k=0;k<n;++k)
		{
			if(p1[k].x!=p2[k].x)
			{
				flag=1;
				break;
			}				
		}
		if(flag==0)
			printf("YES");
		else
			printf("NO");		
	}
}*/

int main()
{
	int n;
	
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		int p1[n],p2[n];
		for(int i=0;i<n;++i)
		{
			scanf("%d %d",&p1[i],&p2[i]);
			
		}
		sort(p1,p1+n);
		sort(p2,p2+n);
		int flag=0;
		for(int k=0;k<n;++k)
		{
			//printf("%d %d\n",p1[k],p2[k]);
			if(p1[k]!=p2[k])
			{
				flag=1;
				break;
			}				
		}
		if(flag==0)
			printf("YES\n");
		else
			printf("NO\n");		
	}
}