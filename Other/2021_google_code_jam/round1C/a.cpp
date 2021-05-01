#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

int main() {
    int T;
    scanf("%d", &T);
    int N, K;
    int in;
    for (int tt = 1; tt <= T; tt++) {
        printf("Case #%d: ", tt);
        cin >> N >> K;
        set<int> P;
        for (int i = 0; i < N; ++i) {
            cin >> in;
            P.insert(in);
        }
        int last = 1;
        priority_queue<int> pq;
        last=*(P.begin());
        for (auto it=P.begin()++;it!=P.end();++it) {
            pq.push(*it-last);
            last=*it;
        }

        int front = *(P.begin())-1, end = K-last;
        int win = 0;
        win = front + end;
        int maxv=pq.top(); pq.pop();
        win=max(win, maxv-1);
        win=max(win, max(front, end)+maxv/2);
        int maxv2=pq.top(); pq.pop();
        win=max(win, maxv/2+maxv2/2);

        cout<<(double)win/K<<endl;
    }
    return 0;
}
