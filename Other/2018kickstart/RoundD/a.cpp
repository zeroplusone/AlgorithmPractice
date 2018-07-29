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

#define MAXN 500500
LL INF = 999999999999999;
int MOD;
LL N, O, D;
LL cnt, oddcnt;
LL ans;
bool isadd = false;

struct NUMBER
{
    bool isodd;
    int val;
} tmp;

queue<struct NUMBER> que;

int Add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return (a);
}

int Mult(int a, int b)
{
    return ((LL)a * b % MOD);
}

LL fun(LL num, LL ans)
{
    if (num & 1)
    {
        if (oddcnt == O)
        {
            while (!que.empty() && !(que.front().isodd))
            {
                cnt -= que.front().val;
                que.pop();
            }
            if (!que.empty())
            {
                cnt -= que.front().val;
                que.pop();
                oddcnt--;
            }
            else
            {
                return ans;
            }
        }

        while (!que.empty() && cnt + num > D)
        {
            cnt -= que.front().val;
            oddcnt -= que.front().isodd ? 1 : 0;
            que.pop();
        }

        if (cnt + num <= D)
        {
            tmp.isodd = true;
            tmp.val = num;
            que.push(tmp);
            oddcnt++;
            cnt += num;
            isadd = true;
        }
    }
    else
    {

        while (!que.empty() && cnt + num > D)
        {
            cnt -= que.front().val;
            oddcnt -= que.front().isodd ? 1 : 0;
            que.pop();
        }

        if (cnt + num <= D)
        {
            tmp.isodd = false;
            tmp.val = num;
            que.push(tmp);
            cnt += num;
            isadd = true;
        }
    }
    // Debug(cnt)
    return ans < cnt ? cnt : ans;
}

int main()
{
    int T;
    scanf("%d", &T);

    LL A, B, C, M, L;
    int X, X1, X2, S;

    int i;
    for (int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d: ", tt);
        scanf("%lld%lld%lld", &N, &O, &D);
        scanf("%d%d%lld%lld%lld%lld%lld", &X1, &X2, &A, &B, &C, &M, &L);
        MOD = M;
        ans = -INF;
        cnt = 0;
        oddcnt = 0;
        isadd = false;
        while (!que.empty())
        {
            que.pop();
        }
        if(D<0 && L==0){
            printf("IMPOSSIBLE\n");
        }else{
            A=A%MOD;    B=B%MOD;    C=C%MOD;
            ans = fun((LL)(X1 + L), ans);
            ans = fun((LL)(X2 + L), ans);
            ForAB(i, 3, N)
            {
                X = Add(Add(Mult(A, X2), Mult(B, X1)), C);
                S = X + L;
                ans = fun((LL)S, ans);
                X1 = X2;
                X2 = X;
            }
            if (!isadd)
            {
                printf("IMPOSSIBLE\n");
            }
            else
            {
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
