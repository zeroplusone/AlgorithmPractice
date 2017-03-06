#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 10100
char str[MAXN],rstr[MAXN];
int len;
char c1,c2,c3;

bool mulSign(char a,char b)
{
    if(a==b)    return false;
    else if((a=='j'&&b=='i') || (a=='i'&&b=='k') || (a=='k'&& b=='j'))
        return false;
    else
        return true;
}

char mul(char a,char b)
{
    if(a=='1')
        return b;
    else if(a=='i')
    {
        switch(b)
        {
            case'1':return 'i';
            case'i':return '1';
            case'j':return 'k';
            case'k':return 'j';
        }
    }
    else if(a=='j')
    {
        switch(b)
        {
            case'1':return 'j';
            case'i':return 'k';
            case'j':return '1';
            case'k':return 'i';
        }
    }       
    else if(a=='k')
    {
        switch(b)
        {
            case'1':return 'k';
            case'i':return 'j';
            case'j':return 'i';
            case'k':return '1';
        }
    }   
    return '1';
}

int check(int a,int b,int c)
{
    int i;
    char ch='1';
    bool sign=true;
    for(i=0;i<a;++i)
    {
        ch=mul(ch,rstr[i]);
        sign^=mulSign(ch,rstr[i]);
    }
    //printf("!%c\n",ch);
    if(ch!='i')
        return 1;
    ch='1';
    for(i=a;i<b;++i)
    {
        ch=mul(ch,rstr[i]);
        sign^=mulSign(ch,rstr[i]);
    }
    //printf("!!%c\n",ch);
    if(ch!='j')
        return 2;
    ch='1';
    for(i=b;i<c;++i)
    {
        ch=mul(ch,rstr[i]);
        sign^=mulSign(ch,rstr[i]);
    }
    //printf("!!!%c\n",ch);
    if(ch!='k')
        return 3;
    if(sign)
        return 0;
    else
        return 4;
}



int main()
{
    int tt,T;
    int L,X;
    int i,j,cal;
    bool ans=false;
    scanf("%d",&T);
    for(tt=1;tt<=T;++tt)
    {
        ans=false;
        scanf("%d%d",&L,&X);
        scanf("%s",str);
        strcpy(rstr,"");
        len=L*X;
        if(L!=1)
        {
        while(X--)
            strcat(rstr,str);

        for(i=1;i<len;++i)
        {
            //jin=false;
            for(j=i+1;j<len;++j)
            {
                cal=check(i,j,leni,i>1?true:false);
                if(!cal)
                {
                    ans=true;
                    break;
                }
                else if(cal==1)
                    break;
            }
            if(ans) break;
        }
        }
        if(ans)
            printf("Case #%d: YES\n",tt);
        else
            printf("Case #%d: NO\n",tt);

    }
    return 0;
}
