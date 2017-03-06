#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

#define MAX 10010
vector<int> num;
char s[MAX];

int main()
{
	int d,n,i;
	
	bool yes;
	while(scanf("%d %d",&n,&d)!=EOF)
	{
		if(n==0 &&  d==0)
			break;
		getchar();
		scanf("%s",s);		
		
		num.clear();	i=0;	yes=false;
		for(int k=0;k<n;++k)
			num.push_back(s[k]-'0');
		while(num.size()!=n-d)
		{			
			if(i==num.size()-1)
			{	
				i=0;
				if(!yes)
				{
					for(int l=num.size()-1;l>=(n-d);--l)
						num.erase(num.begin()+l);
					break;
				}
				yes=false;	
			}	
			if(num[i]<num[i+1])			
			{	
				num.erase(num.begin()+i);
				yes=true;
			}
			else
				i++;
		}		
		for(int j=0;j<num.size();++j)
			printf("%d",num[j]);
		printf("\n");
	}
	return 0;
}