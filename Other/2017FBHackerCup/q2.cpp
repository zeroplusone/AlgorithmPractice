#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAXN 150
int w[MAXN];

int main(){
    int tt,T,N,i,j,ans,k;
    scanf("%d",&T);
    for(tt=1;tt<=T;++tt){
        printf("Case #%d: ",tt);
        ans=0;
        scanf("%d",&N);
        for(i=0;i<N;++i){
            scanf("%d",&w[i]);
        }
        sort(w,w+N);
        for(i=N-1,j=0;i>=j;--i){
            k=50%w[i]==0?50/w[i]:50/w[i]+1;
            j+=k-1;
            if(i>=j)
                ans++;
        }
        printf("%d\n",ans);

    }
}