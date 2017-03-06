#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		vector<int> a(n,0);
		for(int k=0;k<n;++k)
			cin>>a[k];
		int count=0;
		
		for(int i=n-1;i>0;--i)
		{
			for(int j=0;j<i;++j)
			{
				if(a[j]>a[j+1])
				{
					swap(a[j],a[j+1]);
					count++;
				}				
			}
		}
		cout<<"Minimum exchange operations : "<<count<<endl;
	}
	return 0;
}