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

#define MAXN 1100
#define INDEX 5
int p[MAXN];
int h[MAXN];
int x[MAXN];
int y[MAXN];
int A[INDEX], B[INDEX], C[INDEX], M[INDEX];

int Add(int a, int b, int MOD)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return (a);
}

int Mult(int a, int b, int MOD)
{
    return ((LL)a * b % MOD);
}

int main()
{
    int T; scanf("%d", &T);
    int N, K;
    int i, j,ans;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%d%d",&N, &K);
        scanf("%d%d%d%d%d%d",&p[1],&p[2],&A[1],&B[1],&C[1],&M[1]);
        scanf("%d%d%d%d%d%d",&h[1],&h[2],&A[2],&B[2],&C[2],&M[2]);
        scanf("%d%d%d%d%d%d",&x[1],&x[2],&A[3],&B[3],&C[3],&M[3]);
        scanf("%d%d%d%d%d%d",&y[1],&y[2],&A[4],&B[4],&C[4],&M[4]);
        For1N(i,4){
            A[i]=A[i]%M[i];
            B[i]=B[i]%M[i];
            C[i]=C[i]%M[i];
        }
        ForAB(i,3,N){
            p[i]=Add(Add(Mult(A[1],p[i-1],M[1]),Mult(B[1],p[i-2],M[1]),M[1]),C[1] ,M[1])+1;
            h[i]=Add(Add(Mult(A[2],h[i-1],M[2]),Mult(B[2],h[i-2],M[2]),M[2]),C[2] ,M[2])+1;
        }
        ForAB(i,3,K){
            x[i] = Add(Add(Mult(A[3], x[i - 1], M[3]), Mult(B[3], x[i - 2], M[3]), M[3]), C[3], M[3])+1;
            y[i] = Add(Add(Mult(A[4], y[i - 1], M[4]), Mult(B[4], y[i - 2], M[4]), M[4]), C[4], M[4])+1;
        }
        ans=0;
        For1N(i,K){
            For1N(j,N){
                    // Debug(i)
                    // Debug(j)
                    // Debug(x[i])
                    // Debug(y[i])
                    // Debug(p[j])
                    // Debug(h[j])
                if(x[i]>=p[j]-h[j] && x[i]<=p[j]+h[j]){
                    if(y[i]<=(h[j]-abs(x[i]-p[j]))){
                        ans++;

                        break;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
