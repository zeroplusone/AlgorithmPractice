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

#define MAXN 50002
// E S N W
int dir[4][2]={{0, 1}, {1, 0}, {-1,0},{0,-1}};
bitset<50001> v[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    int N, r, c, d, sr, sc;
    string s;
    map<char, bool> group;
    group['E']=true;
    group['W']=true;
    group['N']=false;
    group['S']=false;
    for (int tt = 1; tt <= T; tt++)
    {
        scanf("%d%d%d%d%d",&N, &r, &c, &sr, &sc);
        // vector<bitset<50001> > v(r+1);
        bitset<50001> b(0);
        // for(int i=0;i<r+1;++i){
        //     v.push_back(b);
        // }
        for (int i = 1; i < r + 1; ++i)
        {
            v[i].reset();
        }

        cin>>s;
        v[sr].set(sc);
        char last='x';
        group['x']=!group[s[0]];
        
        for(int i=0;i<s.length();){
            int inc=0, des=0;
            while(i<s.length() && group[last]!=group[s[i]]){
                if(s[i]=='E' || s[i]=='S'){
                    inc++;
                }else{
                    des++;
                }
                i++;
            }
            last=s[i-1];
            int indi, indd;
            // E W
            if(!group[last]){
                indi = sr;
                indd = sr;
                while (inc--)
                {
                    do{
                        indi++;
                    }while (v[indi].test(sc));
                    v[indi].set(sc);
                }
                while (des--)
                {
                    do
                    {
                        indd--;
                    } while (v[indd].test(sc));
                    v[indd].set(sc);
                }
                sr=last=='S'?indi:indd;
            }else{
                indi = sc;
                indd = sc;
                while (inc--)
                {
                    do
                    {
                        indi++;
                    } while (v[sr].test(indi));
                    v[sr].set(indi);
                }
                while (des--)
                {
                    do
                    {
                        indd--;
                    } while (v[sr].test(indd));
                    v[sr].set(indd);
                }
                sc = last == 'E' ? indi : indd;
            }
        }
        
        printf("Case #%d: ", tt);
        printf("%d %d\n", sr, sc);
    }
    return 0;
}