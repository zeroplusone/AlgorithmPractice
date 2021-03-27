#include <bits/stdc++.h>
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

int maxValue(int n) {
    return (n+2)*(n-1)/2;
}

vector<int> solve(int n, int c/*, vector<vector<vector<int>>>& dp*/)
{
    if(n==2) {
        if(c==1) {
            return vector<int> {1, 2};
        } else if(c==2) {
            return vector<int> {2, 1};
        } 
    }

    // if(dp[n][c].size()!=0) {
    //     return dp[n][c];
    // }

    if(c<n-1 || c>maxValue(n)) {
        return vector<int>(0);
    }

    int lastSize = maxValue(n-1)-(n-1-1)+1;
    int mid = n-1+lastSize;
    if(c<mid) {
        vector<int> ans(n);
        ans[0]=1;
        vector<int> sub = solve(n-1, c-1);
        if(sub.size()==0) {
            return sub;
        }
        for(int i=1;i<n;++i) {
            ans[i]=sub[i-1]+1;
        }
        return ans;
    } else {
        vector<int> ans(n);
        ans[n-1]=1;
        vector<int> sub = solve(n-1, c-n);
        if(sub.size()==0) {
            return sub;
        }
        reverse(sub.begin(), sub.end());
        for(int i=0;i<n-1;++i) {
            ans[i]=sub[i]+1;
        }
        return ans;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    int N, C;
    // vector<vector<vector<int>>> dp(101, vector<vector<int>>(500000, vector<int>(0)));
    // dp[2][1] = vector<int> {1, 2};
    // dp[2][2] = vector<int> {2, 1};
    for (int tt = 1; tt <= T; tt++)
    {
        scanf("%d%d", &N, &C);
        printf("Case #%d:", tt);
        
        vector<int> ans = solve(N, C);
        if (ans.size() == 0)
        {
            printf(" IMPOSSIBLE\n");
        }
        else
        {
            for (auto d : ans)
            {
                printf(" %d", d);
            }
            printf("\n");
        }
    }
    return 0;
}

