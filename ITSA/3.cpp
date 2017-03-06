#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int mday[12]={31,29,31,30,31,30,31,31,30,31,30,31};
char week[7][15]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int main()
{
	int n,i,j;
	int y,m,d,dif;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;++i)
		{
			scanf("%d%d%d",&y,&m,&d);
			dif=0;
			if(y>1999 && m>0 && d>0 && m<13)
			{
				if(y%400==0 || (y%4==0 && y%100!=0))
				{
					if(d<=mday[m-1])
					{
						for(j=2000;j<y;++j)
						{
							if(j%400==0 || (j%4==0 && j%100!=0))
								dif+=366;
							else
								dif+=365;
						}
						for(j=0;j<m-1;++j)
						{
								dif+=mday[j];
						}
						dif+=d;
						printf("%s\n",week[(dif-1)%7]);
					}
					else
					{
						printf("invalid date\n");
					}
				}
				else
				{
					if(d<=day[m-1])
					{
												for(j=2000;j<y;++j)
						{
							if(j%400==0 || (j%4==0 && j%100!=0))
								dif+=366;
							else
								dif+=365;
						}
						for(j=0;j<m-1;++j)
						{
								dif+=day[j];
						}
						dif+=d;
						printf("%s\n",week[(dif-1)%7]);
					}
					else 
						printf("invalid date\n");
				}
			}
			else
			{
				printf("invalid date\n");
			}
		}
	}
	return 0;
}