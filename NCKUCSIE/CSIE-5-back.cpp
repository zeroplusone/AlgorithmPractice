#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while(cin>>s)
	{
		int flag=0;
		for(int i=s.length()-1;i>=0;--i)
		{
			if(s[i]!='0' && flag==0)
				flag=1;
			if(s[i]=='0' && flag==0)
				continue;
			cout<<s[i];	
		}
		cout<<endl;
	}
	return 0;
}