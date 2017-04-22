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

#define MAXN 20
int d[MAXN];

int main()
{
    string s,ans;
    bool leadingzero=true;
    int T; scanf("%d", &T);
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        cin>>s;
        ans=s;
        leadingzero=true;
        for(int i=0;i<s.length();++i){
            d[i]=s[i]-'0';
        }
        for(int i=1;i<s.length();++i){
            if(d[i]<d[i-1]){
                for(int j=i;j<s.length();++j){
                    d[j]=9;
                }
                d[i-1]-=1;
                for(int j=i-1;j>=0;--j){
                    if(d[j]<d[j-1]){
                        d[j]=9;
                        d[j-1]-=1;
                    }
                }
                break;
            }
        }
        for(int i=0;i<s.length();++i){
            if(leadingzero && d[i]==0){
                continue;
            }else{
                printf("%d",d[i]);
                leadingzero=false;
            }
        }
        printf("\n");
    }


}