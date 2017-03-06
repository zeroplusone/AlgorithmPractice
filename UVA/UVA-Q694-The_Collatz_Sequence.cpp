#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
   long long int a,l,tmp,c=0,count=0;   //long long int   ->TLE
   while(scanf("%lld %lld",&a,&l)!=EOF)
   {
		c++;
		count=1;
        if(a<0 || l<0)
			break;

			tmp=a;
            while(tmp!=1)
            {								
                if(tmp%2==0)
                  tmp/=2;
                else
                  tmp=tmp*3+1;
				if(tmp>l)
					break;
				count+=1;
                
            }     
              
             
       printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",c,a,l,count); 
   } 
   return 0;
}
