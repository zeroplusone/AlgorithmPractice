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
#include <unordered_map>
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

#define MAXN 26
string s;
unordered_map<char, int> myHash;

struct Node{
    unordered_map<char, int> h;
    Node *l, *r;

    void pull(){
        h=l->h;
        for (unordered_map<char, int>::iterator it=r->h.begin();it!=r->h.end();++it){
            h[it->first]+=it->second;
        }
    }
};

Node* build(int L, int R){
    Node* now = new Node();
    if(L==R){
        now->h[s[L]]+=1;
        return now;
    }
    int mid=(L+R)>>1;
    now->l=build(L, mid);
    now->r=build(mid+1, R);
    now->pull();
    return now;
}

void query(Node* now, int L, int R, int x, int y){
    if(x>R || y<L)  return;
    if(x<=L && y>=R){
        for (unordered_map<char, int>::iterator it = now->h.begin(); it != now->h.end(); ++it)
        {
            myHash[it->first] += it->second;
        }
        return;
    }
    int mid=(L+R)>>1;
    query(now->l, L, mid, x, y);
    query(now->r, mid+1, R, x, y);
    return;
}

int count(){
    int oddNum = 0;
    for (unordered_map<char, int>::iterator it = myHash.begin(); it != myHash.end(); ++it)
    {
        // cout<<it->first<<" "<<it->second<<endl;
        if((it->second)%2==1){
            oddNum++;
        }
    }
    return oddNum<=1;
}

int main()
{
    int T;
    scanf("%d", &T);
    int N, Q;
    int A, B;
    int ans;
    
    for (int tt = 1; tt <= T; tt++)
    {
        scanf("%d%d", &N, &Q);
        getchar();
        printf("Case #%d: ", tt);
        cin>>s;
        Node* root=build(0, N-1);
        ans=0;
        while(Q--){
            scanf("%d%d",&A, &B);
            myHash.clear();
            query(root, 0, N-1, A-1, B-1);
            ans+=count();
        }
        printf("%d\n", ans);
    }
    return 0;
}