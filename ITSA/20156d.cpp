#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;
#define MAXN 10000010
long long int ans;

struct Node
{
	int val;
	bool isodd;
}tmp;
vector<Node> s;

void build(int L,int R)
{
    for(int i=L;i<=R;++i)
    {
    	tmp.val=i;
    	if(i&1)
    	{
			tmp.isodd=true;
    		ans+=i;
    	}
		else
			tmp.isodd=false;
		s.push_back(tmp);
    }
}

void cover(int L,int R)
{
	int i,j;
	if((L&1)==(R&1))
	{
		for(i=L,j=R;j>i;++i,--j)
		{
			tmp.val=s[i].val;
			s[i].val=s[j].val;
			s[j].val=tmp.val;
		}
	}
	else
	{
		for(i=L,j=R;j>i;++i,--j)
		{
			if(i&1)
			{
				ans-=s[i].val;
				ans+=s[j].val;
			}
			tmp.val=s[i].val;
			s[i].val=s[j].val;
			s[j].val=tmp.val;

		}
	}
    
}

int main()
{
	int T,n,m;
	int i;
	int a,b;
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);	
		s.clear();	
		s.push_back(tmp);
		ans=0;
		build(1,n);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			cover(a,b);		
		}
		
		/*
		for(i=1;i<=n;++i)
		{
			//printf("%d \n",s[i].val);
			if(s[i].isodd)
				ans+=s[i].val;
		}
		*/
		printf("%lld\n",ans);
	}
	return 0;
}
