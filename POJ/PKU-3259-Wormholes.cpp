/******************
Judge   : POJ
Problem : 3259-Wormholes
Course  : Course9
discribe:  return to the starting field a time before his initial departure.
Input   : 
			2		//f(case)
			3 3 1	//n(#node) m(positve) w(negative)
			1 2 2
			1 3 4
			2 3 1
			      ------¡ô m
			3 1 3
				  ------¡ô w
			3 2 1 //n(#node) m(positve) w(negative)
			1 2 3
			2 3 4
			3 1 8
Output  : 
			NO
			YES
Solve   : 1.loop every node as start , shortest path (nagatuve cycle) by bellman-ford

		  2. if there are negative
[bidirection negative]
*******************/
/*
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

#define MAX 6000
#define MAXN 600
#define INF 9999999
int n;

struct road
{
	int from;
	int to;
	int dis;
}r[MAX];

int d[MAXN];


int main()
{
	int f,m,w,tmp,v1,v2,l,count,min,a,b,c,ans;
	bool change,yes;
	c=1;
	scanf("%d",&f);
	for(int i=0;i<f;++i)
	{
		scanf("%d %d %d",&n,&m,&w);	
		yes=false;
		count=0;		
		for(int i=0;i<m;++i)
		{
			scanf("%d %d %d",&v1,&v2,&l);
			r[count].from=v1;
			r[count].to=v2;
			r[count].dis=l;
			count++;
			r[count].from=v2;          //******Âù¦V
			r[count].to=v1;
			r[count].dis=l;
			count++;
		}
		for(int i=0;i<w;++i)
		{
			scanf("%d %d %d",&v1,&v2,&l);
			r[count].from=v1;
			r[count].to=v2;
			r[count].dis=l*(-1);
			count++;
		}
		for(int s=1;s<=n;++s)
		{
			for(int i=0;i<=n;++i)
				d[i]=INF;
			d[s]=0;
			for(int i=0;i<n;++i)
			{
				change=false;
				for(int j=0;j<count;++j)
				{
					a=r[j].from;
					b=r[j].to;
					if(d[a]+r[j].dis<d[b])
					{
						d[b]=d[a]+r[j].dis;
						change=true;
					}
				}
				if(!change)
					break;
			}
			if(d[s]<0)
			{
				yes=true;
				break;
			}
		}
		if(yes)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
*/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 6000
#define MAXN 600
#define INF 9999999
int n;

struct road
{
	int from;
	int to;
	int dis;
}r[MAX];

int d[MAXN];


int main()
{
	int f,m,w,v1,v2,l,count,min,a,b;
	int i,j;
	bool flag,yes,change;
	scanf("%d",&f);
	while(f--)
	{
		scanf("%d %d %d",&n,&m,&w);	
		yes=false;
		count=0;		
		for(i=0;i<m;++i)
		{
			scanf("%d %d %d",&v1,&v2,&l);
			r[count].from=v1;
			r[count].to=v2;
			r[count].dis=l;
			count++;
			r[count].from=v2;          //******Âù¦V
			r[count].to=v1;
			r[count].dis=l;
			count++;
		}
		for(i=0;i<w;++i)
		{
			scanf("%d %d %d",&v1,&v2,&l);
			r[count].from=v1;
			r[count].to=v2;
			r[count].dis=l*(-1);
			count++;
		}

		for(i=0;i<=n;++i)
			d[i]=INF;
			
		for(i=0;i<n-1;++i)
		{
			change=false;
			for(j=0;j<count;++j)
			{
				a=r[j].from;	b=r[j].to;
				if(d[a]+r[j].dis<d[b])
				{
					d[b]=d[a]+r[j].dis;
					change=true;
				}
			}
			if(!change)
			{
				yes=true;
				break;
			}
		}
		
		if(yes)
			printf("NO\n");
		else
		{
			change=false;
			for(j=0;j<count;++j)
			{
				a=r[j].from;	b=r[j].to;
				if(d[a]+r[j].dis<d[b])
				{
					d[b]=d[a]+r[j].dis;
					change=true;
				}
			}
			if(change)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}