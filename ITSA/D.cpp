#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

//±öªá1~13   //0~12
//¤è¶ô1~13   //13~25
//¬õ¤ß1~13   //26~38
//¶Â®ç1~13   //39~51
int main()
{
	int n,ans=0,a_M=-1,a_m=13,b_M=12,b_m=26,c_M=25,c_m=39,d_M=38,d_m=52,data;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&data);
		if(data>=0 && data<=12)
		{
			if(a_M < data)
				a_M=data;
			if(a_m > data)
				a_m=data;
		}
		else if(data>=13 && data<=25)
		{
			if(b_M < data)
				b_M=data;
			if(b_m > data)
				b_m=data;
		}
		else if(data>=26 && data<=38)
		{
			if(c_M < data)
				c_M=data;
			if(c_m > data)
				c_m=data;
		}
		else
		{
			if(d_M < data)
				d_M=data;
			if(d_m > data)
				d_m=data;
		}
	}
	//printf("%d %d %d %d\n",a_m,a_M,b_m,b_M);
	//printf("%d %d %d %d\n",c_m,c_M,d_m,d_M);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&data);
		if(data>=0 && data<=12)
		{
			if(data==a_m-1 || data==a_M+1)
				ans++;
		}
		else if(data>=13 && data<=25)
		{
			if(data==b_m-1 || data==b_M+1)
				ans++;
		}
		else if(data>=26 && data<=38)
		{
			if(data==c_m-1 || data==c_M+1)
				ans++;
		}
		else
		{
			if(data==d_m-1 || data==d_M+1)
				ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}