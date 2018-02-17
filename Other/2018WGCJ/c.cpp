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

#define Fill(s,v) memset(s,v,sizeof(s))
#define Debug(x) cout << #x" = " << x <<endl;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

#define MAXL 150
char an[MAXL];
char bn[MAXL];
char cn[MAXL];
int main()
{
    int T; scanf("%d", &T);
    bool a=true;
    bool b=true;
    bool c=true;
    int l;
    int same=3;
    char tmp,tmp2;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        a=true;
        b=true;
        c=true;
        same=3;
        scanf("%d",&l); getchar();
        scanf("%s",an); getchar();
        scanf("%s",bn); getchar();
        scanf("%s",cn);
        
        for(int i=0;i<l;++i){
            if(same==3){
                if(an[i]==bn[i] && bn[i]==cn[i]){
                    continue;
                }else if(an[i]==bn[i] && an[i]!=cn[i]){
                    c=false;
                    tmp=cn[i];
                    tmp2=an[i];
                    same=2;
                }else if(an[i]==cn[i] && an[i]!=bn[i]){
                    b=false;
                    tmp=bn[i];
                    tmp2=an[i];
                    same=2;
                }else if(bn[i]==cn[i] && an[i]!=bn[i]){
                    a=false;
                    tmp=an[i];
                    tmp2=bn[i];
                    same=2;
                }else{
                    same=-1;
                    break;
                }
            }else if(same==2){
                if(!a){
                    if(bn[i]==cn[i])
                        continue;
                    else{
                        if(bn[i]==tmp && cn[i]==tmp2)
                            same=-2;
                        else if(cn[i]==tmp && bn[i]==tmp2)
                            same=-3;
                        else
                            same=-8;
                        break;
                    }
                }else if(!b){
                    if(an[i]==cn[i])
                        continue;
                    else{
                        if(an[i]==tmp && cn[i]==tmp2)
                            same=-4;
                        else if(cn[i]==tmp && an[i]==tmp2)
                            same=-5;
                        else
                            same=-9;
                        break;
                    }
                }else if(!c){
                    if(an[i]==bn[i])
                        continue;
                    else{
                        if(an[i]==tmp && bn[i]==tmp2)
                            same=-6;
                        else if(bn[i]==tmp && an[i]==tmp2)
                            same=-7;
                        else
                            same=-10;
                        break;
                    }
                }
            }
        }
        if(same==-1){
            printf("YES YES YES\n");
        }else if(same==-2){
            printf("NO YES NO\n");
        }else if(same==-3){
            printf("NO NO YES\n");
        }else if(same==-4){
            printf("YES NO NO\n");
        }else if(same==-5){
            printf("NO NO YES\n");
        }else if(same==-6){
            printf("YES NO NO\n");
        }else if(same==-7){
            printf("NO YES NO\n");
        }else if(same==-8){
            printf("NO YES YES\n");
        }else if(same==-9){
            printf("YES NO YES\n");
        }else if(same==-10){
            printf("YES YES NO\n");
        }else{
            printf("YES YES YES\n");
        }
    }


}