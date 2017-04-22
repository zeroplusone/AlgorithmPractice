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

#define MAXN 15
char in[MAXN][MAXN];

int main()
{
    int T; scanf("%d", &T);
    int r, c;
    int i, j, k, l, m, n;
    int lastx, lasty;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d:\n", tt);
        scanf("%d%d",&r,&c);
        getchar();
        for (i = 0; i < r; ++i){
            for (j = 0; j < c; ++j){
                scanf("%c",&in[i][j]);
            }
            getchar();
        }
        lastx=0;   
        lasty=0;
        for (i = 0; i < r; ++i){
            for (j = 0; j < c; ++j){
                if(in[i][j]!='?'){
                    // Debug(lasty);
                    for (k = lastx; k <= i; ++k)
                    {
                        for (l = lasty; l <= j; ++l)
                        {
                            in[k][l]=in[i][j];
                            // Debug(k);
                            // Debug(l);
                            // Debug(in[k][l]);
                        }
                    }
                    lasty=j+1;
                }
            }
            for(m=c-1;m>=0;--m){
                if(in[i][m]!='?'){
                    for(n=m+1;n<c;++n){
                        in[i][n]=in[i][m];
                    }
                    lastx=i+1;
                    lasty=0;
                    break;
                }
            }
            
        }
        for(m=c-1;m>=0;--m){
                if(in[i][m]!='?'){
                    for(n=m+1;n<c;++n){
                        in[i][n]=in[i][m];
                    }
                    lastx=i+1;
                    lasty=0;
                    break;
                }
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