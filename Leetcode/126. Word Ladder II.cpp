class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int len=beginWord.length();
        unordered_set<string> wList(wordList.begin(), wordList.end());
        int n=wList.size();
        if(wList.count(endWord)==0) {
            return vector<vector<string>>(0);
        }
        
        queue<vector<string>> que;
        que.push(vector<string>{beginWord});
        unordered_set<string> visit;
        vector<vector<string>> ans(0);
        while(!que.empty()) {
            if(ans.size()!=0 || que.front().size()>=n+1) {
                break;
            }
            int s=que.size();
            for(int i=0;i<s;++i) {
                vector<string> now = que.front();
                que.pop();
                
                string last=now[now.size()-1];
                for(int j=0;j<len;++j) {
                    string str=last;
                    for(int k=0;k<26;++k) {
                        str[j]='a'+k;
                        if(wList.count(str)!=0) {
                            vector<string> next=now;
                            next.push_back(str);
                            visit.insert(str);
                            if(str==endWord) {
                                ans.push_back(next);
                            } else {
                                que.push(next);
                            }
                        }
                    }
                }
            }
            
            for(auto v:visit) {
                wList.erase(v);
            }
            visit.clear();
        }
        return ans;
    }
};
