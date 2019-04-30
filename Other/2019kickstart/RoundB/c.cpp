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
#include <unordered_map>
using namespace std;

#define ForN(i, n) for (i = 0; i < n; i++)
#define For1N(i, n) for (i = 1; i <= n; i++)
#define ForAB(i, a, b) for (i = a; i <= b; i++)
#define ForNR(i, n) for (i = (n)-1; i >= 0; i--)
#define For1NR(i, n) for (i = n; i > 0; i--)
#define ForABR(i, a, b) for (i = b; i >= a; i--)
#define ForBE(i, s) for (i = s.begin(); i != s.end(); i++)

#define Fill(s, v) memset(s, v, sizeof(s))
#define Debug(x) cout << #x " = " << x << endl;

#define LL long long
#define LD long double
#define PR pair<int, int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

#define MAXN 100010
int A[MAXN];

int main()
{
    int T;
    int N, S;
    int ans, sum;

    scanf("%d", &T);
    unordered_map<char, int> cnt;
    for (int tt = 1; tt <= T; tt++)
    {
        scanf("%d%d", &N, &S);
        printf("Case #%d: ", tt);
        ans=0;
        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < N; ++i)
        {
            sum=0;
            cnt.clear();
            for(int j=i;j<N;++j){
                //cout<<A[j]<<" "<<cnt[A[j]]<<endl;
                cnt[A[j]]+=1;
                if(cnt[A[j]]<=S){
                    sum++;
                }else if(cnt[A[j]]==S+1){
                    sum-=S;
                }
                //cout<<i<<" "<<j<<" "<<sum<<endl;
                ans=sum>ans?sum:ans;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}