#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

bool per(string a)
{
	if(a=="6" || a=="28" || a=="496"|| a=="8128"|| a=="33550336"|| a=="8589869056" ||a=="137438691328")
		return true;
	else
		return false;
}

int main()
{
	int n;
	string in;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			cin>>in;
			if(per(in))
				printf("perfect\n");
			else
				printf("nonperfect\n");
		}
	}
	return 0;
}
