#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	string s[110];   //開比題目大一點
	int i=0;
	int max=0;	
	while(getline(cin,s[i]))
	{
		if(s[i].length()>max)
			max=s[i].length();
		i++;	
			
	}
	for(int j=0;j<max;++j)
	{
		for(int k=i-1;k>=0;--k)   //i-1~~注意
		{
			if(j<s[k].length())
				printf("%c",s[k][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}