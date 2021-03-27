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
    int T;
    scanf("%d", &T);
    int P;
    for (int tt = 1; tt <= T; tt++)
    {
        scanf("%d", &P);
        int ans;
        vector < pair<double, pair<int, string>>> player(100);

        string s;
        for (int i = 1; i <= 100; ++i)
        {
            cin >> s;
            double correct = 0;
            for (int j = 0; j < 10000; ++j)
            {
                if (s[j] == '1')
                {
                    correct++;
                }
            }
            
            correct /= 10000.0;
            player[i - 1] = mp(correct, mp(i, s));
        }
        sort(player.begin(), player.end());

        vector<int> score(100, 0);
        for (int i = 0; i < 10000; ++i)
        {
            double correct = 0;
            for (int j = 0; j <100; ++j)
            {
                if (player[j].second.second[i]=='1')
                {
                    correct++;
                }
            }
            correct /= 100;

            for(int j=0;j<100;++j) {
                if(player[j].first>=0.5) {
                    if(correct>=0.5) {
                        if(player[j].second.second[i]=='0') {
                            score[j]++;
                        }        
                    } else{
                        if(player[j].second.second[i]=='1') {
                            score[j]++;
                        }  
                    }
                }
            }
        }

        int maxValue = 0;
        ans = 0;
        // for (int i = 0; i < 100; ++i)
        // {
        //     cout<<player[i].second.first<<" "<<player[i].first<<endl;
        // }
        for (int i = 0; i < 100; ++i)
        {
            // cout<<player[i].second.first<<" "<<score[i]<<endl;
            if (score[i] > maxValue)
            {
                maxValue = score[i];
                ans = player[i].second.first;
            }
        }

        printf("Case #%d: ", tt);
        printf("%d\n", ans);
    }
}
