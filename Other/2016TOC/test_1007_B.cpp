#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAXN 35000
int c[MAXN];
int dp[MAXN];
int p[MAXN];
int p2[MAXN];

int main(){
    int T,N,ans,i,j,maxv,fmax,bmax;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        ans=0;
        fmax=0;
        bmax=N-1;
        maxv=c[0];
        memset(dp,1,sizeof(dp));
        memset(p,-1,sizeof(p));
        memset(p2,-1,sizeof(p2));
        for(i=0;i<N;++i){
            scanf("%d",&c[i]);
        }
        for(i=1;i<N;++i){
            for(j=0;j<i;++j){
                if(c[i]>c[0] && c[j]<c[i] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    p[i]=j;

                    if(c[i]>maxv){
                        maxv=c[i];
                        fmax=i;
                    }
                }
            }
        }
        maxv=c[N-1];
        memset(dp,1,sizeof(dp));
        for(i=N-2;i>=0;--i){
            for(j=N-1;j>i;--j){
                if(c[i]>c[N-1] && c[j]<c[i] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    p2[i]=j;
                    if(c[i]>maxv){
                        maxv=c[i];
                        bmax=i;
                    }
                }
            }
        }
      
       /* 
        for(i=0;i<N;++i)
            printf("%d%c",c[i],i==N-1?'\n':' ');
        printf("%d %d\n",fmax,bmax);
        for(i=0;i<N;++i)
            printf("%d%c",p[i],i==N-1?'\n':' ');
        for(i=0;i<N;++i)
            printf("%d%c",p2[i],i==N-1?'\n':' ');
        */
        for(i=fmax;i!=-1;i=p[i]){
            if(p[i]==-1){    
                for(j=0;j<i;++j){
                    ans+=c[0]-c[j];
                }
            }
            else{
                for(j=p[i]+1;j<i;++j){
                    ans+=c[p[i]]-c[j];
                }
            }
        }
        for(i=bmax;i!=-1;i=p2[i]){
            if(p2[i]==-1){    
                for(j=N-1;j>i;--j){
                    ans+=c[N-1]-c[j];
                }
            }
            else{
                for(j=p2[i]-1;j>i;--j){
                    ans+=c[p2[i]]-c[j];
                }
            }
        }
        if(fmax!=bmax){
            for(i=fmax+1;i<bmax;++i){
                ans+=c[fmax]-c[i];
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}


