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

int main()
{
    int d,n;
    int T; scanf("%d", &T);
    string p,trash,p1="I/O",p2="O/I",trash1="IIO",trash2="OOI";
    int flag=0;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d:\n", tt);
        scanf("%d%d",&d,&n);
        p=p1;   trash=trash1;
        flag=0;
        for (int i = 0; i <= (n-1)/16; ++i)
        {
            if(i==(n-1)/16){
                for (int j = 0; j <= (n-1)%16; ++j)
                {
                    cout<<p;
                }
                for(int j=(n-1)%16+1;j<16;++j){
                    cout<<trash;
                }
            }
            else{
                for (int j = 0; j < 16; ++j)
                {
                    cout<<p;
                }
            }
            cout<<endl;
            flag++;
            if(flag==2){
                flag=0;
                if(p==p1){
                    p=p2;   
                    trash=trash2;
                }
                else if(p==p2){
                    p=p1;
                    trash=trash1;
                }
            }
        }
    }
    return 0;

}