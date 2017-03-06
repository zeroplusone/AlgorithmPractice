/******************
Judge   : POJ
Problem : 1703-Find them, Catch them
Course  : Course8
discribe: 
          1. D [a] [b] 
		where [a] and [b] are the numbers of two criminals, and they belong to different gangs. 

		2. A [a] [b] 
		where [a] and [b] are the numbers of two criminals. This requires you to decide whether a and b belong to a same gang. 
Input   : 
		1	//t(case)
		5 5	//n criminals m relation
		A 1 2
		D 1 2
		A 1 2
		D 2 4
		A 1 4
Output  : 
		Not sure yet.
		In different gangs.
		In the same gang.
Solve   : disjoint set
*******************/
//WA
/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 100100
int p[2*MAXN],r[2*MAXN];
bool v[MAXN];
void makeset(int size)
{
	for(int i=0;i<=size;++i)
	{	
		p[i]=i;
		r[i]=0;
		
	}
	memset(v,false,sizeof(v));
}

int findset(int a)
{
	if(a==p[a])	return a;
	else	return p[a]=findset(p[a]);
}

void uniont(int a,int b)
{
	a=findset(a);
	b=findset(b);
	if(a!=b)
	{
		if(r[a]<r[b])
		{
			p[a]=b;
		}
		else
		{
			p[b]=a;
			if(r[a]==r[b])
				r[a]++;
		}
	}
}

int main()
{
	int t;
	int n,m;
	char c;
	int x,y;
	int fx,fy;
	int ex,ey;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		makeset(2*n+10);
		while(m--)
		{
			getchar();
			scanf("%c",&c);
			scanf("%d%d",&x,&y);
			
			fx=findset(x);	fy=findset(y);
			ex=findset(x+n);	ey=findset(y+n);
			//printf("~~%d %d %d %d\n",fx,fy,ex,ey);
			switch(c)
			{
				case 'A':
					if(n==2)	printf("In different gangs.\n"); //********
					else if(!v[x] || !v[y])
						printf("Not sure yet.\n");
					else if(fx==fy)
						printf("In the same gang.\n");
					else
						printf("In different gangs.\n");
					break;
				case 'D':
					uniont(x,y+n);
					uniont(x+n,y);
					v[x]=v[y]=true;
					break;
				
					default:
						break;
				}
			
		}
	}
	return 0;
}
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 100100
int p[2*MAXN],r[2*MAXN];

void makeset(int size)
{
	for(int i=0;i<=size;++i)
	{	
		p[i]=i;
		r[i]=0;
	}
}

int findset(int a)
{
	if(a==p[a])	return a;
	else	return p[a]=findset(p[a]);
}

void uniont(int a,int b)
{

		if(r[a]<r[b])
		{
			p[a]=b;
		}
		else
		{
			p[b]=a;
			if(r[a]==r[b])
				r[a]++;
		}
	
}

int main()
{
	int t;
	int n,m;
	char c;
	int x,y;
	int fx,fy;
	int ex,ey;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		makeset(2*n+10);
		while(m--)
		{
			getchar();
			scanf("%c",&c);
			scanf("%d%d",&x,&y);
			
			fx=findset(x);	fy=findset(y);
			ex=findset(x+n);	ey=findset(y+n);
			//printf("~~%d %d %d %d\n",fx,fy,ex,ey);
			switch(c)
			{
				case 'A':
					if(fx!=fy)
					{
						if(fx==ey || fy==ex)
							printf("In different gangs.\n");
						else
							printf("Not sure yet.\n");
					}
					else
						printf("In the same gang.\n");

					break;
				case 'D':
					if(x!=y && fx!=fy)
					{
						uniont(fx,ey);
						uniont(ex,fy);
					}
					break;
				
					default:
						break;
				}
			
		}
	}
	return 0;
}
//p[] 記錄父親節點外，r[] 記錄當前點與根節點的關係。
/*
(a, b） (b, c)  (a, c)  (r1+r2)%2   ab  bc  ac  (XOR)
   0   	  0       0        0        O   O    O
   0      1       1        1        O   X    X
   1      0       1        1        X   O    X
   1      1       0        0        X   X    O
		  */
/*		  
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 100100
int p[MAXN],r[MAXN],h[MAXN];
void makeset(int size)
{
	for(int i=0;i<=size;++i)
	{	
		p[i]=i;
		r[i]=0;
		
	}
	memset(v,false,sizeof(v));
}

int findset(int a)
{
	if(a==p[a])	return a;
	else	return p[a]=findset(p[a]);
}

void uniont(int a,int b)
{
	a=findset(a);
	b=findset(b);
	if(a!=b)
	{
		if(r[a]<r[b])
		{
			p[a]=b;
		}
		else
		{
			p[b]=a;
			if(r[a]==r[b])
				r[a]++;
		}
	}
}

int main()
{
	int t;
	int n,m;
	char c;
	int x,y;
	int fx,fy;
	int ex,ey;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		makeset(2*n+10);
		while(m--)
		{
			getchar();
			scanf("%c",&c);
			scanf("%d%d",&x,&y);
			
			fx=findset(x);	fy=findset(y);
			ex=findset(x+n);	ey=findset(y+n);
			//printf("~~%d %d %d %d\n",fx,fy,ex,ey);
			switch(c)
			{
				case 'A':
					if(n==2)	printf("In different gangs.\n"); //********
					else if(!v[x] || !v[y])
						printf("Not sure yet.\n");
					else if(fx==fy)
						printf("In the same gang.\n");
					else
						printf("In different gangs.\n");
					break;
				case 'D':
					uniont(x,y+n);
					uniont(x+n,y);
					v[x]=v[y]=true;
					break;
				
					default:
						break;
				}
			
		}
	}
	return 0;
}*/