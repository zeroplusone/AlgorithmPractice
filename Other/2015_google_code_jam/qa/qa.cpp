#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 1100

int main()
{
    int T,tt;
    int smax,sum,i,len,ans,j;
    char s[MAXN];
    scanf("%d",&T);
    for(tt=1;tt<=T;++tt)
    {
        scanf("%d",&smax);
        getchar();
        scanf("%s",s);
        sum=0;  ans=0;
        len=strlen(s);
        for(i=0;i<len;)
        {
            sum+=s[i]-'0';
            if(s[i]=='0')
            {
                ans++;
                i++;
                sum++;
            }
            else
            {
                for(j=i+1;j<=sum && sum<len;++j)
                    sum+=s[j]-'0';
                i=sum;
            }
        }
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
