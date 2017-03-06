#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct node
{
	int v;
	int next;
};

struct node2
{
	int wh,mc;
	node2() {}
	node2(int a,int b) : wh(a),mc(b) {}
	~node2() {}
};

int get;

int ser[100005];

int col[100005];
int vis[100005][3];

node edge[600005];
int ecnt;

int head[100005];

void addedge(int u,int v)
{
	edge[ecnt].v=v;
	edge[ecnt].next=head[u];
	head[u]=ecnt++;
}

int main()
{
	int cas;
	int n,m;
//	freopen("pj.in","r",stdin);
	scanf("%d",&cas);
	while(cas--){
		ecnt=0;
		memset(head,-1,sizeof(head));
		scanf("%d %d",&n,&m);
		for(int i=1; i<=n; i++){
			scanf("%d",&ser[i]);
			if(ser[i]==0)
				ser[i]=3;
		}
		for(int i=0; i<m; i++){
			int u,v;
			scanf("%d %d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		queue<node2> que;
		memset(vis,0,sizeof(vis));
		memset(col,0,sizeof(col));
		get=0;
		que.push(node2(1,1));
		vis[1][1]=1;
		while(que.size()){
			int wh,mc;
			wh=que.front().wh;
			mc=que.front().mc;
			que.pop();
			if((ser[wh]&mc)>0 && col[wh]==0){
				get++;
				col[wh]=(ser[wh]&mc);
			}
			for(int i=head[wh]; i!=-1; i=edge[i].next){
				if(vis[edge[i].v][3^mc]==0){
					vis[edge[i].v][3^mc]=1;
					que.push(node2(edge[i].v,3^mc));
				}
			}
		}
		if(get==n){
			printf("Paul Wang Bang Bang\n");
			continue;
		}
		memset(vis,0,sizeof(vis));
		memset(col,0,sizeof(col));
		get=0; 
		que.push(node2(1,2));
		vis[1][2]=1;
		while(que.size()){
			int wh,mc;
			wh=que.front().wh;
			mc=que.front().mc;
			que.pop();
			if((ser[wh]&mc)>0 && col[wh]==0){
				get++;
				col[wh]=(ser[wh]&mc);
			}
			for(int i=head[wh]; i!=-1; i=edge[i].next){
				if(vis[edge[i].v][3^mc]==0){
					vis[edge[i].v][3^mc]=1;
					que.push(node2(edge[i].v,3^mc));
				}
			}
		}
		if(get==n){
			printf("Paul Wang Bang Bang\n");
			continue;
		}
		printf("Paul Wang Huai Huai\n");
	}
	return 0;
}
