class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n=preorder.length();
        stack<int> sta;

        if(preorder.length()==1 && preorder[0]=='#') {
            return true;
        }

        int i;
        for(i=0;i<n;++i) {
            while(i<n&&preorder[i]!=',') {
                i++;
            }
            
            if(preorder[i-1]!='#') {
                sta.push(0);
            } else if(!sta.empty()) {
                int pre=sta.top();  sta.pop();
                sta.push(pre+1);

                while(sta.top()==2) {
                    sta.pop();
                    if(sta.empty()) {
                        break;
                    }
                    pre=sta.top();  sta.pop();
                    sta.push(pre+1);
                }    
            }
            
            if(sta.empty()) {
                break;
            }
        }
        return i==n&&sta.empty();

    }
};
