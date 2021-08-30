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
    for (int tt = 1; tt <= T; tt++) {
        printf("Case #%d: ", tt);
        string S;
        cin>>S;
        unordered_set<char> vowels {'A', 'E', 'I', 'O', 'U'};
        int ans=1e9;
        for (int i = 0; i < 26; ++i) {
            int cnt=0;
            char target='A'+i;
            for (int j = 0; j < S.length(); ++j) {
                if(S[j]!=target) {
                    bool isTargetVowel=vowels.count(target)!=0;
                    bool isNowVowel=vowels.count(S[j])!=0;
                    if (isTargetVowel==isNowVowel) {
                        cnt+=2;
                    } else {
                        cnt+=1;
                    }
                }
            }
            ans=min(ans, cnt);
        }


        printf("%d\n", ans);
    }
    return 0;
}
