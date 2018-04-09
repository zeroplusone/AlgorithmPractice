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

#define MAXP 50

int main()
{
    int T; scanf("%d", &T);
    int D, D2;
    char P[MAXP];
    int Dbit[MAXP], Sbit[MAXP];
    int Dlen, Plen, Clen, Pnum;
    int i, j;
    int ans;
    for(int tt = 1; tt <= T; tt++){
        scanf("%d",&D);
        getchar();
        scanf("%s",P);
        memset(Dbit, 0, sizeof(Dbit));
        memset(Sbit, 0, sizeof(Sbit));

        D2 = D;
        Dlen=0;
        pnum=0;
        while(D2!=0){
            Dbit[Dlen++]=1&D2;
            D2 = D2>>1;
        }

        Plen = strlen(P);
        Clen = 0;
        ForN(i, Plen){
            if(P[i] == 'C'){
                Clen++;
            }else if(P[i] == 'S'){
                Sbit[Clen]++;
                pnum+=pow()
            }
        }
        
        ansType=0;
        if(Dlen>Clen){
            ans=0;
        }else{
            for(i=0;i<Plen;++i){
                for(j=Dlen-1;j>=0;--j){
                    if(Dbit[j] == 1){
                        ans+=Sbit[j]-1>0?Sbit[j]-1:0;
                        Sbit[j-1]+=Sbit[j]-1>0?Sbit[j]-1:0;
                    }else if(Dbit[j] == 0){
                        ans+=Sbit[j]>0?Sbit[j]-1:0;
                        Sbit[j-1]+=Sbit[j]-1>0?Sbit[j]-1:0;
                    }
                }
            }
        }


        printf("Case #%d: ", tt);
        printf("%d\n", ans);
    }


}
