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
    string s;
    int k, ans;
    int T; scanf("%d", &T);
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        cin>>s;
        scanf("%d", &k);
        ans=0;
        for(int i=0;i<s.length()-k+1;++i){
            if(s[i]=='-'){
                for(int j=0;j<k;++j){
                    s[i+j]=s[i+j]=='+'?'-':'+';
                }
                ans++;
            }
        }
        for(int i=0;i<s.length();++i){
            if(s[i]=='-'){
                ans=-1;
                break;
            }
        }
        if(ans==-1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
    }


}