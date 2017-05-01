#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
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
#define PI acos(-1)
#define MAXN 250

struct activity{
    int st,en;
    int who;
    bool operator<(const struct activity & a)const{
        return st<a.st;
    }
}ac[MAXN];

struct duration{
    int min;
    int type;
    bool bound;
    bool endbound;
    bool operator<(const struct duration & dd)const{
        return type==dd.type?min>dd.min:type>dd.type;
    }
}d[MAXN];

int main()
{
    int T; scanf("%d", &T);
    int acn, ajn, ans;
    int sumc, sumj;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%d%d",&acn,&ajn);
        sumc=720; sumj=720;
        ans=0;
        for(int i=0;i<acn;++i){
            scanf("%d%d",&ac[i].st,&ac[i].en);
            ac[i].who=1;
        }
        for(int i=acn;i<acn+ajn;++i){
            scanf("%d%d",&ac[i].st,&ac[i].en);
            ac[i].who=2;
        }
        sort(ac,ac+(acn+ajn));
        
        int index=0;
        for(int i=0;i<acn+ajn;++i){
            if(ac[i].who==1){
                sumc-=ac[i].en-ac[i].st;
            }
            else if(ac[i].who==2){
                sumj-=ac[i].en-ac[i].st;
            }
            if(i==0){
                if(ac[i].st!=0){
                    d[index].min=ac[i].st;
                    if(ac[i].who==1){
                        d[index].type=3;
                    }else{
                        d[index].type=4;
                    }
                }
                d[index].bound=true;
                d[index].endbound=false;
                index++;
            }else{
                d[index].bound=false;
                d[index].endbound=false;
                if(ac[i-1].who==ac[i].who){
                    d[index].min=ac[i].st-ac[i-1].en;
                    if(ac[i].who==1){
                        d[index].type=3;
                    }
                    else if(ac[i].who==2){
                        d[index].type=4;
                    }
                }else{
                    d[index].min=ac[i].st-ac[i-1].en;
                    if(ac[i].who==1){
                        d[index].type=2;
                    }
                    else if(ac[i].who==2){
                        d[index].type=1;
                    }
                }
                index++;
            }
        }
        if(ac[acn+ajn-1].en!=1440){
            d[index].min=1440-ac[acn+ajn-1].en;
            if(ac[acn+ajn-1].who==1){
                d[index].type=3;
            }else{
                d[index].type=4;
            }
            d[index].bound=false;
            d[index].endbound=true;
            index++;
        }
        sort(d,d+index);
        ans=0;
        for(int i=0;i<index;++i){
            // cout<<i<<" "<<d[i].min<<" "<<d[i].type<<endl;
            // Debug(sumc)
            // Debug(sumj)
            if(d[i].type==4){
                if(sumj>=d[i].min){
                    sumj-=d[i].min;
                    if(d[i].bound){
                        ans+=1;
                    }
                }else{
                    sumc-=d[i].min-sumj;
                    sumj=0;

                    if(d[i].endbound)
                        ans+=1;
                    else
                        ans+=2;
                    
                }
            }else if(d[i].type==3){
                if(sumc>=d[i].min){
                    sumc-=d[i].min;
                    if(d[i].bound){
                        ans+=1;
                    }
                }else{
                    sumj-=d[i].min-sumc;
                    sumc=0;

                    if(d[i].endbound)
                        ans+=1;
                    else
                        ans+=2;
                    
                }
            }else if(d[i].type==2){
                if(sumc>sumj){
                    if(sumc>d[i].min){
                        sumc-=d[i].min;
                    }else{
                        sumj-=d[i].min-sumc;
                        sumc=0;
                    }
                }else{
                    if(sumj>d[i].min){
                        sumj-=d[i].min;
                    }else{
                        sumc-=d[i].min-sumj;
                        sumj=0;
                    }
                }
                ans++;
            }else{
                if(sumc>sumj){
                    if(sumc>d[i].min){
                        sumc-=d[i].min;
                    }else{
                        sumj-=d[i].min-sumc;
                        sumc=0;
                    }
                }else{
                    if(sumj>d[i].min){
                        sumj-=d[i].min;
                    }else{
                        sumc-=d[i].min-sumj;
                        sumj=0;
                    }
                }
                ans++;
            }
        }

        printf("%d\n", ans);
    }


}