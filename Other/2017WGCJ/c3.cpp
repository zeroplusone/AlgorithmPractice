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
char ans[MAXN][MAXN];
int main() 
{
    int d,n,tmp;
    char c;
    int T; scanf("%d", &T);
    int flag=true;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d:\n", tt);
        scanf("%d%d",&d,&n);
        flag=true;
        for (int i = 0; i < MAXN; ++i)
        {
            if(flag){
                c='O';
            }else{
                c='I';
            }
            flag=!flag;
            for (int j = 0; j < MAXN; ++j)
            {
                if(j%2==0){
                    ans[i][j]=c;
                    c=c=='O'?'I':'O';
                }else{
                    ans[i][j]='O';
                }
            }
        }

        if(n<=275){
            int test = n%3;
            if(n%3==1)
                ans[14][11]='/';
            else if(n%3==2)
                ans[14][11]=ans[14][13]='/';
            tmp=n/3;
            for (int i = 1; i < MAXN-1; ++i)
            {
                for (int j = 1; j < MAXN-1 ; j+=2)
                {
                    if(tmp!=0){
                        ans[i][j]='/';
                        tmp--;
                    }else{
                        break;
                    }
                }
            }
        }else{
            for (int i = 1; i < MAXN-1; ++i)
            {
                for (int j = 1; j < MAXN ; j+=2)
                {
                    ans[i][j]='/';
                }
            }
            tmp=n-273;

            for (int j = 1; j < MAXN ; j+=2)
            {
                    if(tmp!=0){
                        ans[0][j]='/';
                        tmp--;
                    }else{
                        break;
                    }
            }

            for (int j = 1; j < MAXN ; j+=2)
            {
                    if(tmp!=0){
                        ans[14][j]='/';
                        tmp--;
                    }else{
                        break;
                    }
            }
            
        }
        for (int i = 0; i < MAXN; ++i)
            {
                for (int j = 0; j < MAXN ; ++j)
                {
                    printf("%c",ans[i][j]);
                }
                printf("\n");
            }
    }
    return 0;

}