#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    long long int N, Nsum, ans, tmp;
    int digitNum, i, dig;
    bool digit[10];
    for(int t=1; t<=T; ++t){
        printf("Case #%d: ",t);
        digitNum = 0;
        tmp = 0;
        memset(digit, false, sizeof(digit));
        scanf("%lld", &N);
        Nsum = N;
        if(N == 0)
            ans = -1;
        else{
            for(i=1;;++i){
                tmp = Nsum;
                while(tmp!=0){
                    dig=tmp%10;
                    if(!digit[dig]){
                        //printf("@%d\n",dig);
                        digitNum++;
                        digit[dig] = true;
                    }
                    tmp/=10;
                }
                if(digitNum == 10){
                    ans = Nsum;
                    break;
                }
                Nsum += N;
            }
        }
        if(ans == -1)
            printf("INSOMNIA\n");
        else
            printf("%lld\n", ans);
    }
    return 0;
}
