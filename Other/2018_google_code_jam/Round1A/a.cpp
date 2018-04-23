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

#define MAXN 110
int w[MAXN][MAXN];
char in[MAXN];
int numr[MAXN];
int numc[MAXN];

int main()
{
    int T; scanf("%d", &T);
    int R, C, H, V;
    int i, j, k, len, cnt;
    int avgr, avgc, avgb;
    int now, cutn, blockn, lastc, cal;
    bool success=true;
    vector<int> Hcut;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        memset(w, 0, sizeof(w));
        memset(numr, 0, sizeof(numr));
        memset(numc, 0, sizeof(numc));
        scanf("%d%d%d%d",&R, &C, &H, &V);
        getchar();
        cnt=0;
        for(i=1;i<=R;++i){
            scanf("%s", in);
            getchar();
            len=strlen(in);
            for(j=1;j<=len;++j){
                if(in[j-1]=='@'){
                    w[i][j]=1;
                    numr[i]++;
                    numc[j]++;
                    cnt++;
                }
            }
        }

        for(i=1;i<=R;++i){
            now=0;
            for(j=1;j<=C;++j){
                now+=w[i][j];
                w[i][j]=w[i-1][j]+now;            
            }
        }

        // for(i=1;i<=R;++i){

        //     for(j=1;j<=C;++j){
        //         printf("%d",w[i][j]);
        //     }
        //     printf("\n");
        // }

        avgr=cnt/(H+1);
        avgc=cnt/(V+1);
        success=true;
        Hcut.clear();
        Hcut.push_back(0);
        if(cnt==0){
            printf("POSSIBLE\n");
        }else if(cnt%((H+1)*(V+1))==0){
            avgb=cnt/((H+1)*(V+1));
            now=0; cutn=0;
            for(i=1;i<=R;++i){
                now+=numr[i];
                // Debug(now)
                // Debug(cutn)
                // Debug(avgr)
                if(now==avgr){
                    cutn++;
                    now=0;
                    Hcut.push_back(i);
                }else if(now>avgr){
                    success=false;
                    break;
                }
            }
            if(cutn!=H+1)
                success=false;
            lastc=0;
            if(success){
                now=0; cutn=0;
                for(i=1;i<=C;++i){
                    now+=numc[i];
                    // Debug(now)
                    // Debug(cutn)
                    // Debug(avgc)
                    if(now==avgc){
                        cutn++;
                        now=0;
                        blockn=0;
                        cal=0;
                        for(j=1;j<Hcut.size();++j){
                            cal=w[Hcut[j]][i]-w[Hcut[j]][lastc]-w[Hcut[j-1]][i]+w[Hcut[j-1]][lastc];
                            // Debug(cal)
                            if(cal!=avgb){
                                success=false;
                                break;
                            }
                        }
                        lastc=i;
                    }else if(now>avgc){
                        success=false;
                        break;
                    }
                }
            }
            if(success && cutn!=V+1)
                success=false;
            if(success)
                printf("POSSIBLE\n");
            else
                printf("IMPOSSIBLE\n");

        }else{
            printf("IMPOSSIBLE\n");
        }

    }
    return 0;
}
