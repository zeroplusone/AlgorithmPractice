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

int main()
{
    int T, B;
    cin >> T >> B;
    for (int tt = 1; tt <= T; tt++)
    {
        string ans = "", ret;
        for (int i = 0; i <= B; ++i)
        {
            ans += '.';
        }

        char in;
        int r1 = -1, c1 = -1;
        for (int current = 0; current < B / 2;)
        {
            bool isR = false, isC = false;

            if (c1 != -1)
            {
                cout << c1 << endl;
                cin >> in;
                if (ans[c1] != in)
                {
                    isC = true;
                }
            }
            else
            {
                cout << "1" << endl;
                cin >> in;
            }

            if (r1 != -1)
            {
                cout << r1 << endl;
                cin >> in;
                if (ans[r1] != in)
                {
                    isR = isC ? false : true;
                }
                else
                {
                    isR = isC ? true : false;
                }
            }
            else
            {
                cout << "1" << endl;
                cin >> in;
            }

            if (isC)
            {
                for (int i = 1; i <= current; ++i)
                {
                    ans[i] = ans[i] == '0' ? '1' : '0';
                    ans[B-i+1] = ans[B-i+1] == '0' ? '1' : '0';
                }
            }

            char tmp;
            if (isR)
            {
                for (int i = 1; i <= current; ++i)
                {
                    tmp = ans[i];
                    ans[i] = ans[B - i + 1];
                    ans[B - i + 1] = tmp;
                }
            }

            int i;
            for (i = current+1; i <= current+4 && i<=B/2; ++i)
            {
                int ind = i;
                int cind = B - ind + 1;
                cout << ind << endl;
                cin >> in;
                ans[ind] = in;

                cout << cind << endl;
                cin >> in;
                ans[cind] = in;

                if (r1 == -1 && ans[ind] != ans[cind])
                {
                    r1 = ind;
                }

                if (c1 == -1 && ans[ind] == ans[cind])
                {
                    c1 = ind;
                }
            }
            current = i-1;
        }

        cout << ans.substr(1) << endl;
        cin >> ret;
        if (ret != "Y")
        {
            return 0;
        }
    }
    return 0;
}
