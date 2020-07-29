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

#define MAXN 100
bool I[MAXN];
bool O[MAXN];
char ans[MAXN][MAXN];

int main()
{
    int T, N; 
    scanf("%d", &T);
    char input;
    for(int tt = 1; tt <= T; tt++){
        scanf("%d", &N);
        getchar();
        for(int i=0;i<N; ++i) {
            scanf("%c", &input);
            I[i]=input=='Y'?true:false;
        }
        getchar();
        for(int i=0;i<N; ++i) {
            scanf("%c", &input);
            O[i]=input=='Y'?true:false;
        }
        getchar();

        printf("Case #%d: \n", tt);
        for(int i=0;i<N;++i) {
            ans[i][i]='Y';
            for(int j=i+1; j<N;++j) {
                if (O[j-1]&&I[j] && ans[i][j-1]=='Y') {
                    ans[i][j]='Y';
                }
                else {
                    ans[i][j]='N';
                }
            }

            for(int j=i-1; j>=0;--j) {
                if (O[j+1]&&I[j] && ans[i][j+1]=='Y') {
                    ans[i][j]='Y';
                }
                else {
                    ans[i][j]='N';
                }
            }
        }

        for(int i=0;i<N;++i) {
            for(int j=0; j<N;++j) {
                printf("%c", ans[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
