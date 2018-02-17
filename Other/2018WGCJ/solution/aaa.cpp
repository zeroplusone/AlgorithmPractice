#include <bits/stdc++.h>
using namespace std;

#define INF 1023456789
typedef pair<int,int> ii;
typedef long long ll;

#define sq(x) ((x)*(x))

int arr[110];

int main(){
    freopen("hi.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        int cur=0;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=sq(arr[i]-cur);
            if(i%2==1){
                cur++;
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
}
