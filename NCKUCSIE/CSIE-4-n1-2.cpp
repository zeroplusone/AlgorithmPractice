#include<iostream>
using namespace std;

int mult(int n)
{
	if(n==0 || n==1)
		return 1;
	return n*mult(n-1);
	
}

int main()
{
	int n;
	long long int ans;
	while(cin>>n)
	{		
		cout<<mult(n)<<endl;
	}
}

/*
bool isfind[MAXN];   //all initialized to be false
int fib[MAXN];          //all initialized to be zero

int trace(int n)
{
	if(n<=2) return 1;
	if(isfind[n]) return fib[n];
	fib[n] = trace(n-1) + trace(n-2);
	isfind[n] = true;
	return fib[n];
}

*/