#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
/*
#define MAXN 120000
bool isPrime[MAXN];
void calPrime(){
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=false;   isPrime[1]=false;
    for(int i=2;i<sqrt(MAXN);++i){
        if(isPrime[i]){
            for(int j=i*i;j<MAXN;j+=i)
                isPrime[j]=false;
        }
    }
}
*/

bool isPrime(long long int p){
    for(long long int i=2;i<sqrt(p);++i)
        if(p%i==0)
            return false;
    return true;
}
#define MAX 35
#define BASEN 11
int ansNum;
bool num[MAX];
long long int base[BASEN];

bool check(int N){
    int i,j;
    long long int pow;
    for(i=2;i<BASEN;++i){
        base[i] = 0;
        pow = 1;
        for(j=0;j<N;++j){
            base[i]+=num[j]?pow:0;
            pow*=(long long int)i;
        }
        //printf("OK %lld\n",base[i]);
        if(isPrime(base[i]))
            return false;
    }
    return true;
}

void print(int N){
    int i;
    long long int j;
    printf("%lld",base[10]);
    for(i=2;i<BASEN;++i){
        for(j=2;j<base[i];++j){
            if(base[i]%j == 0){
                printf(" %lld",j);
                break;
            }
        }
    }
    printf("\n");
}
void backTracking(int now, int N, int J){
    if(ansNum == J)    return;

    if(now == N-2){

       /* for(int i=N-1;i>=0;--i)
            printf("%d",num[i]?1:0);
        printf("  !!\n");*/
        if(check(N)){
            ansNum++;
            print(N);
        }
        return;
    }
    num[now+1]=true;
    backTracking(now+1,N,J);
    num[now+1]=false;
    backTracking(now+1,N,J);
}

int main(){
	int t, tNum;
    int N, J;
    ansNum = 0;
	scanf("%d", &tNum);
	printf("Case #1:\n");
	scanf("%d%d",&N, &J);
    memset(num,false,sizeof(num));
    num[0]=true;    num[N-1]=true;
    backTracking(0,N, J);
	return 0;
}
