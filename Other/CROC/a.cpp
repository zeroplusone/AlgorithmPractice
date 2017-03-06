#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
    int n,a,b;
    int i,j,num;
    while(scanf("%d%d%d",&n,&a,&b)!=EOF){
        if(n>a*b){
            printf("-1\n");
        }else{
            if(b%2==0){
                for(i=0;i<a;++i){
                    if(i%2==0){
                        for(j=0;j<b;++j){
                            num=i*b+j+1;
                            num=num>n?0:num;
                            printf("%d%c",num,j==b-1?'\n':' ');
                        }
                    }
                    else{
                        for(j=b-1;j>=0;--j){
                            num=i*b+j+1;
                            num=num>n?0:num;
                            printf("%d%c",num,j==0?'\n':' ');
                        }
                    }
                }
            }else{
                for(i=0;i<a;++i){
                    for(j=0;j<b;++j){
                        num=i*b+j+1;
                        num=num>n?0:num;
                        printf("%d%c",num,j==b-1?'\n':' ');
                    } 
                }
            }
        }
    }
    return 0;
}
