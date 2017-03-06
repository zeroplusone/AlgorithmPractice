/******************
Judge   : UVA
Problem : 11686-Pick_up_sticks
Course  : Course7
discribe: calculate the order to pick up the sticks 
Input   : 
			3 2		// n sticks ~ m overlap
			1 2		//stick a lies on top of stick b. 
			2 3
			0 0		//end
Output  : 	
			1
			2
			3
Solve   :	topological sort
*******************/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

#define MAXN 100001
int n;
//bool r[MAXN][MAXN];
vector<int> r[MAXN];
int visited[MAXN];
int dag[MAXN];
int ans[MAXN];
int ansnum;
bool ya=false;
void DFS(int now)
{
	if(ya || visited[now]==2)	return;
	visited[now]=1;
	int tmp;
	for(int i=0;i<r[now].size();++i)
	{
		tmp=r[now].at(i);
			if(visited[tmp]==1)
				ya=true;

			else if(visited[tmp]==0)
				DFS(tmp);
	}
	visited[now]=2;
	ans[ansnum]=now+1;
	ansnum++;
}

int main()
{
	int m;
	int i,j;
	bool ya2=false;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)	break;
		memset(r,false,sizeof(r));
		memset(dag,0,sizeof(dag));
		memset(visited,0,sizeof(visited));
		memset(ans,0,sizeof(ans));
		for(i=0;i<=n;++i)	r[i].clear();
		ansnum=0;
		ya=false;
		
		while(m--)
		{
			scanf("%d%d",&i,&j);
			r[i-1].push_back(j-1);
			dag[j]++;
		}
		ya2=false;
		for(i=1;i<=n;++i)
		{
			if(dag[i]==0)
			{	
				DFS(i-1);
				ya2=true;
			}
		}
		if(ansnum!=n)	ya=true;
		if(!ya2 || ya)	printf("IMPOSSIBLE\n");
		else
		{	
			for(i=n-1;i>=0;--i)
				printf("%d\n",ans[i]);
		}
	}
	return 0;
}