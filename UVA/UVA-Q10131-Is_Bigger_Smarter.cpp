#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;

#define MAX 1010
struct elephant
{
	int num;
	int w,s;
	bool operator<(const elephant& p)const
	{
		return w<p.w;
	}	
}e[MAX];
int dp[MAX];
int p[MAX];

int main()
{
	int max=0,ans=0,tmp=0;
	int c=1;
	for(int i=0;i<MAX;++i)
	{
		dp[i]=0;	p[i]=0;		
	}
	e[0].w=e[0].s=e[0].num=0;
	while(scanf("%d %d",&e[c].w,&e[c].s)!=EOF)
	{
		e[c].num=c;
		c++;
	}
	sort(e,e+c);

	for(int i=0;i<c;++i)
	{
		max=dp[i];
		for(int j=i-1;j>=0;--j)
		{	
			if(j>=0)
			{
				if(e[i].w>e[j].w && e[i].s< e[j].s)
				{
					if(dp[j]+1>max)
					{
						max=dp[j];
						p[i]=j;
					}
				}
			}
		}
		dp[i]=max+1;
		if(dp[i]>=tmp){	tmp=dp[i];	ans=i;}
	}

	int n=dp[ans];
	printf("%d\n",n);
	stack<int> a;
	a.push(ans);

	for(int i=1;i<n;++i)
	{
		a.push(p[ans]);
		ans=p[ans];
	}
	
	while(!a.empty())
	{
		printf("%d\n",e[a.top()].num);
		a.pop();
	}
}
