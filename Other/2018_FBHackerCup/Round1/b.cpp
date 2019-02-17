#include <bits/stdc++.h>
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

#define MAXN 2200

struct NODE
{
    int l, r;
} node[MAXN];
int pre[MAXN], post[MAXN];
int p[MAXN], prank[MAXN];

int preorder(int root, int index)
{
    pre[index++] = root;
    if (node[root].l != 0)
    {
        index = preorder(node[root].l, index);
    }
    if (node[root].r != 0)
    {
        index = preorder(node[root].r, index);
    }
    return index;
}

int postorder(int root, int index)
{
    if (node[root].l != 0)
    {
        index = postorder(node[root].l, index);
    }
    if (node[root].r != 0)
    {
        index = postorder(node[root].r, index);
    }
    post[index++] = root;
    return index;
}

void MakeSet(int x)
{
    p[x] = x;
    prank[x] = 0;
}

int FindSet(int x)
{
    if (x != p[x])
        p[x] = FindSet(p[x]);
    return p[x];
}

void Link(int x, int y)
{
    if (prank[x] > prank[y])
        p[y] = x;
    else
    {
        p[x] = y;
        if (prank[x] == prank[y])
            prank[y]++;
    }
}

void Union(int x, int y)
{
    Link(FindSet(x), FindSet(y));
}

int main()
{
    int T;
    scanf("%d", &T);
    int N, K;
    int i, labelNum;
    map<int,int> leader;
    for (int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d:", tt);
        scanf("%d%d", &N, &K);
        For1N(i, N)
        {
            scanf("%d%d", &node[i].l, &node[i].r);
        }
        preorder(1, 0);
        postorder(1, 0);
        For1N(i,N){
            MakeSet(i);
        }
        ForN(i, N)
        {
            Union(pre[i], post[i]);
        }
        labelNum=0;
        leader.clear();
        For1N(i,N){
            // Debug(i)
            // Debug(p[i])
            // Debug(prank[i])
            if(p[i]==i){
                leader[i]=labelNum;
                labelNum++;
            }
        }
        if(labelNum>=K){
            For1N(i, N)
            {
                printf(" %d", leader[FindSet(i)]%K+1);
            }
            printf("\n");
        }else{
            printf(" Impossible\n");
        }
    }
    return 0;
}