#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

int main()
{
    int T; scanf("%d", &T);
    int N;
    for(int tt = 1; tt <= T; tt++){
        cin>>N;
        vector<int> card(N);
        for(int i=1;i<=N;++i) {
            card[i-1]=i;
        }
        double score=0;
        double total=0;
        do {
            int last=card[0];
            score++;
            cout<<card[0]<<" ";
            for(int i=1;i<N;++i) {
                if(card[i]>last) {
                    score++;
                    last=card[i];
                }
                cout<<card[i]<<" ";
            }
            cout<<endl;
            total++;
        }while(next_permutation(card.begin(), card.end()));

        double ans=score/total;
        printf("Case #%d: %lf\n", tt, ans);
//        cout<<ans<<endl;
    }

    return 0;
}
