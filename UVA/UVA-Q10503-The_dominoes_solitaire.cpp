/******************
Judge   : UVA
Problem : 10503 - The dominoes solitaire
Course  : Course7
discribe:  give n space and m choice.calculate whether arrive end from start
Input   : 	
			3 //n
			4 //m
			0 1 //start ->(cannot change)
			3 4 //end ->(cannot change)
			2 1 //mid point ->(can change)
			5 6 
			2 2 
			3 2 
			2 
			4 
			0 1 
			3 4 
			1 4 
			4 4 
			3 2 
			5 6 
			0 //over
			
Output  : 	
			YES 
			NO
Solve   :	backtracking
*******************/
#include<bits/stdc++.h>
using namespace std;

int n,m;
int s,e;
#define MAXN 20
struct range
{
	int x,y;
}r[MAXN];
bool v[MAXN];
bool ok=false;

void DFS(int now,int at)
{
	if(now==n)
	{
		if(at==e)
			ok=true;
		return;
	}
	for(int i=0;i<m;++i)
	{
		if(!v[i])
		{
			v[i]=true;
			if(r[i].x==at)
			{				
				DFS(now+1,r[i].y);
			}
			if(r[i].y==at)
			{
				DFS(now+1,r[i].x);
			}
			v[i]=false;
		}
	}
}

int main()
{
	int tmp,i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		scanf("%d",&m);
		scanf("%d%d",&tmp,&s);
		scanf("%d%d",&e,&tmp);

		for(i=0;i<m;++i)
			scanf("%d%d",&r[i].x,&r[i].y);
			
		ok=false;
		memset(v,false,sizeof(v));
		DFS(0,s);
		printf("%s\n",ok?"YES":"NO");
	}
	return 0;
}
