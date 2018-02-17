#include <bits/stdc++.h>
using namespace std;

#define INF 1023456789
typedef pair<int,int> ii;
typedef long long ll;

#define sq(x) ((x)*(x))


int main(){
    freopen("hi.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n;
        scanf("%d",&n);
        ll people=0;
        ll a,b;
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&a,&b);
            if(b==0){
                people+=a;
            }
            else{
                //a*b edges
                people-=min(people,a*b);
                people+=a;
            }
        }
        printf("Case #%d: %lld\n",t,max(b+1,people));
    }
}
