#include<iostream>
#include<stdlib.h>
#include<cstdio>
using namespace std;

int main(){
    int m,n;
    while(scanf("%d %d",&m,&n)!=EOF)
    {    
         if(n>m)
         {
			int tmp1=n;
			n=m;
			m=tmp1;
         }
         
         int left;
       
         while(n>0)
         {     
              left=m%n;              
              m=n;
              n=left;
         }
		 printf("%d\n",m);
         //cout<<m<<endl;
    }
    return 0;
}


//cin cout物件裡面有多一些檢查的運算 會TLE