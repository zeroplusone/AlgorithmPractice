class Solution {
public:
    string pushDominoes(string dominoes) {
        int len=dominoes.length();
        queue<int> que;
        for(int i=0;i<len;++i) {
            if(dominoes[i]!='.') {
                que.push(i);
            }
        }
        string ans=dominoes;
        while(!que.empty()) {
            int n=que.size();
            for(int i=0;i<n;++i) {
                int now=que.front();
                int newIndex=-1;
                if(dominoes[now]=='L' && now-1>=0 && dominoes[now-1]=='.') {
                    newIndex=now-1; 
                } else if(dominoes[now]=='R' && now+1<len && dominoes[now+1]=='.') {
                    newIndex=now+1;
                }
                if(newIndex!=-1) {
                    ans[newIndex]=ans[newIndex]=='.'?dominoes[now]:'.';
                    que.push(newIndex);
                }
                que.pop();
            }
            dominoes=ans;
        }
        return ans;
    }
};
