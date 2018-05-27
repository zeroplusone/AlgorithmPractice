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

#define MAXN 18

int m[MAXN][MAXN];
int edge[3];
int ans;
bool visited[MAXN];
int N;

bool check(){
    int sum=edge[0]+edge[1]+edge[2];
    int c=max(max(edge[0],edge[1]),edge[2]);
    int a=min(min(edge[0],edge[1]),edge[2]);
    int b=sum-c-a;
    if(a+b>c)
        return true;
    else 
        return false;
}

void DFS(int e){
    if(e==3){
        if(check()){
            ans++;
        }
        return;
    }
    for(int j=0;j<N;++j){
        for(int i=j+1;i<N;++i){
            if(m[j][i]!=0 && !visited[j] && !visited[i]){
                // Debug(e)
                // Debug(i)
                // Debug(j)
                edge[e]=m[j][i];
                visited[i]=true;
                visited[j]=true;
                DFS(e+1);
                edge[e]=0;
                visited[i]=false;
                visited[j]=false;
            }
        }
    }
}

int main()
{
    int T; scanf("%d", &T);
    
    for(int tt = 1; tt <= T; tt++){
        scanf("%d",&N);
        memset(m,0,sizeof(m));
        memset(visited,false,sizeof(visited));
        ans=0;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                scanf("%d",&m[i][j]);
            }
        }
        DFS(0);
        printf("Case #%d: ", tt);
        printf("%d\n", ans/6);
    }
    return 0;

}
