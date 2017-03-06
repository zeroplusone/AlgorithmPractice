/******************
Judge   : UVA
Problem : 455-Periodic Strings
Course  : Course 16
discribe: print the periodic of string
Input   :1

         HoHoHo
Solve   :2 
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAXS 100
char str[MAXS];
int fail[MAXS];

void build_fail(int len)
{
        int cur=fail[0]=-1;
        for(int i=1;i<len;++i)
        {
            while(cur!=-1 && str[cur+1]!=str[i])
            {
                    cur=fail[cur];
            }
            if(str[cur+1]==str[i])
                cur++;
            fail[i]=cur;
        }
        fail[len-1]++;
}

int main()
{
    int t,len;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        getchar();
        memset(fail,-1,sizeof(fail));
        gets(str);
        len=strlen(str);
        build_fail(len);
        if(len%(len-fail[len-1]))
            printf("%d\n",len);
        else
            printf("%d\n",len-fail[len-1]);
        if(t!=0)    printf("\n");
 
    }
    return 0;
}
