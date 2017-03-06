#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	string s;
	int odd,even;
	while(cin>>s)
	{
		if(s=="0")
			break;
		odd=0;
		even=0;
		for(int i=0;i<s.length();i=i+2)
		{
			odd+=s[i]-'0';
			if(i+1!=s.length())
				even+=s[i+1]-'0';
		}

		if(abs(even-odd)%11==0)
		{
			cout<<s;
			printf(" is a multiple of 11.\n");
		}
		else
		{
			cout<<s;
			printf(" is not a multiple of 11.\n");
		}	
	}
	return 0;
}