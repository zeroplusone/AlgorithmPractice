/******************
Judge   : PKU
Problem : 1664-apple
Course  : Course2
discribe: put m apples to n plates,and how many ways are there?
Input   : t (case)
          m n
		  m n
		  .
		  .
		  m n
		  
Output  : k  
Solve   : stack

*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
/*
int F(int m,int n)
{
	if(m<0)
		return 0;
	if(m==0 ||n==1)
		return 1;
	return F(m-n,n)+F(m,n-1);
}

int main()
{
	int t;
	cin>>t;
	int m,n;
	for(int i=0;i<t;++i)
	{
		cin>>m>>n;
		cout<<F(m,n)<<endl;
	}
}
*/
//看某個盤子 為空(0) + 每個盤子都一科(防止重複算)後開始分(1.2....)
#define MAX 12
int a[MAX][MAX];

int apple(int mm,int nn)
{
	//printf("%d %d\n",mm,nn);
	if(mm >= 0 && nn>=0 && a[mm][nn])
		return a[mm][nn];
	if(mm<0)
		a[mm][nn]=0;		
	else if(mm<=1 || nn==1)
		a[mm][nn]= 1;	
	else
		a[mm][nn]=apple(mm-nn,nn)+apple(mm,nn-1);
	return a[mm][nn];
}

int main()
{
	int t,m,n;
	memset(a,0,sizeof(a));
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d %d",&m,&n);
			if(!a[m][n])			
				a[m][n]=apple(m,n);
			printf("%d\n",a[m][n]);	
		}
	}
	return 0;
}