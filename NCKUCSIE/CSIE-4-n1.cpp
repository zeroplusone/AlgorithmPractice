#include<iostream>
using namespace std;

int main()
{
	int n;
	long long int ans;
	while(cin>>n)
	{
		ans=1;
		for(int i=1;i<=n;++i)
		{
			ans=ans*i;
		}
		cout<<ans<<endl;
	}
}