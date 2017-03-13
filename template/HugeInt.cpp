#include<iostream>
#include"HugeInt.h"
using namespace std;
#define max 30

ostream &operator<<(ostream& output,const HugeInt &num)
{
   for(int i=num.len-1;i>=0;--i)
   {
      output<<num.n[i];
   }
   return output;
}

istream &operator>>(istream& input,HugeInt &num)
{
   string s;
   input>>s;
   num.len=s.size();
   for(int i=0;i<num.len;++i)
   {
      num.n[num.len-1-i]=s[i]-'0';
   }
   return input;
}

HugeInt::HugeInt(long long int num)
{
   long long int tmp=num;
   int count=0;

   while(tmp>0)
   {
        tmp/=10;
        ++count;
   }
   len=count;
   tmp=num;
   for(int j=0;j<max;j++)
      n[j]=0;
   for(int i=0;i<len;++i)
   {
      n[i]=tmp%10;
      tmp/=10;
   }
    
}

HugeInt::HugeInt(string number)
{   
   len=number.size();
   for(int j=0;j<max;j++)
      n[j]=0;
   for(int i=0;i<len;++i)
   {
      n[len-1-i]=number[i]-'0';
   }
}

HugeInt::~HugeInt()
{
   delete [] n;
}

HugeInt HugeInt::operator+(HugeInt num)
{
   HugeInt ans;
   int add=0;

   for(int i=0;i<max;++i)
   {
      ans.n[i]=n[i]+num.n[i]+add;
      if(ans.n[i]>9)
      {
        add=1;
        ans.n[i]%=10;
      }
      else
        add=0;
   }

   return ans;
} 

HugeInt HugeInt::operator-(HugeInt num)
{
  HugeInt ans;
  HugeInt tmp;
  int lock=0;
  for(int i=max-1;i>=0;--i)
  {
     if(num.n[i]>n[i])
     {  
       lock=1;
       break;
     }
     else if(num.n[i]==n[i])
       continue;
     else 
       break;
  }
  if(lock==0)
  {
    tmp.len=len;
    len=num.len;
    num.len=tmp.len;
    for(int j=0;j<max;j++)
    {
       tmp.n[j]=n[j];
       n[j]=num.n[j];
       num.n[j]=tmp.n[j];
    }  
  }
  
  int borrow=0;
  for(int k=0;k<len;++k)
  {
     ans.n[k]=n[k]-num.n[k]-borrow;
     
     if(ans.n[k]<0)
     {
       ans.n[k]=n[k]-num.n[k]-borrow+10;
       borrow=1;       
     }
     else      
        borrow=0;     
  }
  
  return ans;

} 

HugeInt HugeInt::operator*(HugeInt num)
{
    HugeInt ans;
    int tmp=0;
    for(int i=0;i<=(len+num.len+1);++i)
    {
       for(int j=i;j>=0;--j)
       {
          ans.n[i]+=n[j]*num.n[i-j];
       }
       ans.n[i]+=tmp;
       if(ans.n[i]>=10)
       {
          tmp=ans.n[i]/10;
          ans.n[i]%=10;
       }
       else 
          tmp=0;
    } 

    return ans;
} 

HugeInt HugeInt::operator/(HugeInt num)
{
   HugeInt ans;
   if(num.len>len)
     return ans;
   else
   {
     for(int i=0;i<len-num.len+1;++i)
     {
        num=num*10;
     }
     for(int k=len-num.len;k>=0;--k)
     {
        for(int j=1;j<10;++j)
        {
           if(num*j>=*this && num*j!=*this)
           {
             *this=*this-(num*(j-1));
             break;
           }
           ans.n[k]=j;
           num=num/10;
        }         
     }
    
     return ans;
 
   }
} 

const HugeInt &HugeInt::operator=(const HugeInt& right)
{
   if(&right!=this)
   {
     for(int i=0;i<max;++i)
     {
        n[i]=right.n[i];
     }
   }
    
   return *this; 
}

bool HugeInt::operator==(const HugeInt& right)const
{
    if(len!=right.len)
      return false;
    for(int i=0;i<len;++i)
    {
       if(n[i]!=right.n[i])
         return false;
    }

    return true;
}

bool HugeInt::operator!=(const HugeInt& right)const
{
    return !(*this==right);
}

bool HugeInt::operator>=(const HugeInt& right)const
{
    if(len>right.len)
      return true;
    for(int i=max-1;i>=0;--i)
    {
       if(n[i]>right.n[i])
         return true;
       else if(n[i]==right.n[i])
       {
         if(i==0)
           return true;
         continue;
       }
       else
         return false;     
    }

    return true;
}

bool HugeInt::operator<=(const HugeInt& right)const
{
   if(len<right.len)
      return true;
    for(int i=max-1;i>=0;--i)
    {
       if(n[i]<right.n[i])
         return true;
       else if(n[i]==right.n[i])
       {
         if(i==0)
           return true;
         continue;
       }
       else
         return false;     
    }

    return true;
}
