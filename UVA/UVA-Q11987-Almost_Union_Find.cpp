/******************
Judge   : UVA
Problem : 11987 - Almost Union-Find
Course  : Course8
discribe: 
			1 p q
			Union the sets containing p and q. If p and q are already in the same set, ignore this command.
			2 p q
			Move p to the set containing q. If p and q are already in the same set, ignore this command
			3 p
			Return the number of elements and the sum of elements in the set containing p.
Input   : 
			5 7	//n(#node) m(@relation)
			1 1 2
			2 3 4
			1 3 5
			3 4
			2 4 1
			3 4
			3 3
Output  : 
			3 12	//#elemeny sum
			3 7
			2 8
Solve   : disjoint set
*******************/
//TLE
/*
#include<bits/stdc++.h>
#include<stack>
using namespace std;

#define MAXN 100100
int p[2*MAXN],h[2*MAXN];
int sum[2*MAXN],num[2*MAXN];
//stack<int> son[2*MAXN];
int n;
int trash;
void makeset(int size)
{
	for(int i=0;i<=size;++i)
	{	
		p[i]=i;
		h[i]=0;
		//while(!son[i].empty())	son[i].pop();
		sum[i]=i>n?0:i;
		num[i]=i>n?0:1;
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
	x=findset(x);
	y=findset(y);
	if(x!=y)
	{
		if(h[x]<h[y])
		{
			p[x]=y;
			sum[y]+=sum[x];
			num[y]+=num[x];
			//son[y].push(x);
		}
		else
		{
			p[y]=x;
			sum[x]+=sum[y];
			num[x]+=num[y];
			//son[x].push(y);
			if(h[x]==h[y])
				h[y]++;
		}
	}
	//printf("%d %d %d %d\n",num[x],sum[x],num[y],sum[y]);
}

void move(int x,int y)
{
	/* //delete by force
	int root=findset(x);
	if(root==x)
	{
		if(!son[x].empty())	//reset root
		{
			root=son[x].top();
			son[x].pop();
			num[root]=num[x];
			sum[root]=sum[x];
			p[x]=root;
			p[root]=root;
		}	
	}
	while(!son[x].empty())
	{
		p[son[x].top()]=p[x];
		son[p[x]].push(son[x].top());
		son[x].pop();
	}
	num[root]--;
	sum[root]-=x;*/

	//change x value to impossible	
	
	/*p[x+n]=p[x]==x?x+n:p[x];
	
	while(!son[x].empty())
	{
		p[son[x].top()]=x+n; //fiction value
		son[x].pop();
	}
	int root=findset(x+n);
	if(root==x+n)
	{
		num[root]=num[x]-1;
		sum[root]=sum[x]-x;
	}
	else
	{
		//printf("!!!%d %d %d\n",root,num[root],sum[root]);
		num[root]--;
		sum[root]-=x;
		//printf("!!!%d %d %d\n",root,num[root],sum[root]);
	}*/
	/*
	//add value by force
	int root2=root;
	root=findset(y);
	p[x]=root;
	num[root]++;
	sum[root]+=x;
	son[root].push(x);*/
	/*
	num[x]=1;	sum[x]=x;	p[x]=x;
	uniont(x,y);
	//printf("%d %d %d %d\n",num[findset(x)],sum[findset(x)],num[findset(x+n)],sum[findset(x+n)]);
}

int main()
{
	int m;
	int in;
	int a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		makeset(2*n+10);
		trash=n+1;
		while(m--)
		{
			scanf("%d",&in);
			switch(in)
			{
				case 1:
					scanf("%d%d",&a,&b);
					uniont(a,b);
					break;
				case 2:
					scanf("%d%d",&a,&b);
					move(a,b);
					break;
				case 3:
					scanf("%d",&a);
					a=findset(a);
					printf("%d %d\n",num[a],sum[a]);
					break;
				default:
					break;
			}
		}	
	}
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
int p[MAXN*2],h[MAXN*2];
long long int sum[MAXN*2]; //*****
int num[MAXN*2];
int now;
int realpoint[MAXN];

void makeset(int size)
{
	for(int i=0;i<=size;++i)
	{	
		p[i]=i;
		h[i]=0;
		sum[i]=i;
		num[i]=1;
		realpoint[i]=i;
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
	x=findset(x);
	y=findset(y);
	if(x!=y)
	{
		if(h[x]<h[y])
		{
			p[x]=y;
			sum[y]+=sum[x];
			num[y]+=num[x];
		}
		else
		{
			p[y]=x;
			sum[x]+=sum[y];
			num[x]+=num[y];
			if(h[x]==h[y])
				h[y]++;
		}
	}
	//printf("%d %d %d %d\n",num[x],sum[x],num[y],sum[y]);
}

void move(int a,int b)
{
	//origin set change to virtual point
	int root=findset(realpoint[a]);
	num[root]--;
	sum[root]-=a;
	//make new point
	int i=now;	now++;
	p[i]=i;		h[i]=0;		sum[i]=a;	num[i]=1;
	realpoint[a]=i;
	uniont(realpoint[a],realpoint[b]);
}

int main()
{
	int n,m;
	int in,a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		makeset(2*n+10);
		now=n+1;
		while(m--)
		{
			scanf("%d",&in);
			switch(in)
			{
				case 1:
					scanf("%d%d",&a,&b);
					uniont(realpoint[a],realpoint[b]);
					break;
				case 2:
					scanf("%d%d",&a,&b);
					move(realpoint[a],realpoint[b]);
					break;
				case 3:
					scanf("%d",&a);
					a=findset(realpoint[a]);
					printf("%d %lld\n",num[realpoint[a]],sum[realpoint[a]]);
					break;
				default:
					break;
			}
		}	
	}
	return 0;
}