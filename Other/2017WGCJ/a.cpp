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

#define Fill(s,v) memset(s,v,sizeof(s))
#define Debug(x) cout << #x" = " << x <<endl;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

#define MAXN 150

struct ticket
{
    int x,y;
}tic[MAXN];

int main()
{
    int f,s,a,b;
    int ans;
    int T; scanf("%d", &T);
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%d%d",&f,&s);
        for (int i = 0; i < f; ++i)
        {
            scanf("%d%d",&a,&b);
            if(b<a){
                tic[i].x=b;
                tic[i].y=a;
            }else{
                tic[i].x=a;
                tic[i].y=b;
            }
        }
        set<int> cnt;
        ans=0;
        for (int i = 1; i <= s; ++i)
        {
            cnt.clear();
            for(int j=0;j<f;++j){
                if(tic[j].x==i){
                    cnt.insert(tic[j].y);
                }else if(tic[j].y==i){
                    cnt.insert(tic[j].x);
                }
            }

            if(ans<cnt.size()){
                ans=cnt.size();
            }

        }
        printf("%d\n",ans);
    }


}