#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s1,s2;
	int n1[26],n2[26];
	int size,flag,dif;
	while(cin>>s1>>s2)
	{
		size=s1.length();
		if(s2.length()==size)
		{
			//cout<<"!"<<size<<endl;
			for(int i=0;i<26;++i)
			{
				n1[i]=0;
				n2[i]=0;
			}
			for(int i=0;i<size;++i)
			{
				n1[s1[i]-'A']++;
				n2[s2[i]-'A']++;
			}
			sort(n1,n1+26);
			sort(n2,n2+26);
			
			
			/*for(int k=0;k<26;++k)
			{		
				flag=0;
				//cout<<"!"<<k<<endl;
				for(int j=0;j<size;++j)
				{
					n1[j]=(n1[j]+1)%26;				
				}
				sort(n1,n1+size);*/
				flag=0;
				for(int j=0;j<26;++j)
				{		
					//cout<<n1[j]<<" "<<n2[j]<<endl;	
					if(n1[j]!=n2[j])
					{
						flag=1;
						break;
					}
				}
				/*if(!flag)
					break;
			}*/
			
			if(flag)			
				printf("NO\n");
			
			else
				printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}