class AutocompleteSystem {
public:
    // static bool comparator (int s1, int s2) {
    //     return t[s1]==t[s2]?s[s1]>s[s2]:t[s1]<t[s2];
    // };
    
    struct Word {
        string str;
        int tim;
        Word(string str, int tim):str(str), tim(tim){};
        bool operator<(const Word& t) const {
            return tim==t.tim?str<t.str:tim>t.tim;
        };
    };
    struct Trie{
        char c;
        unordered_map<char, Trie*> children;
        vector<int> pq;
        Trie(char c):c(c), pq(vector<int>(0)){};
    };
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        s=sentences;
        t=times;
        index=sentences.size();
        root=new Trie('#');
        buildTrie();
        it=root;
        newString="";
        for(int i=0;i<s.size();++i) {
            s2i[s[i]]=i;
        }
    }
    
    vector<string> input(char c) {
        if(c=='#') {
            if(s2i.count(newString)!=0) {
                t[s2i[newString]]++;
            } else {
                Trie* now=root;
                for(int i=0;i<newString.length();++i) {
                    if(now->children.count(newString[i])==0) {
                        now->children[newString[i]]=new Trie(newString[i]);
                    } 
                    now=now->children[newString[i]];
                    now->pq.push_back(index);
                }
                s.push_back(newString);
                t.push_back(1);
                s2i[newString]=index;
                index++;
                
            }
            
            newString="";
            it=root;
            return vector<string>{};
        } else {
            newString+=c;
            
            if(it->children.count(c)==0) {
                it->children[c]=new Trie(c);
                it=it->children[c];
                return vector<string>{};
            }
            it=it->children[c];
            
            vector<Word> words;
            for(int i=0;i<(it->pq).size();++i) {
                words.push_back(Word(s[it->pq[i]], t[it->pq[i]]));
            }
            sort(words.begin(), words.end());
            // priority_queue<int, vector<int>, decltype(cmp)> cpq=it->pq;
            vector<string> ans;
            // int cnt=0;
            // while(!cpq.empty() && cnt<3) {
            //     ans.push_back(s[cpq.top()]);
            //     cpq.pop();
            //     cnt++;
            // }
            for(int i=0;i<words.size() && i<3;++i) {
                ans.push_back(words[i].str);
            }
            return ans;
        }
    }
    
    void buildTrie() {
        for(int i=0;i<s.size();++i) {
            Trie* now=root;
            for(int j=0;j<s[i].length();++j) {
                if(now->children.count(s[i][j])==0) {
                    now->children[s[i][j]]=new Trie(s[i][j]);
                } 
                now=now->children[s[i][j]];
                now->pq.push_back(i);
            }
        }
    }
    
    Trie* root, *it;
    int index;
    string newString;
    vector<string> s;
    vector<int> t;
    unordered_map<string, int> s2i;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
