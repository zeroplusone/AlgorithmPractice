#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

char chess[8][8];
char in[3],c;
int x,y;

void read(int black)
{
	do
	{
		scanf("%c%",&in[0]);
		if(in[0]>='A' && in[0]<='Z')  //¤£¬O§L
		{
			scanf("%c%c",&in[1],&in[2]);
			y=in[1]-'a'; x=8-(in[2]-'0');
			chess[x][y]=black?in[0]-('A'-'a'):in[0];			
		}
		else
		{
			scanf("%c",&in[2]);
			y=in[0]-'a'; x=8-(in[2]-'0');			
			chess[x][y]=black?'p':'P';
		}

		c=getchar();
	}while(c!='\n');
}

int main()
{	
	scanf("White: ");	read(0);
	scanf("Black: ");	read(1);
	for(int i=0;i<8;++i)
	{
		printf("+---+---+---+---+---+---+---+---+\n");
		for(int j=0;j<8;++j)
		{			
			if(chess[i][j]!='\0')
			{
				if((i+j)%2==0)
					printf("|.%c.",chess[i][j]);
				else
					printf("|:%c:",chess[i][j]);
			}
			else
			{
				if((i+j)%2==0)
					printf("|...",chess[i][j]);
				else
					printf("|:::",chess[i][j]);
			}
		}
		printf("|\n");
	}
	printf("+---+---+---+---+---+---+---+---+\n");
	
	return 0;
}
