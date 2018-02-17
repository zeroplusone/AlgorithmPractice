#include <bits/stdc++.h>
using namespace std;

#define INF 1023456789
typedef pair<int,int> ii;
typedef long long ll;

#define sq(x) ((x)*(x))

//3 cards,2 cards,1 card
double state[110][110][110][5];
int n;

//cur: 0 (nothing), 1, 2
double dp(int a,int b,int c,int cur){
    if(a==n)return 0;
    if(state[a][b][c][cur]>0)return state[a][b][c][cur];
    int remaining=3*n-3*a-2*b-c;
    int card2=b;
    int card1=c*2;
    int newcard=remaining-card2-card1;
    double ans=0;
    if(cur==0){ //first card
        if(card2>0){
            ans+=(double)card2/remaining*(dp(a+1,b-1,c,0)+1);
        }
        if(card1>0){
            ans+=(double)card1/remaining*(dp(a,b+1,c-1,2)+1);
        }
        if(newcard>0){
            ans+=(double)newcard/remaining*(dp(a,b,c+1,1)+1);
        }
    }
    else if(cur==1){ //one card
        if(card2>0){
            ans+=(double)card2/remaining*(dp(a+1,b-1,c,0)+1); // 1 more move to clear 3
        }
        if(card1>2){
            ans+=(double)(card1-2)/remaining*(dp(a,b+1,c-1,0));
        }
        if(newcard>0){
            ans+=(double)newcard/remaining*(dp(a,b,c+1,0));
        }
        ans+=(double)2/remaining*dp(a,b+1,c-1,2);
    }
    else{ //two cards
        if(card2>1){
            ans+=(double)(card2-1)/remaining*(dp(a+1,b-1,c,0)+1); // 1 more move to clear 3
        }
        if(card1>0){
            ans+=(double)card1/remaining*(dp(a,b+1,c-1,0));
        }
        if(newcard>0){
            ans+=(double)newcard/remaining*(dp(a,b,c+1,0));
        }
        ans+=(double)1/remaining*(dp(a+1,b-1,c,0));
    }
    //printf("%d %d %d %d:%f\n",a,b,c,cur,ans);
    return state[a][b][c][cur]=ans;
}

int main(){
    freopen("hi.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d",&n);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    state[i][j][k][0]=-1;
                    state[i][j][k][1]=-1;
                    state[i][j][k][2]=-1;
                }
            }
        }
        printf("Case #%d: %.9f\n",t,dp(0,0,0,0));
    }
}
