#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 1100

struct input
{
	int ss,ee;
	bool operator<(const input& i)const
	{
		return ss<i.ss;
	}
}in[MAX];

struct area
{
	int s,e;
}a[MAX];

int main()
{
	int t,n;
	int ans;
	int ins,ine;
	bool ya;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i)		
			scanf("%d %d",&in[i].ss,&in[i].ee);
		sort(in,in+n);
		
		for(int j=0;j<n;++j)
		{
			ya=true;
			for(int i=0;i<ans;++i)
			{
				if(in[j].ss>=a[i].s && in[j].ss <=a[i].e)
				{
					if(in[j].ee>a[i].e)
						a[i].e=in[j].ee;
					ya=false;
					break;
				}
			}
			if(ya)
			{
				a[ans].s=in[j].ss;
				a[ans].e=in[j].ee;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}