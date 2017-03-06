/******************
Judge   : UVA
Problem : 10685 - Nature
Course  : Course8
discribe: find the longest size in alimentary chains

Sample Input
5 2	//n #animal  r #relation
caterpillar	// n  animal name
bird
horse
elefant
herb
herb caterpillar	//r  the second creature is a predator of the first one.
caterpillar bird     // a->b

0 0	//end

Sample Output
3	//longest size in alimentary chains

Solve   : disjoint set
*******************/
#include<bits/stdc++.h>
using namespace std;

#define MAXN 5100
int h[MAXN];
int p[MAXN];
int num[MAXN];
int ans;

void makeset(int size)
{
	for(int i=0;i<=size;++i)
	{	
		p[i]=i;
		h[i]=0;
		num[i]=1;
	}
}

int findset(int x)
{
	if(x==p[x])
		return x;
	else
		return p[x]=findset(p[x]);
}

void uniont(int x,int y)
{
	int px=findset(x);
	int py=findset(y);
	if(px!=py)
	{
		if(h[px]<h[py])
		{
			p[px]=py;
			num[py]+=num[px];			
		}
		else
		{
			p[py]=px;
			num[px]+=num[py];
			if(h[px]==h[py])
				h[px]++;
		}	
	}
}

int main()
{
	int n,r;
	int i;
	map<string,int> ani;
	string s1,s2;
	while(scanf("%d%d",&n,&r)!=EOF)
	{
		if(n==0 && r==0)	break;
		ani.clear();	ans=0;
		makeset(n);
		
		for(i=0;i<n;++i)
		{
			cin>>s1;
			ani[s1]=i;
		}
		for(i=0;i<r;++i)
		{
			cin>>s1>>s2;
			uniont(ani[s1],ani[s2]);
		}
		for(i=0;i<n;++i)
			ans=num[i]>ans?num[i]:ans;
		printf("%d\n",ans);
	}
	return 0;
}