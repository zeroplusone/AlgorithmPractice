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

vector<long long int> price;

int main()
{
    int n;
    LL p;
    int i;
    int T; scanf("%d", &T);
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        price.clear();
        scanf("%d",&n);
        for (int i = 0; i < 2*n; ++i)
        {
            scanf("%lld",&p);
            price.pb(p);
        }

        vector<LL>::iterator it;
        for (int j=0; j<n;++j)
        {
            it=price.begin()+j;
            price.erase(find(price.begin(), price.end(), (*it)*4/3));
        }
        for (int i = 0; i < price.size(); ++i)
        {
            printf("%lld%c", price[i], i==price.size()-1?'\n':' ');
        }
    }

    return 0;
}
