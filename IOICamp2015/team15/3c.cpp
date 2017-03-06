#include <stdio.h>

const long long mod=1000000007;

struct node
{
    long long num[3][3];
    node() {}
    ~node() {}
    node operator*(const node& rhs) const
    {
        node tmp;
        for(int i=0; i<3; i++){
        	for(int j=0; j<3; j++){
        		tmp.num[i][j]=0;
				for(int k=0; k<3; k++){
        			tmp.num[i][j]=(tmp.num[i][j]+num[i][k]*rhs.num[k][j])%mod;
        		}
        	}
        }
        return tmp;
    }
};

node fast(node a,long long n)
{
    node ans;
    ans.num[0][0]=1;
    ans.num[0][1]=0;
    ans.num[0][2]=0;
    ans.num[1][0]=0;
    ans.num[1][1]=1;
    ans.num[1][2]=0;
    ans.num[2][0]=0;
    ans.num[2][1]=0;
    ans.num[2][2]=1;
    while(n){
        if(n&1)
            ans=a*ans;
        a=a*a;
        n>>=1;
    }
    return ans;
}

int main()
{
    int cas;
    node uni;
    uni.num[0][0]=3;
    uni.num[0][1]=2;
    uni.num[0][2]=1;
    uni.num[1][0]=1;
    uni.num[1][1]=1;
    uni.num[1][2]=0;
    uni.num[2][0]=0;
    uni.num[2][1]=0;
    uni.num[2][2]=1;
    long long n;
    scanf("%d",&cas);
    while(cas--){
        scanf("%lld",&n);
        node ini;
        ini.num[0][0]=1;
        ini.num[0][1]=0;
        ini.num[0][2]=0;
        ini.num[1][0]=0;
        ini.num[1][1]=0;
        ini.num[1][2]=0;
        ini.num[2][0]=1;
        ini.num[2][1]=0;
        ini.num[2][2]=0;
        n--;
        ini=fast(uni,n)*ini;
        printf("%lld\n",ini.num[0][0]);
    }
    return 0;
}