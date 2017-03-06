#include<iostream>
#include<stdlib.h>
using namespace std;

int f(int n)
{
	if(n<100||n==100)	
		return f(f(n+11));	
	else
		return (n-10);
	
	
}

int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
			break;
		cout<<"f91("<<n<<") = "<<f(n)<<endl;
	}
	return 0;
}
