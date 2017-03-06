#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;


#define MAXN 150
char str[MAXN];
int k[MAXN];

int main(){
    int n, len, i, ans, st;
    char pre;
    while(scanf("%d",&n)!=EOF){
        getchar();
        scanf("%s",str);
        len=strlen(str);
        ans=0;
        memset(k,0,sizeof(k));
        for(i=0;i<len;++i){
            if(str[i]=='B'){
                st=i;
                do{
                    i++;
                }while(i!=len && str[i]=='B');
                k[ans]=i-st;
                ans++;
            }
        }
        printf("%d\n",ans);
        for(i=0;i<ans;++i){
            printf("%d%c",k[i],i==ans-1?'\n':' ');
        }
    }
    return 0;
}
