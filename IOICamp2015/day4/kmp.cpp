void build_fail(string B)
{
	int len=B.length(),cur;
	cur=fail[0]=-1;
	for(int i=1;i<len;++i)
	{
		while(cur!=-1 && B[cur+1]!=B[i])
		{
			cur=fail[cur];
		}
		if(B[cur+1]==B[i])
			cur++;
		fail[i]=cur;
	}
}

void match(string A,string B)
{
	int lenA=A.length(),lenB=B.length();
	int cur=-1;
	for(int i=0;i<lenA;++i)
	{
		while(cur!=-1 && B[cur+1]!=A[i])
			cur=fail[cur];
	}

	if(B[cur+1]==A[i])
	{
		cur++;
	}	
	if(cur==lenB-1)
	{
		cur=fail[cur];
	}
}
