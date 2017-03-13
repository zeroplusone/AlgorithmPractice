#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXC 15
char month[12][MAXC]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"}; 

int monthTrans(char* s)
{
    for(int i=0;i<12;++i)
    {
        if(!strcmp(s,month[i]))
            return i+1;
    }
    return 0;
}

int main()
{
    int tt,T;
    int m1,m2,d1,d2,y1,y2,ans;
    char monthChar[MAXC];
    scanf("%d",&T);
    for(tt=1;tt<=T;++tt)
    {
        scanf("%s %d, %d",monthChar,&d1,&y1);
        m1=monthTrans(monthChar)*100+d1;
        if(m1>229)  y1++; 
        scanf("%s %d, %d",monthChar,&d2,&y2);
        m2=monthTrans(monthChar)*100+d2;
        if(m2<229)  y2--;
        while(!((y1%4==0 && y1%100!=0) || y1%400==0))
            y1++;
        while(!((y2%4==0 && y2%100!=0) || y2%400==0))
            y2--;
        if(y2<y1)
           ans=0;
        else if(y2==y1)
            ans=(m1<=229 && m2>=229)?1:0;
        else
        {
            ans=(y2-y1)/4+1;
            //minus 100
            y1-=y1%100;
            y2-=y2%100;
            ans-=(y2-y1)/100;
            //add 400
            y1-=(y1%400);
            y2-=(y2%400);
            ans+=(y2-y1)/400;
        }
           printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
