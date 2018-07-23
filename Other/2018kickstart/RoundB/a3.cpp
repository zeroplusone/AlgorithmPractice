// my large try - fail

#include <bits/stdc++.h>
using namespace std;

#define ForN(i,n) for (i=0; i<n; i++)
#define For1N(i,n) for (i=1; i<=n; i++)
#define ForAB(i,a,b) for (i=a; i<=b; i++)
#define ForNR(i,n) for (i=(n)-1; i>=0; i--)
#define For1NR(i,n) for (i=n; i>0; i--)
#define ForABR(i,a,b) for (i=b; i>=a; i--)
#define ForBE(i,s) for (i=s.begin(); i!=s.end(); i++)

#define Fill(s,v) memset(s,v,sizeof(s))
#define Debug(x) cout << #x" = " << x <<endl;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

#define MAXN 20
long long int digit[MAXN];
long long int sum[MAXN];
long long int num[MAXN];
long long int ten[MAXN];

int getDigit(long long int n){
    int ans=0;
    while(n>0){
        ans++;
        n/=10;
    }
    return ans;
}

long long int calAns(long long int n){
    int d = getDigit(n);
    long long int ans=0;
    if(n<9)
        return n;
    ans+=sum[d-1];
    n=n-ten[d-1]+1;
    while(n>0){
        Debug(n)
        Debug(d)
        Debug(num[d-1])
        if(n>=num[d-1]*9){
            cout<<"hi";
            ans+=digit[d];
            ans+=n%9;
            break;
        }else{
            ans+=n/(num[d-1])*digit[d-1];
            n-=n%(num[d-1]);
            d--;
        }
    }
    return ans;
}

int main()
{
    int T; scanf("%d", &T);
    long long int F, L, ans, i, tmp;
    bool hasnine;
    memset(digit, 0, sizeof(digit));
    memset(sum, 0, sizeof(sum));
    memset(num, 0, sizeof(num));
    memset(ten, 0, sizeof(ten));
    
    digit[1]=8; digit[2]=64;
    sum[1]=digit[1]; sum[2]=sum[1]+digit[2];
    num[1]=9; num[2]=num[1]*10;
    ten[0]=1; ten[1]=ten[0]*10; ten[2]=ten[1]*10;
    for(i=3;i<MAXN;++i){
        digit[i]=digit[i-1]*9;
        sum[i]=sum[i-1]+digit[i];
        num[i]=num[i-1]*10;
        ten[i]=ten[i-1]*10;
    }
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%lld%lld",&F, &L);
        long long int a=calAns(L);
        long long int b=calAns(F);

        printf("%lld %lld %lld\n",a,b ,b-a+1);
        // printf("%lld %lld %lld\n",calAns(L), calAns(F),calAns(L)-calAns(F)+1);
    }


}
