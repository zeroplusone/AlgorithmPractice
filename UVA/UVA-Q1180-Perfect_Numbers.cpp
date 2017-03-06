#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

char str[100];
bool per(char* a)
{
	if(!strcmp(a,"6") || !strcmp(a,"28") || !strcmp(a,"496")|| !strcmp(a,"8128")|| !strcmp(a,"33550336")|| !strcmp(a,"8589869056") ||!strcmp(a,"137438691328"))
		return true;
	else
		return false;
}

int main()
{
	int n;
	char *ptr,token[]=",\n";
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%s",str);
			for(ptr=strtok(str,token);ptr;ptr=strtok(NULL,token))
			{
				if(per(ptr))
					printf("Yes\n");
				else
					printf("No\n");
			}

		}
	}
	return 0;
}
