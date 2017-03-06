#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;

int main()
{
	map<string ,string> dia;
	string s1,s2;
	//while()
	dia["ogday"]="dog";
	dia["atcay"]="cat";
	dia["igpay"]="pig";
	dia["ootfray"]="froot";
	dia["oopslay"]="loops";

	string s;
	char in[130];
	while(gets(in))
	{
		s=string(in);
		cout<<s<<endl;
		if(dia[s]=="\0")
			printf("eh\n");
		else
			printf("%s\n",dia[s]);
	}
	return 0;
	
}