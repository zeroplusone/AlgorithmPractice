#include <bits/stdc++.h>
using namespace std;
#define LL long long
int n;
LL d[22];
LL need;
int used[22];
bool dfs(int x,LL r,int K){
    if(K==0)return 1;
    if(r==0)return dfs(0,need,K-1);
    if(x>=n)return 0;
    if(r==need){
        while(used[x])x++;
        used[x]=1;
        if(dfs(x+1,need-d[x],K))return 1;
        used[x]=0;
    }
    else{
        if(used[x])return dfs(x+1,r,K);
        if(r>=d[x]){
            used[x]=1;
            if(dfs(x+1,r-d[x],K))return 1;
            used[x]=0;
        }
        if(dfs(x+1,r,K))return 1;
    }
    return 0;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int K;
        scanf("%d%d",&n,&K);
        LL sum=0,ma=0;
        for(int i=0;i<n;i++){
            cin>>d[i];
            sum+=d[i];
            ma=max(ma,d[i]);
        }
        if(sum%K||ma>sum/K)puts("no");
        else if(sum==0&&K>n)puts("no");
        else{
            for(int i=0;i<n;i++)used[i]=0;
            need=sum/K;
            if(dfs(0,need,K))puts("yes");
            else puts("no");
        }
    }
    return 0;
}
