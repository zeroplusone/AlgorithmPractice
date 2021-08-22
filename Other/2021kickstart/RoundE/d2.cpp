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
    double N;
    for(int tt = 1; tt <= T; tt++){
        cin>>N;
        double last=1;
        for (int i = 1; i < N; ++i) {
            last=(last*i+(last+1))/(i+1);
        }
        printf("Case #%d: %lf\n", tt, last);
    }
    return 0;
}
