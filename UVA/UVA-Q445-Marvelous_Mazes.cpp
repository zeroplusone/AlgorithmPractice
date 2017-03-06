#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	char c;
	int i;
	while(scanf("%c",&c)!=EOF)
	{		
		if(c=='!')
		{
			printf("\n");
		}
		else if(c==10)
		{
			printf("\n");			
		}
		else
		{
			i=0;
			while(c>='0' && c<='9')
			{
				i+=c-'0';
				scanf("%c",&c);
			}
			for(int j=0;j<i;++j)
			{
				if(c=='b')
					printf(" ");
				else
					printf("%c",c);
			}
		}
	}
	return 0;
}
/*數字表示要印出幾個後面的字母或符號 !為換行 b為空格
ps.123T TTTTTT(1+2+3)*/