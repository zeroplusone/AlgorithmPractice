#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 150
char s[MAX];
char nine[5];
int main()
{
	int len,i,ans;
	while(gets(s))
	{
		len=strlen(s);
		memset(nine,0,sizeof(nine));
		for(i=0;i<len;++i)
		{
			switch(s[i])
			{
				case 'n':	nine[0]++;
					break;
				case 'i':	nine[1]++;
					break;
				case'e':	nine[2]++;
					break;	
				case 't':	nine[3]++;
					break;
				default:
					break;
			}
		}
		nine[0]+=(nine[0]-1)/2;
		nine[0]/=3;
		nine[2]/=3;
		ans=9999;
		for(i=0;i<4;++i)
		{
			ans=nine[i]<ans?nine[i]:ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}