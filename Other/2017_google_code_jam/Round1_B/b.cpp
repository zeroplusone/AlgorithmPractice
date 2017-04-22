#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
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
char seat[MAXN];
bool done;
int num[6];
vector<vector<int> > near;
char trans[6]={'R','Y','B','O','G','V'};
int N;
#define R 0
#define Y 1
#define B 2
#define O 3
#define G 4
#define V 5

void backtracking(int now){
    if(now==N){
        for(int i=0;i<N;++i){
            printf("%c",trans[seat[i]]);
        }
        printf("\n");
        done=true;
        return;
    }
    if(done)
        return;
    for(int i=0;i<near[seat[now-1]].size();++i){
        int color=near[seat[now-1]][i];
        if(num[color]>0){
            cout<<now<<" : "<<trans[color]<<endl;
            // for(int j=0;j<6;++j){
            //     Debug(num[j])
            // }
            seat[now]=color;
            num[color]--;
            backtracking(now+1);
            num[color]++;
            if(done)
                return;
        }
    }
    return;
}

int main()
{
    int T; scanf("%d", &T);
    double addtime=0;
    vector<int> v;
    near.clear();
    //R
    v.clear();
    v.push_back(Y); v.push_back(B); v.push_back(G);
    near.push_back(v);
    //Y
    v.clear();
    v.push_back(R); v.push_back(B); v.push_back(V);
    near.push_back(v);
    //B
    v.clear();
    v.push_back(R); v.push_back(Y); v.push_back(O);
    near.push_back(v);
    //O
    v.clear();
    v.push_back(B); 
    near.push_back(v);
    //G
    v.clear();
    v.push_back(R); 
    near.push_back(v);
    //V
    v.clear();
    v.push_back(Y); 
    near.push_back(v);

    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        Fill(num,0);
        scanf("%d%d%d%d%d%d%d",&N,&num[R],&num[O],&num[Y],&num[G],&num[B],&num[V]);
        done=false;
        for(int i=0;i<6;++i){
            if(num[i]!=0){
                seat[0]=i;
                num[i]--;
                break;
            }
        }
        int maxn=max(max(num[R],num[Y]),num[B]),rest=num[R]+num[Y]+num[B]-maxn;
        if(maxn>rest)
            printf("IMPOSSIBLE\n");
        else{
            backtracking(1);
            if(!done)
                printf("IMPOSSIBLE\n");
        }
    }


}