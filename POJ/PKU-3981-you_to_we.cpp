#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
	char s[1000];

	while(gets(s))
	{	
		char *token=strtok(s," ");//可用旗子判斷是否第一個

		if(!(strcmp(token,"you")))
			printf("we");
		else
			printf("%s",token);
		token=strtok(NULL," ");
		for(;token!=NULL;token=strtok(NULL," "))
		{
			
			if((!strcmp(token,"you")))
				printf(" we");
			else
				printf(" %s",token);
		}
		printf("\n");
		
	}
	return 0;
}