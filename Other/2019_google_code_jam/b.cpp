// fail when not formatting a pair 
// since it's gurantee that row=col
// just reverse the direction in b2.cpp
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

#define ForN(i, n) for (i = 0; i < n; i++)
#define For1N(i, n) for (i = 1; i <= n; i++)
#define ForAB(i, a, b) for (i = a; i <= b; i++)
#define ForNR(i, n) for (i = (n)-1; i >= 0; i--)
#define For1NR(i, n) for (i = n; i > 0; i--)
#define ForABR(i, a, b) for (i = b; i >= a; i--)
#define ForBE(i, s) for (i = s.begin(); i != s.end(); i++)

#define Fill(s, v) memset(s, v, sizeof(s))
#define Debug(x) cout << #x " = " << x << endl;

#define LL long long
#define LD long double
#define PR pair<int, int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

int main()
{
    int T;
    scanf("%d", &T);
    string s;
    char first;
    bool change=false;
    int len, n;
    stack<char> dir;
    for (int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d: ", tt);
        scanf("%d",&n);
        getchar();
        cin>>s;
        while(!dir.empty()){
            dir.pop();
        }
        len=s.length();
        for(int i=0;i<len;++i){
            if(dir.empty()){
                first=s[i];
                change=false;
                dir.push(s[i]);
            }else{
                if(!change){
                    dir.push(s[i]);
                    if(s[i]!=first){
                        change=true;
                    }
                }else{
                    if(s[i]==first){
                        while(!dir.empty()){
                            printf("%c",dir.top());
                            dir.pop();
                        }
                        dir.push(s[i]);
                        change = false;
                    }else{
                        dir.push(s[i]);
                    }
                }
            }
        }
        while (!dir.empty())
        {
            printf("%c", dir.top());
            dir.pop();
        }
        printf("\n");
    }
    return 0;
}