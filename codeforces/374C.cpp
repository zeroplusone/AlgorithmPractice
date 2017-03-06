#include<iostream>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
#define MAXN 5100
struct nodeT{
    int end;
    int t;
}tmp;

struct answer{
    int pre;
    int totalT;
}ans[MAXN];

typedef struct nodeT nodeT;
vector<nodeT> r[MAXN];
bool visit[MAXN];

int main(){
    int n, m, T, i, ui, vi, ti;
    queue<int> que;
    int now;
    while(scanf("%d%d%d",&n,&m,&T)!=EOF){
        i=n+1;
        while(i--){
            r[i].clear();
        }
        while(!que.empty())
            que.pop();
        memset(visit, false, sizeof(visit));
        i=m;
        while(m--){
            scanf("%d%d%d",&ui,&vi,&ti);
            tmp.end=vi;
            tmp.t=ti;
            r[ui].push_back(tmp);
        }

        //BFS
        que.push(1);

        while(!que.empty()){
            now=que.front();
            que.pop();
            visit[now]=true;
            for(i=0;i<r[now].size();++i){
                r[now].at(i).end
            }
        }

    }
    return 0;
}
