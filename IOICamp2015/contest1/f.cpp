#include <cstdio>
#include <cstring>
char s[4015];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        int n=strlen(s);
        memcpy(s+n,s,n);
        int i=0,j=1;
        while(i<n&&j<n){
            int len=0;
		printf("~%d %d\n",i,j);
            while(len<n&&s[i+len]==s[j+len])len++;
            if(len==n)break;
            if(s[i+len]>s[j+len])i+=len+1;
            else j+=len+1;
        }
        printf("%d\n",i<j?i:j);
    }
    return 0;
}
