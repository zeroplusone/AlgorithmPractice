#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

typedef long long LL;

const int MOD=1000000007;
LL add(LL a,LL b){return (a+b+MOD)%MOD;}
LL mul(LL a,LL b){return (a*b%MOD+MOD)%MOD;}

struct Mat
{
	LL x[2][2];
	Mat(LL a=0,LL b=0,LL c=0,LL d=0)
	{
		x[0][0]=a;x[0][1]=b;x[1][0]=c;x[1][1]=d;
	}
	Mat operator*(const Mat& A)const
	{
		Mat res=Mat(0,0,0,0);
		int i,j,k;
		for(i=0;i<2;++i)
		{
			for(j=0;j<2;++j)
			{
				for(k=0;k<2;++k)
				{
					res.x[i][j]=add(res.x[i][j],mul(x[i][k],A.x[k][j]));
				}
			}
		}
		return res;
	}
};

Mat MatPow(Mat A,int b)
{
	Mat ans=Mat(1,0,0,1);
	while(b)
	{
		if(b&1)	ans=ans*A;
		A=A*A;
		b>>=1;
	}
	return ans;
}

int main()
{
	int T,n;
	LL a,b,ans;
	int i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		scanf("%d",&n);
		Mat X=Mat(1,-1,1,0);	
		if(n==1)	printf("%lld\n",a<0?a+MOD:a);
		else if(n==2)	printf("%lld\n",b<0?b+MOD:b);
		else
		{
			X=MatPow(X,n-1);
			//printf("%lld %lld %lld %lld\n",X.x[0][0],X.x[0][1],X.x[1][0],X.x[1][1]);
			ans=add(mul(X.x[1][0],b),mul(X.x[1][1],a));
			printf("%lld\n",ans<0?ans+MOD:ans);
		}	
	}
	return 0;
}
