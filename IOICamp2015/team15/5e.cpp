#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int mod=987654361;

struct Dis{
	int f[1000];
	void init(int n)
	{
		for(int i=0;i<=n;i++)
			f[i]=i;
	}
	int find(int x)
	{
		if(f[x]==x)
			return x;
		return f[x]=find(f[x]);
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
	bool Union(int a,int b)
	{
		if(!same(a,b))
			f[find(a)] = find(b);
	}
};

ll pow(int a,int k) // a^k %mod
{
//printf("%d %d\n",a,k);
	ll re=1, tmp=a;
	while(k)
	{
		if(k&1)
			re=re*tmp%mod;
		k/=2;
		tmp=tmp*tmp%mod;
//printf("%d %lld %lld\n",k,tmp,re);
	}
//printf("%lld\n",re);
	return re;
}

int inv(int k)
{
	return pow(k,mod-2);
}

struct Block{
	int s[25][25]; // 1~cnt
	int n,m,cnt;
	void easy()
	{
		int offset=n;
		for(int i=0; i<n; i++){
			bool exi=false;
			for(int j=0; j<m; j++){
				if(s[i][j]=='#'){
					exi=true;
					break;
				}
			}
			if(exi==true){
				offset=i;
				break;
			}
		}
		for(int i=offset; i<n; i++)
			for(int j=0; j<m; j++)
				s[i-offset][j]=s[i][j];
		n-=offset;
		offset=m;
		for(int i=0; i<m; i++){
			bool exi=false;
			for(int j=0; j<n; j++){
				if(s[j][i]=='#'){
					exi=true;
					break;
				}
			}
			if(exi==true){
				offset=i;
				break;
			}
		}
		for(int i=offset; i<m; i++)
			for(int j=0; j<n; j++)
				s[j][i-offset]=s[j][i];
		m-=offset;
	//printf("(%d,%d)\n",n,m);
		for(int i=n-1; i>=0; i--){
			bool exi=false;
			for(int j=0; j<m; j++){
				if(s[i][j]=='#'){
					exi=true;
					break;
				}
			}
			if(exi==true){
				n=i+1;
				break;
			}
		}
//	printf("(%d,%d)\n",n,m);
		for(int i=m-1; i>=0; i--){
			bool exi=false;
			for(int j=0; j<n; j++){
			//	printf("~%d %d\n",s[j][i],'#');
				if(s[j][i]=='#'){
	//	printf("%d %d\n",i,j);
					exi=true;
					break;
				}
			}
			if(exi==true){
	//	printf("i=%d\n",i);
				m=i+1;
				break;
			}
		}
//	printf("(%d,%d)\n",n,m);
		cnt=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{ 
				if(s[i][j]=='#')
					s[i][j]=++cnt;
				else
					s[i][j]=0;	
			} 
	}

	Block rotate() // 順時針90度 
	{
		Block r;
		r.n=m;
		r.m=n;
		r.cnt=cnt;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				r.s[j][r.m-i-1]=s[i][j];
		return r;
	}
	Block turn() //翻轉 
	{
		Block r;
		r.n=m;
		r.m=n;
		r.cnt=cnt;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				r.s[j][i]=s[i][j];
		return r;
	}
	void print()
	{
		for(int i=0;i<n;i++,puts(""))
			for(int j=0;j<m;j++)
				printf("%d",s[i][j]);
	}
}ori;

int c;

int cnt(const Block &b)
{
	if(ori.n!=b.n || ori.m!=b.m)
		return -1;
	int n=ori.n , m=ori.m;
	Dis dis;
	dis.init(ori.cnt);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(ori.s[i][j]>0 && b.s[i][j]==0)
				return -1;
			if(ori.s[i][j]==0 && b.s[i][j]>0)
				return -1;
			if(ori.s[i][j]>0)
			{
				dis.Union(ori.s[i][j], b.s[i][j]);
			}
		}
	int r=0;
	for(int i=1;i<=ori.cnt;i++)
		if(dis.find(i)==i)
			r++;
	return r;
}

char in[50][50];

int main()
{
//printf("%lld\n",pow(3,3));
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&ori.n,&ori.m,&c);
		for(int i=0;i<ori.n;i++)
			scanf("%s",in[i]);
		for(int i=0;i<ori.n;i++)
			for(int j=0;j<ori.m;j++)
				ori.s[i][j]=(int)in[i][j];
//printf("%d\n",ori.m);
		ori.easy();
//printf("%d\n",ori.m);
//ori.print();
//puts("");
		if(ori.cnt==0)
		{
			puts("0");
			continue;
		}
//puts("f");
		Block tmp=ori;
//tmp.print();
		ll ans=0;
		int div=0;
		for(int i=0;i<4;i++)
		{
			tmp=tmp.rotate();
//tmp.print();
			int r=cnt(tmp);
			if(r==-1)
				continue;
	//printf("%d:%d\n",i,r);
			ans=( ans + pow(c,r) ) % mod;
	//printf("%d %lld\n",div,ans);
			div++;
		}
		tmp=tmp.turn();
//tmp.print();
		for(int i=0;i<4;i++)
		{
			tmp=tmp.rotate();
//tmp.print();
			int r=cnt(tmp);
			if(r==-1)
				continue;
	//printf("%d:%d\n",i,r);
			ans=( ans + pow(c,r) ) % mod;
	//printf("%d %lld\n",div,ans);
			div++;
		}
		ans = (ans * inv(div))%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
