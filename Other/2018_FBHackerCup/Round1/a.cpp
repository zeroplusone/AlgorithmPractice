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

#define MOD 1000000007
#define MAXN 1100
bool m[3][MAXN];

int Mult(int a, int b)
{
    return ((LL)a * b % MOD);
}

int main()
{
    int T; scanf("%d", &T);
    int N;
    int i,j;
    int cnt;
    char c;
    int ans;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        memset(m,true,sizeof(m));
        scanf("%d",&N); getchar();
        ForN(i,3){
            ForN(j,N){
                scanf("%c",&c);
                m[i][j]=c=='.'?true:false;
            }
            getchar();
        }
        
        // entry and exit
        if (m[0][0] && m[1][0] && m[1][N - 1] && m[2][N - 1])
        {
            if(N==2){
                ans=1;
            }else if(N%2==0){
                ans=1;
                ForN(i,N/2-1){
                    cnt=0;
                    if(m[0][1+2*i]&&m[0][1+2*i+1])  cnt++;
                    if(m[2][1+2*i] && m[2][1+2*i+1])  cnt++;
                    if(cnt==0){
                        ans=0;  break;
                    }else{
                        ans=Mult(ans,cnt);
                    }
                }
            }else{
                ans=0;
            }
        }else{
            ans=0;
        }   
        printf("%d\n",ans);
    }
    return 0;
}
