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


#define MAXN 110
char tree[MAXN][MAXN];
int ans;
int n, m;

bool check(int x,int y1,int y2){
    for(int i=y1;i<=y2;++i){
        if(tree[x][i]=='.'){
            return false;
        }
    }
    return true;
}

void find(int x, int y){
    int cnt=1;
    for(int i=x+1,ii=1;i<n;++i,++ii){
        if(y-ii>=0 && y+ii<m){
            if(check(i,y-ii,y+ii)){
                cnt+=1+2*ii;
            }else{
                break;
            }
        }
    }
    ans=cnt>ans?cnt:ans;
}

int main()
{
    int T; scanf("%d", &T);
    int k;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%d%d%d",&n,&m,&k);
        ans=0;
        for(int i=0;i<n;++i){
            getchar();
            for(int j=0;j<m;++j){
                scanf("%c",&tree[i][j]);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(tree[i][j]=='#'){
                    find(i,j);
                }
            }
        }
        printf("%d\n",ans);
    }


}