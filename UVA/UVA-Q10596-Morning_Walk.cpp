#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;

#define MAX 250
int d[MAX];
int p[MAX];
int rank[MAX];

void makeset(int x)
{
	p[x]=x;
	rank[x]=0;
}

int findset(int x)
{
	if(x!=p[x])
		p[x]=findset(p[x]);
	return p[x];
}

void link(int x,int y)
{
	if(rank[x]>rank[y]) 
		p[y] = x; 
	else 
	{ 
		p[x] = y; 
		if(rank[x]==rank[y]) 
			rank[y]++; 
	}
}

int main()
{
	int v,e,v1,v2,tmp1,tmp2,last;
	bool no;
	while(scanf("%d %d",&v,&e)!=EOF)
	{
		memset(d,0,sizeof(d));
		no=false;
		for(int i=0;i<v;++i)
			makeset(i);
		for(int i=0;i<e;++i)
		{
			scanf("%d %d",&v1,&v2);
			d[v1]++;	d[v2]++;
			tmp1=findset(v1);
			tmp2=findset(v2);
			if(tmp1!=tmp2)
				link(tmp1,tmp2);
		}
		last=findset(0);	
		for(int i=0;i<v;++i)
		{
			if(d[i]%2==1)
			{
				no=true;
				break;
			}
			if(last!=findset(i))
			{
				no=true;
				break;
			}
		}
		if(no)
			printf("Not Possible\n");
		else
			printf("Possible\n");
	}
	return 0;
}