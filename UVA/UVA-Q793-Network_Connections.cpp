/******************
Judge   : UVA
Problem : 793 - Network Connections
Course  : Course3
discribe: c computeri computerj,computeri and computerj get interconnected.
			q computeri computerj, is computeri interconnected with computerj?
			answer the q
Input   : 
			1	//t (case)

			10	//n node
			c 1 5
			c 2 7
			q 7 1
			c 3 9
			q 9 6
			c 2 5
			q 7 5
Output  : 
			1,2
Solve   : disjoint set
*******************/
#include<bits/stdc++.h>
using namespace std;

#define MAXN 100000
int p[MAXN];
int h[MAXN];
int n;

void makeset()
{
	for(int i=1;i<=n;++i)
	{
		p[i]=i;	h[i]=0;
	}
}

int findset(int a)
{
	if(p[a]==a)
		return a;
	else
		return p[a]=findset(p[a]);
}

void uniont(int x,int y)
{
	int px=findset(x);
	int py=findset(y);
	if(px!=py)
	{
		if(h[x]<h[y])
		{
			p[x]=y;
		}
		else
		{
			p[y]=x;
			if(h[x]==h[y])
				h[x]++;
		}
	}
}

int main()
{
	int t,a,b;
	int n1,n2;
	char c;
	scanf("%d",&t);
	while(t--)
	{	
		n1=0;	n2=0;
		
		scanf("%d",&n);
		getchar();
		while(c=getchar())
		{
			if(c=='\n')	{ printf("ya\n"); break;}
			scanf("%d%d",&a,&b);
			printf("~%c %d %d\n",c,a,b);
			if(c=='c')
			{
				uniont(a,b);
			}
			else if(c=='q')
			{
				if(findset(a)==findset(b))
					n1++;
				else
					n2++;
			}
			getchar();
		}
		printf("%d,%d\n",n1,n2);
		if(t)	printf("\n");
	}
	return 0;
}