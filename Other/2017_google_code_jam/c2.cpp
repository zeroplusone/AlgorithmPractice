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
#define PR pair<long long int,long long int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

int main()
{
    long long int n,k,cnt;
    int T; scanf("%d", &T);
    priority_queue<PR> que;
    PR ans, tmp, tmp2;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%lld%lld",&n,&k);
        while(!que.empty()){
            que.pop();
        }
        cnt=0;
        tmp=n%2==0?mp (n/2, n/2-1):mp (n/2, n/2);
        que.push(tmp);
        while(++cnt<k && !que.empty()){
            // Debug(cnt);
            // Debug(que.size());
            tmp=que.top();
            // Debug(tmp.x);
            // Debug(tmp.y);
            que.pop();
            if(tmp.x>1){
                tmp2=tmp.x%2==0?mp (tmp.x/2, tmp.x/2-1):mp (tmp.x/2, tmp.x/2);
                que.push(tmp2);
            }
            if(tmp.y>1){
                tmp2=tmp.y%2==0?mp (tmp.y/2, tmp.y/2-1):mp (tmp.y/2, tmp.y/2);
                que.push(tmp2);
            }
        }
        if(que.empty())
            printf("0 0\n");
        else
            printf("%lld %lld\n",que.top().x, que.top().y);
    }
    return 0;
}