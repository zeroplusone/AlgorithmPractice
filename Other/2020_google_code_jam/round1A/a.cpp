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

#define MAXN 55
int N;
string in[MAXN];

string matching(vector<int> poi, vector<int> poi2, vector<bool> passes, vector<bool> passes2) {
    string prefix = "", subfix = "";
    int pass = 0;
    
    while (pass != N)
    {
        char now = '*';
        for (int i = 0; i < N; ++i)
        {
            if (passes[i])
            {
                continue;
            }
            else if (in[i][poi[i]] == '*')
            {
                pass++;
                passes[i] = true;
            }
            else if (now == '*' || in[i][poi[i]] == now)
            {
                now = in[i][poi[i]];
                poi[i]++;
            }
            else
            {
                now = '.';
                break;
            }
        }

        if (now == '.')
        {
            prefix = "*";
            break;
        }
        else if (now == '*')
        {
            break;
        }
        else
        {
            prefix += now;
        }
    }

    pass = 0;
    
    while (pass != N)
    {
        char now = '*';
        for (int i = 0; i < N; ++i)
        {
            if (passes2[i])
            {
                continue;
            }
            else if (in[i][poi2[i]] == '*')
            {
                pass++;
                passes2[i] = true;
            }
            else if (now == '*' || in[i][poi2[i]] == now)
            {
                now = in[i][poi2[i]];
                poi2[i]--;
            }
            else
            {
                now = '.';
                break;
            }
        }

        if (now == '.')
        {
            subfix = "*";
            break;
        }
        else if (now == '*')
        {
            break;
        }
        else
        {
            subfix = now + subfix;
        }
    }

    if (prefix == "*" || subfix == "*")
    {
        return "*";
    }
    else
    {
        bool conti =false;
        for(int i=0;i<N;++i) {
            if(poi[i]==poi2[i]) {
                passes[i] = true;
                passes2[i] = true;
            } else {
                poi[i]++;
                poi2[i]--;
                passes[i] = false;
                passes2[i] = false;
                conti = true;
            }
        }
        if(conti) {
            cout<<prefix<< " "<<subfix<<endl;
            return prefix + matching(poi, poi2, passes, passes2) + subfix;
        } else {
            return prefix + subfix;
        }
    }
}

int main()
{
    int T;
    
    scanf("%d", &T);
    for (int tt = 1; tt <= T; tt++)
    {
        scanf("%d", &N);
        for(int i=0;i<N;++i) {
            cin>>in[i];
            string cut = "";
            bool lastStar =false;
            for(int j=0;j<in[i].length(); ++j) {
                if(lastStar && in[i][j]=='*') {
                    continue;
                } else if (in[i][j] == '*') {
                    lastStar = true;
                } else {
                    lastStar = false;
                }
                cut+=in[i][j];
            }
            in[i]=cut;
        }

        vector<int> poi(N);
        vector<int> poi2(N);
        for (int i = 0; i < N; ++i)
        {
            poi2[i] = in[i].length() - 1;
        }
        vector<bool> passes(N, false);
        vector<bool> passes2(N, false);
        string ans = matching(poi, poi2, passes, passes2);

        printf("Case #%d: ", tt);
        cout<<ans<<endl;
    }
}
