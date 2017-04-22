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

#define MAXN 1100
char seat[MAXN];
int num[6];
char trans[6]={'R','Y','B','O','G','V'};
int N;
#define R 0
#define Y 1
#define B 2
#define O 3
#define G 4
#define V 5

struct coloring{
    int type;
    int num;
    bool operator<(const struct coloring &c)const{
        return c.num==num?c.type>type:c.num<num;
    }
}color[3];

int main()
{
    int T; scanf("%d", &T);


    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        Fill(num,0);
        for(int i=0;i<3;++i)
            color[i].type=i;
        scanf("%d%d%d%d%d%d%d",&N,&color[R].num,&color[O].num,&color[Y].num,&color[G].num,&color[B].num,&color[V].num);
        sort(color,color+3);
        // cout<<color[0].type<<color[0].num<<endl;
        //     cout<<color[1].type<<color[1].num<<endl;
        //     cout<<color[2].type<<color[2].num<<endl<<endl;
        if(color[0].num>color[1].num+color[2].num){
            printf("IMPOSSIBLE");
        }else if(color[0].num==color[1].num+color[2].num){
            bool printmax=true;
            for(int i=0;i<N;++i){
                if(printmax){
                    printf("%c",trans[color[0].type]);
                    printmax=false;
                }else{
                    if(color[1].num!=0){
                        printf("%c",trans[color[1].type]);
                        color[1].num--;
                    }else{
                        printf("%c",trans[color[2].type]);
                    }
                    printmax=true;
                }
            }
        }else{
            int much=color[1].num+color[2].num-color[0].num;
            for(int i=0;i<much;++i){
                printf("%c%c%c",trans[color[0].type],trans[color[1].type],trans[color[2].type]);
            }
            color[1].num-=much; color[2].num-=much;
            while(color[1].num!=0){
                printf("%c%c",trans[color[0].type],trans[color[1].type]);
                color[1].num--;
            }while(color[2].num!=0){
                printf("%c%c",trans[color[0].type],trans[color[2].type]);
                color[2].num--;
            }
        }
        printf("\n");
        
    }

    return 0;
}