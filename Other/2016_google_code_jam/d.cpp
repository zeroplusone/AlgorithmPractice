#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

long long int power(long long int K, long long int C){
    if(K==0)
        return 0;
    long long int ans=1,i;
    for(i=0;i<C;++i)
        ans*=K;
    return ans;
}

long long int Cal(long long int K, long long int C, long long int i){
    if(C == 0)
        return i;
    else
        return power(K, C)*i+Cal(K, C-1,i);
}

int main(){
	int t, tNum;
    long long int K, C, S, i;

	scanf("%d", &tNum);
	for(t = 1; t <= tNum; ++t){
		printf("Case #%d:", t);
		scanf("%lld%lld%lld",&K, &C, &S);
        
        for(i=0; i<S; ++i)
            printf(" %lld", Cal(K, C-1, i)+1);
        
		printf("\n");
	}
	return 0;
}
