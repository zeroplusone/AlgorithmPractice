#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 110
int a[MAX];

int main()
{
	string a,b,killed,newp;
	cin>>a>>b;
	cout<<a<<" "<<b<<endl;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		cin>>killed>>newp;
		if(a==killed){
			a=newp;
		}else{
			b=newp;
		}
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}