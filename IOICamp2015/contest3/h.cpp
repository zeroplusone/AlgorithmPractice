#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, m;
vector<int> G[200010];

int ans;
int st[200010];
bool used[200010];
void dfs(int root, int lev = 0, int num = 0)
{
	  used[root] = true;
    st[lev] = root;
    int tmp = 1;
    for(; tmp<=num; ++tmp)
    {
        int i = lower_bound(G[root].begin(), G[root].end(), st[lev-tmp]) - G[root].begin();
        if(i==G[root].size() || G[root][i] != st[lev-tmp])
            break;
    }
    ans = max(ans, tmp);
	printf("root %d lev %d tmp %d ans %d\n",root,lev,tmp,ans);
  
    for(int i=0; i<G[root].size(); ++i)
        if(!used[G[root][i]])
            dfs(G[root][i], lev+1, tmp);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T-->0)
    {
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; ++i) G[i].clear();
        while(m-->0)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        ans = 0;
        for(int i=0; i<n; ++i)
        {
            used[i] = false;
            sort(G[i].begin(), G[i].end());
        }
        for(int i=0; i<n; ++i)
            if(!used[i]) dfs(i);
        printf("%d\n", ans);
    }
}
