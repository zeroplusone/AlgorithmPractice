#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

char S[120];
bool mp[500][500];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",S);
		int x=250,y=250;
		fill(mp[0],mp[500],0);
		bool yes=1;
		mp[x][y]=1;
		for(char *p=S;*p;p++)
		{
			switch(*p)
			{
				case 'L': y--; break;
				case 'U': x--; break;
				case 'R': y++; break;
				case 'D': x++; break;
			}
			int c=0;
			if(mp[x][y])
			{
				yes=0;
				break;
			}
			mp[x][y]=1;
			//printf("(%d)\n",mp[250][249]);
			if(mp[x+1][y])
				c++;
			if(mp[x-1][y])
				c++;
			if(mp[x][y+1])
				c++;
			if(mp[x][y-1])
				c++;
			if(c>=2)
			{
				//printf("%d,%d\n",x,y);
				yes=0;
				break;
			}
			//printf("%d,%d\n",x,y);
		}
		if(yes)
			puts("worshik<(_ _)>");
		else
			puts("MADA0");
	}
	return 0;
}

