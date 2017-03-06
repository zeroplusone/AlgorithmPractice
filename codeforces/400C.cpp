#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 110000
long long int a[MAX];

int main()
{
    int n, k;
    long long int sum, tmp, ans=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
        cin>>a[i];
    if(k==1){
        for(int i=1;i<=n;++i){
            ans+=i;
        }
    }
    else{
        for(int i=1;i<=n;++i){
            sum=0;
            for(int j=0;j<i;++j)
                sum+=a[j];
            for(int j=0;j<=n-i;++j){
                tmp=sum;
                while(tmp%k==0){
                    tmp/=k;
                    if(tmp==1){
                        ans++;
                        break;
                    }
                }
                sum-=a[j];
                sum+=a[j+i];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}