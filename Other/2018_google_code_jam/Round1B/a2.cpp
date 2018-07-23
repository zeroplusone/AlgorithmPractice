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

#define MAXN 255
int C[MAXN];
int N, L;
struct MODNS{
    int index;
    double remain;
    bool operator<(const MODNS& p)const{
        return remain<p.remain;
    }
}modn[MAXN];

double maxans;

void findans(int now, double rnow){
    if(now==N){
        maxans=maxans<rnow?rnow:maxans;
        return;
    }
    for(int i=1;i<=L;++i){
        findans(now+1, rnow+modn[(C[i]+1)%10].remain);
    }
    return;
}

int main()
{
    int T; scanf("%d", &T);
    int sum;
    int roundn;
    double rnow;
    double divide;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        memset(C, 0, sizeof(C));
        sum=0;
        scanf("%d%d",&N, &L);
        for(int i=0;i<N;++i){
            modn[i].index=i;
            divide=(double)i/(double)N * 100;
            roundn=(int)(divide+0.5);
            if(roundn!=(int)(divide)){
                modn[i].remain=(int)(divide+0.5)-divide;
            }else{
                modn[i].remain=(-1)*(divide-(int)(divide));
            }
        }
        rnow=0;
        for(int i=1;i<=L;++i){
            scanf("%d",&C[i]);
            sum+=C[i];
            rnow+=modn[C[i]%N].remain;

        }
        maxans=-1;
        findans(sum, rnow);
        // printf("%lf %d\n",maxans, (int)(100+maxans+0.5));
        printf("%d\n", (int)(100+maxans+0.5));
    }


}
