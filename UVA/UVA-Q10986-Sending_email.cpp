#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 110
#define INF 1000000000

struct road
{
	int des,len;
	
};
vector<struct road> edge[MAX];
struct road tmp2;

struct release
{
	int v,l;
	bool operator<(const release& p)const
	{
		return l>p.l;
	}
}tmp;

priority_queue<struct release> pque;
int dis[MAX];
int n,m,start,end;
bool visit[MAX];

int Dijkstra(int start)
{
	int nowv,nowl,nextv;
	tmp.v=start;	tmp.l=0;
	pque.push(tmp);
	dis[start]=0;
	while(!pque.empty())
	{
		tmp=pque.top();
		pque.pop();
		nowv=tmp.v;	nowl=tmp.l;
		dis[nowv]=nowl;
		if(nowv==end)	return dis[end];
		for(int i=0;i<edge[nowv].size();++i)
		{
			nextv=edge[nowv][i].des;
			tmp.v=nextv;	
			tmp.l=nowl+edge[nowv][i].len;	
			pque.push(tmp);

		}
	}
	if(dis[end]==INF)	return -1;
	else	return dis[end];
}


void reset()
{
	for(int i=0;i<MAX;++i)	
	{
		dis[i]=INF;
		edge[i].clear();	
	}
	memset(visit,false,sizeof(visit));
	while(!pque.empty())
		pque.pop();
}

int main()
{
	int c,fromr,tor,lenr;
	scanf("%d",&c);
	for(int i=1;i<=c;++i)
	{
		scanf("%d%d%d%d",&n,&m,&start,&end);
		reset();
		
		for(int j=0;j<m;++j)
		{
			scanf("%d %d %d",&fromr,&tor,&lenr);
			tmp2.des=tor;
			tmp2.len=lenr;
			edge[fromr].push_back(tmp2);
		}
		int ans=Dijkstra(start);
		printf("Case #%d: \n",i);
		if(ans==-1)
			printf("unreachable\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}