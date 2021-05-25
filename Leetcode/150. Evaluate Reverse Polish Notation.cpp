class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        int n1, n2;
        for(auto token: tokens) {
            if(token=="+") {
                n1=sta.top(); sta.pop();
                n2=sta.top(); sta.pop();
                sta.push(n2+n1);
            } else if(token=="-") {
                n1=sta.top(); sta.pop();
                n2=sta.top(); sta.pop();
                sta.push(n2-n1);
            } else if(token=="*") {
                n1=sta.top(); sta.pop();
                n2=sta.top(); sta.pop();
                sta.push(n2*n1);
            } else if(token=="/") {
                n1=sta.top(); sta.pop();
                n2=sta.top(); sta.pop();
                sta.push(n2/n1);
            } else {
                sta.push(stoi(token));
            }
        }
        return sta.top();
    }
};
