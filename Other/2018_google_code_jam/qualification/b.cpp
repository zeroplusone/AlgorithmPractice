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

#define MAXN 100100

int main()
{
    int T; scanf("%d", &T);
    int n, ans;
    int v[MAXN];
    int i;
    bool done=false;
    for(int tt = 1; tt <= T; tt++){
        memset(v,0,sizeof(MAXN));
        scanf("%d",&n);
        for(i=0;i<n;++i){
            scanf("%d",&v[i]);
        }

        done=false;
        while(!done){
            done=true;
            for(i=0;i<n-2;++i){
                if(v[i]>v[i+2]){
                    done=false;
                    swap(v[i],v[i+2]);
                }
            }
        }

        ans=-1;
        for(i=1;i<n;++i){
            if(v[i]>=v[i-1]){
                continue;
            }
            else{
                ans=i-1;
                break;
            }
        }
        printf("Case #%d: ", tt);
        if(ans==-1)
            printf("OK\n");
        else
            printf("%d\n",ans);
            
    }


}
