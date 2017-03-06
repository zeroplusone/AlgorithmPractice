#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

#define MAXN 2200
#define INF 999999

int dis[MAXN],inqueue[MAXN],coun[MAXN];
vector<int> adj[MAXN*2];

struct EDGE
{
	int a,b;
	int st,et,len;
	bool pass;
}e[MAXN*2];

int diff(int s,int e)
{
	if(s/100==e/100)
		return e-s;
	else
		return (60-s%100)+(e/100-(s/100+1))*60+e%100;	
}
int addtime(int s,int addt)
{
	return s/100*100+(s%100+addt)/60*100+(s%100+addt)%60;
}
int main()
{
	freopen("testdata.in","r",stdin);
	int caseN,cc;
	int n,edgeN,i,j,x,y,tmp,tran;
	int now,vsize;
	bool over=false;
	scanf("%d",&caseN);
	int qa,qb,qst,qet;
	queue<int> que;
	for(cc=1;cc<=caseN;++cc)
	{
		printf("%d\n",cc);
		scanf("%d%d",&n,&edgeN);
		for(i=0;i<=n;++i)
		{
			dis[i]=INF;
			inqueue[i]=false;
			coun[i]=0;
		}
		for(i=0;i<edgeN;++i)		
		{
			scanf("%d%d%d%d",&e[i].st,&e[i].a,&e[i].et,&e[i].b);
			e[i].len=diff(e[i].st,e[i].et);
			e[i].pass=true;
			adj[e[i].a].push_back(i);
		}
		scanf("%d%d%d%d",&qst,&qa,&qet,&qb);
		dis[qa]=0;
		

		inqueue[qa]=true;
		que.push(qa);
		over=false;
		while(!que.empty() && !over)
		{
			now=que.front();
			inqueue[now]=false;
			que.pop();
			vsize=adj[now].size();
			for(i=0;i<vsize && !over;++i)
			{
				j=adj[now][i];

				x=e[j].a;	y=e[j].b;				

					if(x==qa)
						tmp=e[j].len+diff(qst,e[j].st);

					else
					{
						tran=diff(addtime(qst,dis[x]),e[j].st);
						if(tran>=5)
							tmp=dis[x]+e[j].len+tran;
						else
						{ 
							tmp=INF;
							e[j].pass=false;
						}
					}
					if(dis[y]>tmp)
					{
						dis[y]=tmp;
						if(!inqueue[y])
						{
							que.push(y);
							inqueue[y]=true;
							coun[y]++;
							if(coun[y]>=n)	over=true;
						}
					}
			}
		}

		if(dis[qb]==INF)		
			printf("no connection\n");		
		else if(addtime(qst,dis[qb])+5>qet)
			printf("time out\n");	
		else
			printf("%04d %d\n",addtime(qst,dis[qb]),dis[qb]);	
	}
	return 0;
}
