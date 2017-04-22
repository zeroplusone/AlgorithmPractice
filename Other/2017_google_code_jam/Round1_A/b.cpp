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

#define MAXN 3
int r[MAXN];
#define MAXP 10
int pack[MAXN][MAXP];
int cnt[MAXN][MAXP];

int main()
{
    int T; scanf("%d", &T);
    int n, p, ans;

    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d:\n", tt);
        scanf("%d%d", &n, &p);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d",&r[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < p; ++j)
            {
                scanf("%d",&pack[i][j]);

            }
        }
        Fill(cnt,0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < p; ++j)
            {
                double kit=pack[i][j]/r[i];
                cnt[i][j]=(int)kit;
                cnt[i][j]+=kit-cnt[i][j]>=0.9?1:0;
            }
        }
        ans=0;
        if(n==1){
            for (int i = 0; i < p; ++i)
            {
                if(cnt[0][i]!=0)
                    ans++;
            }
        }else{
            sort(cnt[0],cnt[0]+p);
            sort(cnt[1],cnt[1]+p);
            int i=0;
                for (int j = 0; j < p; )
                {
                    if(cnt[0][i]==cnt[0][j]){
                        ans++;
                        i++;
                        j++;
                        break;
                    }else{
                        j++;
                    }
                }

        }
        printf("%d\n",ans);

    }
    return 0;

}