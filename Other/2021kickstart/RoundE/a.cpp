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
    string s;
    for(int tt = 1; tt <= T; tt++){
        cin>>s;
        printf("Case #%d: ", tt);
        vector<pair<int, char>> cnt(26, make_pair(0, 'a'));
        string ans(s.length(), '.');
        for(int i=0;i<s.length();++i) {
            int index=s[i]-'a';
            cnt[index]=make_pair(cnt[index].first+1, s[i]);
        }
        sort(cnt.begin(), cnt.end());
        vector<pair<int, char>> cntUsed=cnt;
//        for(int i=0;i<26;++i) {
//            if(cnt[i].first==0) {
//                cntUsed[i]=make_pair(-1, cnt[i].second);
//            } else {
//                cntUsed[i]=cnt[i];
//            }
//        }
        if(cnt[25].first>s.length()/2) {
            printf("IMPOSSIBLE\n");
        } else {
            for(int i=25;i>=0 && cnt[i].first>0;--i) {
                int now=i-1;
                while(now>=0 && cntUsed[now].first==0) {
                    now--;
                }
                if(now==-1) {
                    now=25;
                }
                while(cnt[i].first!=0) {
                    int left=min(cnt[i].first, cntUsed[now].first);
                    cnt[i].first-=left;
                    cntUsed[now].first-=left;
                    for(int j=0;j<s.length() && left!=0;++j) {
                        if(ans[j]=='.'&&s[j]==cnt[now].second) {
                            ans[j]=cnt[i].second;
                            left--;
                        }
                    }
                    now--;
                    if(now==-1) {
                        now=25;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
