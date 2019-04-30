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

#define MAXN 10010
bool prime[MAXN];
#define MAXL 110
int arr[MAXL];

void init()
{
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i < sqrt(MAXN); ++i)
    {
        if (prime[i])
        {
            for (int j = i * i; j < MAXN; j = j + i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    map<int, vector<int> > encrpy;
    init();
    int n, l, now;
    string ans;
    vector<int> candidate;
    for (int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d: ", tt);
        scanf("%d%d", &n, &l);
        candidate.clear();
        for (int i = 2; i <= n; ++i)
        {
            if (prime[i])
            {
                candidate.push_back(i);
            }
        }
        for (int i = 0; i < l; ++i)
        {
            scanf("%d", &arr[i]);
        }
        ans = "AA";
        encrpy.clear();
        for (int i = 0; i < l - 1; ++i)
        {
            ans += 'A';
            for (int j = 0; j < candidate.size(); ++j)
            {
                if (arr[i] % candidate[j] == 0 && arr[i + 1] % candidate[j] == 0)
                {
                    now = candidate[j];
                    break;
                }
            }
            encrpy[now].push_back(i+1);
            if (i == 0)
            {
                encrpy[arr[i] / now].push_back(i);
            }
            else if (i == l - 2)
            {
                encrpy[arr[i+1] / now].push_back(i+2);
            }
        }
        int cnt=0;
        for(map<int,vector<int> >::iterator it=encrpy.begin();it!=encrpy.end();++it, cnt++){
            for(vector<int>::iterator it2=it->second.begin();it2!=it->second.end();++it2){
                ans[*it2]+=cnt;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}