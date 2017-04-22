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

#define MAXN 30
char in[MAXN][MAXN];
bool isRow[MAXN];

int main()
{
    int T; scanf("%d", &T);
    int r, c;
    int i, j, k, l, m, n;
    int lastx, lasty, nextx, nexty;
    bool visit=false;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d:\n", tt);
        scanf("%d%d",&r,&c);
        getchar();
        Fill(isRow, false);
        for (i = 0; i < r; ++i){
            for (j = 0; j < c; ++j){
                scanf("%c",&in[i][j]);
                if(in[i][j]!='?')
                    isRow[i]=true;
            }
            getchar();
        }
        lastx=0;   
        lasty=0;
        for (i = 0; i < r; ++i){
            visit=false;
            for (j = 0; j < c; ++j){
                if(in[i][j]!='?'){
                    visit=true;
                    // Debug(lasty);
                    for(m=j+1;m<=c;++m){
                        if(m==c || in[i][m]!='?'){
                            nexty=m;
                            break;
                        }
                    }
                    for(m=i+1;m<=r;++m){
                        if(m==r || isRow[m]){
                            nextx=m;
                            break;
                        }
                    }
                    // Debug(lastx);
                    // Debug(lasty);
                    // Debug(nextx);
                    // Debug(nexty);
                    for (k = lastx; k < nextx; ++k)
                    {
                        for (l = lasty; l < nexty; ++l)
                        {
                            in[k][l]=in[i][j];
                            // Debug(k);
                            // Debug(l);
                            // Debug(in[k][l]);
                        }
                    }
                    lasty=nexty;
                }
            }
            if(visit)
                lastx=nextx;
            lasty=0;
        }
        for (i = 0; i < r; ++i){
            for (j = 0; j < c; ++j){
                printf("%c",in[i][j]);
            }
            printf("\n");
        }
    }
    return 0;

}