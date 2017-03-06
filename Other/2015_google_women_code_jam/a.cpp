#include <cstdio>
#include <cstdlib>

int main(){
    int tt, t, n, aci;
    int i, j;
    char c;
    scanf("%d", &t);
    for(tt=1;tt<=t;++tt){
        printf("Case #%d: ",tt);
        scanf("%d", &n);
        getchar();
        for(i=0;i<n;++i){
            aci=0;
            for(j=0;j<8;++j){
                c=getchar();
                aci<<=1;
                aci=c=='I'?aci|1:aci;
            }
            c=(char)aci;
            printf("%c",c);
        }
        printf("\n");
    }
}
