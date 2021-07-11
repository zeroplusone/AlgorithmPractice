#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

struct stat {
    long long int st, en;
    long long int cnum;
};

bool comparator2(stat s1, stat s2) {
    return s1.cnum==s2.cnum?(s1.en-s1.st)>(s2.en-s2.st):s1.cnum>s2.cnum;
}
int main()
{
    int T; scanf("%d", &T);
    int N;
    long long int C;
    long long int L, R;
    for(int tt = 1; tt <= T; tt++){
        cin>>N>>C;
        map<long long int, pair<int, int>> edges;
        for(int i=0;i<N;++i) {
            cin>>L>>R;
            edges[L].first++;
            edges[R].second++;
        }

        vector<stat> cuts;
        long long int last=edges.begin()->first;
        int cnt=edges.begin()->second.first;
        for(auto edge:edges) {
            if(edge==*edges.begin()){
                continue;
            }
            stat now;
            now.st=last+1;
            now.en=edge.x-1;
            if(now.st<=now.en) {
                now.cnum = cnt;
                cuts.push_back(now);
            }
            cnt-=edge.y.second;
            stat now2;
            now2.st=edge.x;
            now2.en=edge.x;
            now2.cnum = cnt;
            cuts.push_back(now2);
            cnt+=edge.y.first;
            last=edge.x;
        }
        sort(cuts.begin(), cuts.end(), comparator2);

        long long int ans=N;
        long long int add=0;
        for(int i=0;i<cuts.size();++i) {
            if(C!=0) {
                add=min((cuts[i].en-cuts[i].st+1), C);
                ans+=add*cuts[i].cnum;
                C-=add;
            } else {
                break;
            }
        }
        printf("Case #%d: ", tt);
        printf("%lld\n", ans);
    }

    return 0;

}
