#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

VI e[1010];
bool vis[1010];

void DFS(int n)
{
	vis[n]=1;
	for(int i:e[n])
		if(!vis[i])
			DFS(i);
}

int main()
{
	int T,N,M,v,u;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		for(int i=1;i<=N;i++)
			e[i].clear();
		while(M--)
		{
			scanf("%d%d",&v,&u);
			e[v].pb(u);
			e[u].pb(v);
		}
		fill(vis,vis+N+1,0);
		DFS(1);
		bool yes=1;
		for(int i=1;i<=N;i++)
			if(!vis[i])
				yes=0;
		if(yes && N>1)
			puts("Chen Li Bang Bang");
		else
			puts("Chen Li Huai Huai");
	}
	return 0;
}
