#include <bits/stdc++.h>
using namespace std;

#define ForN(i,n) for (i=0; i<n; i++)
#define For1N(i,n) for (i=1; i<=n; i++)
#define ForAB(i,a,b) for (i=a; i<=b; i++)
#define ForNR(i,n) for (i=(n)-1; i>=0; i--)
#define For1NR(i,n) for (i=n; i>0; i--)
#define ForABR(i,a,b) for (i=b; i>=a; i--)
#define ForBE(i,s) for (i=s.begin(); i!=s.end(); i++)

#define Fill(s,v) memset(s,v,sizeof(s))
#define Debug(x) cout << #x" = " << x <<endl;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

#define MAXN 1100
bool m[MAXN][MAXN];
bool visited[MAXN];
int ans[MAXN];
int dis[MAXN];
int ori, ori2, now;
int N;

int DFS(int node, int parent){
    visited[node]=true;
    dis[node]=now++;
    for(int i=1;i<=N;++i){
        if(m[node][i]){
            if(!visited[i] && i!=parent){
                int ret=DFS(i, node);
                if(ret!=0){
                    ans[node]=0;
                }
            }else if(i==parent){
                continue;
            }else{
                if(ori==0){
                    ori=i;
                    ans[node]=0;
                }else{
                    continue;
                }
            }
        }
    }
    return ans[node]==0?(node==ori?0:ori):0;
}

void otherVal(int node, int parent){
    visited[node]=true;
    for(int i=1;i<=N;++i){
        if(m[node][i]){
            if(!visited[i] && i!=parent){
                if(ans[i]==-1){
                    ans[i]=ans[node]+1;
                }
                otherVal(i, node);
            }else if(i==parent){
                continue;
            }else{
                if(ori2==0){
                    ori2=i;
                }else{
                    continue;
                }
            }
        }
    }
}

int main()
{
    int T; scanf("%d", &T);
    int a, b;
    for(int tt = 1; tt <= T; tt++){
        scanf("%d",&N);
        memset(m,false,sizeof(m));
        memset(visited,false,sizeof(visited));
        memset(ans,-1,sizeof(ans));
        memset(dis,0,sizeof(dis));
        now=1;
        ori=0; ori2=0;
        for(int i=0;i<N;++i){
            scanf("%d%d",&a, &b);
            m[a][b]=true;
            m[b][a]=true;
        }
        DFS(1, 0);
        memset(visited,false,sizeof(visited));
        otherVal(ori, 0);
        printf("Case #%d: ", tt);
        for(int i=1;i<=N;++i){
            printf("%d%c",ans[i],i==N?'\n':' ');
        }
    }

    return 0;
}
