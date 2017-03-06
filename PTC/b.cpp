#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

unsigned long long int modpow( unsigned long long int B, unsigned long long int P, unsigned long long int M )
{
    if( P == 0 )
        return 1;
    else if( P == 1 ) 
        return B%M;
    else
    {
        unsigned long long int result = modpow( B, P/2, M );
        if( P % 2 )
            return result * result * B % M; 
        else
            return result * result % M;
        
    }
}

int main()
{
	int n;
	unsigned long long int a,b,c;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%llu %llu %llu",&a,&b,&c);
		printf("%llu\n",modpow(a,c,b));
	}
	return 0;
}