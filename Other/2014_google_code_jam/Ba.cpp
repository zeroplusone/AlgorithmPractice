
/*#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
char in[110];
struct alp
{
	char e;
	int num;

}seq[2][110];

int main()
{
	//freopen("BBa.in","r",stdin);
	freopen("Ba.out","w",stdout);
	int t,tt,n;
	int i,j;
	int coun[2];
	char last;
	int ans;
	scanf("%d",&t);
	for(tt=1;tt<=t;++tt)
	{

		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			coun[i]=0;
			scanf("%s",in);
			last=in[0];
			seq[i][coun[i]].e=in[0];
			seq[i][coun[i]].num=1;
			for(j=1;j<strlen(in);++j)
			{
				if(in[j]==last)
				{
					seq[i][coun[i]].num++;
				}
				else
				{
					coun[i]++;
					seq[i][coun[i]].e=in[j];
					seq[i][coun[i]].num=1;
					last=in[j];
				}

			}
		}
		/*for(i=0;i<=coun[0];++i)
		{
			printf("%d %c %d\n",i,seq[0][i].e,seq[0][i].num);
		}
		printf("\n");
		for(i=0;i<=coun[1];++i)
		{
			printf("%d %c %d\n",i,seq[1][i].e,seq[1][i].num);
		}
		printf("\n");*/
		/*
		printf("Case #%d: ",tt);
		if(coun[0]!=coun[1])
			printf("Fegla Won\n");
		else
		{
			ans=0;
			for(i=0;i<=coun[0];++i)
			{
				if(seq[0][i].e!=seq[1][i].e)
				{
					ans=-1;
					break;
				}

				ans+=abs(seq[0][i].num-seq[1][i].num);
			}
			if(ans==-1)
				printf("Fegla Won\n");
			else
				printf("%d\n",ans);
		}



	}
	return 0;
}
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
char in[110];
struct alp
{
	char e;
	int num;

}seq[110][110];
int coun[110];

bool samenum(int n)
{
	int i=0;
	for(i=1;i<n;++i)
	{
		if(coun[i]!=coun[0])
			return false;
	}

	return true;
}

bool samechar(int n)
{
	int i,j;
	for(i=0;i<=coun[0];++i)
	{
		for(j=1;j<n;++j)
			if(seq[j][i].e!=seq[0][i].e)
				return false;
	}
	return true;
}

int finddif(int n,int now)
{
	int ma=seq[0][now].num,mi=seq[0][now].num;
	int i;
	for(i=0;i<n;++i)
	{
		ma=ma<seq[i][now].num?seq[i][now].num:ma;
		mi=mi>seq[i][now].num?seq[i][now].num:mi;
	}
	return abs(ma-mi);
}

int main()
{
	//freopen("BBa.in","r",stdin);
	freopen("Ba.out","w",stdout);
	int t,tt,n;
	int i,j;

	char last;
	int ans;
	scanf("%d",&t);
	for(tt=1;tt<=t;++tt)
	{

		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			coun[i]=0;
			scanf("%s",in);
			last=in[0];
			seq[i][coun[i]].e=in[0];
			seq[i][coun[i]].num=1;
			for(j=1;j<strlen(in);++j)
			{
				if(in[j]==last)
				{
					seq[i][coun[i]].num++;
				}
				else
				{
					coun[i]++;
					seq[i][coun[i]].e=in[j];
					seq[i][coun[i]].num=1;
					last=in[j];
				}

			}
		}
		/*for(j=0;j<n;++j)
		{
			for(i=0;i<=coun[j];++i)
			{
				printf("%d %c %d\n",i,seq[j][i].e,seq[j][i].num);
			}
			printf("\n");
		}*/
		printf("Case #%d: ",tt);
		if(!samenum(n))
			printf("Fegla Won\n");
		else
		{
			ans=0;
			for(i=0;i<=coun[0];++i)
			{
				if(!samechar(n))
				{
					ans=-1;
					break;
				}

				ans+=finddif(n,i);
			}
			if(ans==-1)
				printf("Fegla Won\n");
			else
				printf("%d\n",ans);
		}



	}
	return 0;
}
