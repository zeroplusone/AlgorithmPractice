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

#define MAXP 35

long long int two[MAXP];

int main()
{
    int T; scanf("%d", &T);
    long long int D;
    char P[MAXP];
    int Sbit[MAXP];
    long long int pnum, Plen, Clen;
    int i, j;
    long long int ans;
    bool success;

    two[0]=1;
    for(i=1;i<MAXP;++i){
        two[i]=two[i-1]*2;
    }

    for(int tt = 1; tt <= T; tt++){
        scanf("%lld",&D);
        getchar();
        scanf("%s",P);
        memset(Sbit, 0, sizeof(Sbit));
        success=false;

        Plen = strlen(P);
        Clen = 0; pnum=0;
        ans=0;
        for(i=0;i<Plen;++i){
            if(P[i] == 'C'){
                Clen++;
            }else if(P[i] == 'S'){
                Sbit[Clen]++;
                pnum+=two[Clen];
            }
        }
        if(pnum<=D){
            ans=0;
            success=true;
        }else{
            for(i=Clen;i>0;){
                if(Sbit[i]>0){
                    pnum-=two[i]-two[i-1];
                    ans+=1;
                    Sbit[i]--; Sbit[i-1]++;
                }else{
                    i--;
                }
                if(pnum<=D){
                    success=true;
                    break;
                }
            }
                
        }

        printf("Case #%d: ", tt);
        if(success)
            printf("%lld\n", ans);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;

}
