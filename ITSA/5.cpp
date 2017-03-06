#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char w[1600][150];
int l[1600];
char ans[110];
int space[110];
int cut[110];

bool isvowel(int i,int index)
{
		if((i==l[index]-1 && w[index][i]=='y') || w[index][i]=='a' || w[index][i]=='i'|| w[index][i]=='o'|| w[index][i]=='u'|| (w[index][i]=='e' && i!=l[index]-1) &&(w[index][i]=='e' && w[index][l[index]-1]!=','))
			return true;
		else
			return false;
}

int last(int index)
{
	int i,j=0,num=1;
	cut[0]=l[index];
	printf("*%s\n",w[index]);
	for(i=l[index]-1;i>=0;)
	{
		if(isvowel(i,index))
		{
			if(j==0)
			{
				j++;	i--;
				continue;
			}
			if(i>1 && (w[index][i-1]=='c' && w[index][i-1]=='h') || (w[index][i-1]=='s' && w[index][i-1]=='h') || (w[index][i-1]=='p' && w[index][i-1]=='h'))			
			{	
				cut[j]=i-1;
				i=i-3;
			}				
			else if(i==0)
			{
				cut[j]=1;
				break;
			}				
			else
			{			
				cut[j]=i+2;
				i=i-2;
			}
			j++;
			num++;
		}
		else
		{
			--i;
		}
	}
	return num;
}

int main()
{
	int c,i,tmp,now,s,j,num,snum,dif,k,kk,start,kkk;
	char in[1600];
	bool ya=false;
	memset(l,0,sizeof(l));
	while(scanf("%d",&c)!=EOF)
	{
		getchar();
		i=0;	now=0;	s=0;
		while(gets(in))
		{
			char* ptr;
			
			for(ptr=strtok(in," \n\r");ptr;ptr=strtok(NULL," \n\r"))
			{
				strcpy(w[i],ptr);
				//printf("%s\n",w[i]);
				l[i]=strlen(w[i]);
				i++;
			}
		}
		start=0;
		while(now<=i-2)
		{
			snum=0;	tmp=0;
			while((tmp-1)<c && now<i)
			{
				tmp+=l[now]+1;
				now++;
				printf("!!%d\n",tmp);
				snum++;
			}			
			snum-=2;
			now--;
			
			tmp=tmp-(l[now]+1);
			//tmp=tmp-(l[now-1]+1);
			printf("~~~%d",tmp);
			num=last(now);
			memset(space,0,sizeof(space));
			for(k=0;k<num;++k)
			{
				printf("%d ",cut[k]);

			}
			printf("\n");
			ya=false;
			for(j=0;j<num;++j)
			{
				printf("*****%d\n",tmp+cut[j]);
				if(tmp+cut[j]==c)			
				{
					ya=true;
					break;
				}					
				else if(tmp+cut[j]<c)
				{
					ya=true;
					dif=c-(tmp+cut[j]);
					
					for(k=snum-1;dif>0;--dif)
					{
						space[k]++;
						k=k==0?snum-1:k-1;
					}
					break;
				}
			}
			if(!ya)
			{
				dif=c-(tmp-1);
					
				for(k=snum-1;dif>0;--dif)
				{
					space[k]++;
					k=k==0?snum-1:k-1;
				}
				now-=1;
			}
			for(k=0;k<snum;++k)
			{
				printf("%d ",space[k]);
			}
			printf("\n");
			for(k=start,kkk=0;k<now;++k,++kkk)
			{
				//printf("%d ",space[k]);
				printf("%s",w[k]);
				for(kk=-1;kk<space[kkk];++kk)
					printf("@");
			}
			//printf("@@@%d %d\n",j,cut[j]-1);
			if(j==0 || !ya)
			{
				printf("%s",w[now]);
				printf("\n");
			}
			else
			{
				
				for(k=0;k<cut[j]-1;++k)
					printf("%c",w[now][k]);
				printf("-\n");
				for(k=cut[j]-1;k<l[now];++k)
					printf("%c",w[now][k]);
			}
			start=now;
			if(!ya)
				start=now+1;
		}
	}
	return 0;
}