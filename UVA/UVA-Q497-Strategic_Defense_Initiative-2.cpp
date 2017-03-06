#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    int t,tmp,i;
    vector<int>::iterator posi;
    string s;
    vector<int> vec,pa,arr,ans;
    scanf("%d\n",&t);
    while(t--)
    {
        vec.clear();
        pa.clear();
        arr.clear();
        ans.clear();
        while(getline(cin,s) && s!="")
        {
            tmp=atoi(s.c_str());
            arr.push_back(tmp);
            if(vec.empty())
            {
                vec.push_back(tmp);
                pa.push_back(1);
            }
            else if(tmp>vec.back())
            {
                vec.push_back(tmp);
                pa.push_back(vec.size());
            }
            else
            {
                posi=lower_bound(vec.begin(),vec.end(),tmp);
                *posi=tmp;
                pa.push_back(posi-vec.begin()+1);
            }
        }
        tmp=vec.size();
        for(i=pa.size()-1;i>=0;--i)
        {
            if(pa[i]==tmp)
            {
                ans.push_back(arr[i]);
                tmp--;
            } 
        }
        printf("Max hits: %lu\n",vec.size());
        for(i=ans.size()-1;i>=0;--i)
            printf("%d\n",ans[i]);
        if(t!=0)
            printf("\n");
        
    }
    return 0;
}
