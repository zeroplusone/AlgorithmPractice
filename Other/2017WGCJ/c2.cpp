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
    int d,n,tmp;
    int T; scanf("%d", &T);
    string p, p1, p2;
    int flag=0;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d:\n", tt);
        scanf("%d%d",&d,&n);
        flag=0;
        p1="O/I/O/I/O/I/O/I";
        p2="I/O/I/O/I/O/I/O";

        if(n<=7){
            for (int i = 2+2*((n-1)%7)+1; i < p1.length(); ++i)
            {
                p1[i]='/';
            }
            cout<<p1<<endl;
        }else if(n<=14){
            cout<<p1<<endl;
            for (int i = 2+2*((n-1)%7)+1; i < p2.length(); ++i)
            {
                p2[i]='/';
            }
            cout<<p2<<endl;

        }else{
            tmp=n-14;
            cout<<p1<<endl;
            cout<<p2<<endl;
            for (int i = 0; i <= (n-15)/21; ++i)
            {
                if(i==(n-1)/21){
                    Debug(tmp)
                    if(i%2==0){
                        for (int i = 2+2*((tmp-1)%7)+1; i < p1.length(); ++i)
                        {
                            p1[i]='/';
                        }
                        cout<<p1<<endl;
                    }
                    else{
                        for (int i = 2+2*((tmp-1)%7)+1; i < p2.length(); ++i)
                        {
                            p2[i]='/';
                        }
                        cout<<p2<<endl;
                    }
                }else{
                    if(i%2==0){
                        cout<<p1<<endl;
                    }
                    else{
                        cout<<p2<<endl;
                    }
                    tmp-=21;
                }
            }
        }
    }
    return 0;

}