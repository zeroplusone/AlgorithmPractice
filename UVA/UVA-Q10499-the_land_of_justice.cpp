#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	int piece;
	while(cin>>piece)
	{
		if(piece<0)
			break;
		cout<<(100/piece)<<"%"<<endl;	
	}
	return 0;
}