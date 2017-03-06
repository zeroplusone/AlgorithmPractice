/******************
Judge   : POJ
Problem : 2367-Genealogical tree
Course  : Course7
discribe:  an order that would guarantee that every member of the Council takes the floor earlier than each of his descendants
Input   : 	
			5	//n
			0       //the children of  i th 
			4 5 1 0
			1 0
			5 3 0
			3 0
			
Output  : 	
			2 4 5 3 1
Solve   :	topological sort
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 110
bool r[MAXN][MAXN];
int ans[MAXN];
int dag[MAXN];
int v[MAXN];
int ansnum;
int n;

void DFS(int now)
{
	v[now]=1;
	for(int i=1;i<=n;++i)
	{
		if(r[now][i] && !v[i])
			DFS(i);
	}
	v[now]=2;
	ans[ansnum]=now;
	ansnum++;
}

int main()
{
	int i,tmp;
	while(scanf("%d",&n)!=EOF)
	{
		memset(r,false,sizeof(r));
		memset(ans,0,sizeof(ans));
		memset(dag,0,sizeof(dag));
		memset(v,0,sizeof(v));
		for(i=1;i<=n;++i)
		{
			while(scanf("%d",&tmp)!=EOF)
			{
				if(tmp==0)	break;
				r[i][tmp]=true;
				dag[tmp]++;
			}
		}
		ansnum=0;
		for(i=1;i<=n;++i)
			if(!dag[i])
				DFS(i);

		for(i=n-1;i>=0;--i)
			printf("%d%c",ans[i],i==0?'\n':' ');	
	}
	return 0;
}