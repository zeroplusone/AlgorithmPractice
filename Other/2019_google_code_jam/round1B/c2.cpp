#include <bits/stdc++.h>
using namespace std;

#define ForN(i,n) for (i=0; i<n; i++)
#define For1N(i,n) for (i=1; i<=n; i++)
#define ForAB(i,a,b) for (i=a; i<=b; i++)
#define ForNR(i,n) for (i=(n)-1; i>=0; i--)
#define For1NR(i,n) for (i=n; i>0; i--)
#define ForABR(i,a,b) for (i=b; i>=a; i--)
#define ForBE(i,s) for (i=s.begin(); i!=s.end(); i++)

#define Fill(s,v) memset(s,v,sizeof(s))
#define Debug(x) cout << #x" = " << x <<endl;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

#define MAXN 100010
int c[MAXN];
int d[MAXN];

int main()
{
    int T; scanf("%d", &T);
    int N, K;
    long long int ans;
    int last;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        ans=0;  last=0;
        scanf("%d %d",&N, &K);
        for(int i=1;i<=N;++i){
            scanf("%d", &c[i]);
        }
        for (int i = 1; i <= N; ++i)
        {
            scanf("%d", &d[i]);
        }
        for (int i = 1; i <= N; ++i)
        {
            if(abs(c[i]-d[i])<=K){
                if(c[i]==0 && d[i]!=0){
                    for (int j = i - 1; j > 0; --j)
                    {
                        if (c[j]!=0 && abs(c[j] - d[i]) <= K)
                        {
                            ans+=j;
                            last=j;
                            break;
                        }
                    }
                }else if (c[i] != 0 && d[i] == 0){
                    for (int j = i - 1; j > 0; --j)
                    {
                        if (d[j]!=0 && abs(c[i] - d[j]) <= K)
                        {
                            ans += j;
                            last=j;
                            break;
                        }
                    }
                }else if(c[i]==0 && d[i]==0){
                    ans+=last;
                }else{
                    ans += i;
                    last=i;
                }
            }else{
                if(c[i]>d[i]){
                    for (int j = i - 1; j > 0; --j)
                    {
                        if (d[j]!=0 && abs(c[i] - d[j]) <= K)
                        {
                            ans += j;
                            last=j;
                            break;
                        }
                    }
                }else{
                    for (int j = i - 1; j > 0; --j)
                    {
                        if (c[j]!=0 && abs(c[j] - d[i]) <= K)
                        {
                            ans += j;
                            last=j;
                            break;
                        }
                    }
                }
                
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
