class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len=beginWord.length();
        unordered_set<string> wList(wordList.begin(), wordList.end());
        int n=wList.size();
        if(wList.count(endWord)==0) {
            return 0;
        }

        queue<string> que;
        que.push(beginWord);
        unordered_set<string> visit;
        int ans=2;
        while(!que.empty()) {
            if(ans>n+1) {
                break;
            }
            int s=que.size();
            for(int i=0;i<s;++i) {
                string last = que.front();
                que.pop();

                for(int j=0;j<len;++j) {
                    string str=last;
                    for(int k=0;k<26;++k) {
                        str[j]='a'+k;
                        if(wList.count(str)!=0) {
                            visit.insert(str);
                            if(str==endWord) {
                                return ans;
                            } else {
                                que.push(str);
                            }
                        }
                    }
                }
            }

            for(auto v:visit) {
                wList.erase(v);
            }
            visit.clear();
            ans++;
        }
        return 0;
    }
};
