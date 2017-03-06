#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 120
int lenNum[MAXN];
char str[MAXN];

int main(){
    int n, k, i, ansLen, best, worst;
    while(scanf("%d%d",&n,&k)!=EOF){
        i=n;
        getchar();
        memset(lenNum,0,sizeof(lenNum));
        best=0;
        while(i--){
            scanf("%s",str);
            lenNum[strlen(str)]++;
        }   
        scanf("%s",str);
        ansLen=strlen(str);

        for(i=0;i<ansLen;++i)
            best+=lenNum[i];
        worst=best+lenNum[ansLen];
        best++;
        best=best+(best-1)/k*5;
        worst=worst+(worst-1)/k*5;
        printf("%d %d\n",best, worst);
    }
    return 0;
}
