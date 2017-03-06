/******************
Judge   : POJ
Problem : 2492-A Bug's Life
Course  : Course8
discribe: Given a list of bug interactions, decide whether the experiment supports his assumption of two genders with no homosexual bugs or if it contains some bug interactions that falsify it.
Input   : 
			2  //t (case)
			3 3	//n #bugs r #relation
			1 2
			2 3
			1 3 
			4 2  //n #bugs r #relation
			1 2
			3 4
Output  : 
			Scenario #1:
			Suspicious bugs found!

			Scenario #2:
			No suspicious bugs found!
Solve   : disjoint set

disjoint set不是用來記錄是否是在一個集合內，而是看他們有沒有關係

*******************/

/*WA union in nou-rooted node will produce problem 
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAXN 2100
int p[MAXN];
int h[MAXN];
int son[MAXN][MAXN]; //son[i][0] save array size
void makeset(int size)
{
	for(int i=0;i<=size;++i)
	{	
		p[i]=i;
		h[i]=-1;
		son[i][0]=1;
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
	int i;
	if(h[x]<h[y])
	{
		p[x]=y;
		//add son
		i=son[y][0];
		son[y][i]=x;
		son[y][0]++;
		//add height
		h[x]++;
		for(i=1;i<son[x][0];++i)
			h[i]++;
	}
	else
	{
		p[y]=x;
		//add son
		i=son[x][0];
		son[x][i]=y;
		son[x][0]++;
		//add height
		h[y]=h[x]+1;
		for(i=1;i<son[y][0];++i)
			h[i]+=h[y];
	}	
}

int main()
{
	int t,n,r;
	int i,tt;
	int a,b,pa,pb;
	bool ok=true;
	scanf("%d",&t);
	
		for(tt=1;tt<=t;++tt)
		{
			ok=true;			
			printf("Scenario #%d:\n",tt);
			scanf("%d%d",&n,&r);
			makeset(n);
			while(r--)
			{
				scanf("%d%d",&a,&b);
				pa=findset(a);
				pb=findset(b);
				if(!ok)	continue;
				if(h[a]!=-1 && h[b]!=-1)
				{
					if(h[a]%2==h[b]%2) //same height
						ok=false;
				}
				else	//union
				{
					h[a]=h[a]==-1?0:h[a];
					h[b]=h[b]==-1?0:h[b];
					uniont(pa,pb);
				}				
			}
			printf("%s\n\n",ok?"No suspicious bugs found!":"Suspicious bugs found!");
		}
	
}
*/
//1~n one sex posibility   n+1~2n: another sex posibility
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAXN 2100
int p[2*MAXN];
int h[2*MAXN];

void makeset(int size)
{
	for(int i=0;i<=size;++i)
	{	
		p[i]=i;
		h[i]=0;
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
	if(h[x]<h[y])
	{
		p[x]=y;
	}
	else
	{
		p[y]=x;
		if(h[x]==h[y])
			h[y]++;
	}	
}

int main()
{
	int t,n,r;
	int i,tt;
	int a,b,pa,pb;
	bool ok=true;
	scanf("%d",&t);
	
		for(tt=1;tt<=t;++tt)
		{
			ok=true;			
			printf("Scenario #%d:\n",tt);
			scanf("%d%d",&n,&r);
			makeset(2*n);
			while(r--)
			{
				scanf("%d%d",&a,&b);
				if(!ok)	continue;
				pa=findset(a);
				pb=findset(b);				
				if(pa==pb) //in the same sex ,they are in same set XXX
						ok=false;
				else	//union
				{
					uniont(a,b+n);
					uniont(a+n,b);
				}				
			}
			printf("%s\n\n",ok?"No suspicious bugs found!":"Suspicious bugs found!");
		}
	
}