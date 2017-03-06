/******************
Judge   : uva
Problem : 11475 - Extend to Palindrome
Course  : Course17
discribe:   adding the fewest number of extra letters to the end  to make a palidrome
Input   :
		
			aaaa
			abba
			amanaplanacanal
			xyz

Output	:
			aaaa
			abba
			amanaplanacanalpanama
			xyzyx
solve:
			KMP
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 100010
int pi[MAXN];
char w[MAXN],t[MAXN];
int ans;

void buildPi()
{	
	int i,j,len;
	len=strlen(w+1);
	memset(pi,0,(len+1)*sizeof(int));
	pi[1]=0;	j=0;
	for(i=2;i<=len;++i)
	{
		while(j>0 && w[j+1]!=w[i])
		{
			j=pi[j];
		}

		if(w[j+1]==w[i])
			j++;
		pi[i]=j;

	}
}

void KMP()
{
	int i,j;
	int lent=strlen(t+1);
	int lenw=strlen(w+1);
	j=0;
	for(i=1;i<=lent;++i)
	{
		while(j>0 && t[i]!=w[j+1])
		{
			j=pi[j];
		}
			
		if(t[i]==w[j+1])
			j++;
		if(i==lent)
			ans=j;
		if(j==lenw)
		{
			j=pi[j];
		}
		
	}
}

int main()
{
	int i,len;
	while(gets(t+1))
	{	
		len=strlen(t+1);	
		for(i=1;i<=len;++i)
			w[len+1-i]=t[i];
		w[len+1]='\0';
		buildPi();
		/*for(i=0;i<=strlen(w+1);++i)
			printf("%d ",pi[i]);
		printf("\n");*/
		ans=0;
		KMP();
		
		printf("%s",t+1);
		for(i=len-ans;i>=1;--i)
			printf("%c",t[i]);
		printf("\n");
	}
	return 0;
}