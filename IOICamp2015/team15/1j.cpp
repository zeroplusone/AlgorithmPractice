#include <bits/stdc++.h>
using namespace std;
int dp[301];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,S;
        scanf("%d%d",&N,&S);
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        vector<int>r;
        for(int i=0;i<N;i++){
            int x;
            scanf("%d",&x);
            r.push_back(x);
            for(int j=0;j+x<=S;j++){
                if(dp[j]>=0){
                    if(dp[j+x]==-1||dp[j+x]>dp[j]+1){
                        dp[j+x]=dp[j]+1;
                    }
                }
            }
        }
        if(dp[S]==-1)puts("impossible");
        else{
            printf("[%d]",dp[S]);
            int now=S;
            vector<int>an;
            sort(r.begin(),r.end());
            reverse(r.begin(),r.end());
            while(now){
                for(int i=0;i<r.size();i++)
                    if(now>=r[i]&&dp[now-r[i]]==dp[now]-1){
                        an.push_back(r[i]);
                        now-=r[i];
                        break;
                    }
            }
            sort(an.begin(),an.end());
            reverse(an.begin(),an.end());
            for(int i=0;i<an.size();i++)printf(" %d",an[i]);
            puts("");
        }
    }
    return 0;
}
