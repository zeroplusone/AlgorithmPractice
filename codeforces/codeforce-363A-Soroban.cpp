#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

string s[10]={"O-|-OOOO","O-|O-OOO","O-|OO-OO","O-|OOO-O","O-|OOOO-","-O|-OOOO","-O|O-OOO","-O|OO-OO","-O|OOO-O","-O|OOOO-"};

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			cout<<s[0]<<endl;
		while(n!=0)
		{
			cout<<s[n%10]<<endl;
			n/=10;
		}
	}
	return 0;
}