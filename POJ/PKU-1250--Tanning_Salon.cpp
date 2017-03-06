#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

int main()
{
	int num;	
	string s;
	while(cin>>num)
	{
		if(num==0)
			break;
		cin>>s;
			
			int now=0;
			vector<char> tan(num,'0');
			
			
			int count=0;
			for(int i=0;i<s.length();++i)
			{
				if(now!=num)
				{
					int j=0;
					int flag=0;
					for(j=0;j<num;++j)
					{
						if(s[i]==tan[j])
						{	
							flag=1;
							
							--now;
							tan[j]='0';
							break;
						}				
					}
					if(flag==0)
					{
						
						now++;
						for(int k=0;k<num;++k)
						{
							if(tan[k]=='0')
							{
								tan[k]=s[i];
								break;
							}
							
						}
					}
				}
				else
				{
					int j=0;
					int tmp=now;
					for(j=0;j<now;++j)
					{
						if(s[i]==tan[j])
						{
						
							--now;
							tan[j]='0';
							break;
						}				
					}
					if(j==tmp)
					{
						
						count++;
					}
					
				}
			}
			
			
			if(count==0)
				cout<<"All customers tanned successfully."<<endl;
			else
				cout<<count/2<<" customer(s) walked away."<<endl;
		
	}
	return 0;
} 