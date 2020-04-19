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

#define MAXN 55
int matrix[MAXN][MAXN];

int main()
{
    int T; scanf("%d", &T);
    int N, K;
    for(int tt = 1; tt <= T; tt++){
        bool hasSol = true;
        scanf("%d%d",&N, &K);

        if(K==(1+N)*N/2 && N>2) {
            for (int i = 0; i < N; ++i)
            {
                matrix[i][i] = N-i;
                for (int j = 1; j < N; ++j)
                {
                    matrix[i][(i+j)%N] = (N-i+j)%N==0? N: (N-i+j)%N;
                    // matrix[i][(j + i) % N] = (N - (i + j)) % N==0? N:(N - (i+j))%N;
                }
            }
        } else 
        if (K>=N && K%N==0){
            int dia = K/N;
            for(int i=0;i<N;++i) {
                for(int j=0;j<N;++j) {
                    matrix[i][(j+i)%N]=(dia+j)%N==0? N: (dia+j)%N;
                }
            }
        } else {
            hasSol = false;
        }

        printf("Case #%d: ", tt);
        if(hasSol) {
            cout<<"POSSIBLE"<<endl;
            for(int i=0;i<N;++i) {
                for(int j=0;j<N;++j) {
                    cout<<matrix[i][j];
                    if(j==N-1){
                        cout<<endl;
                    }else {
                        cout<<" ";
                    }
                }
            }
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}
