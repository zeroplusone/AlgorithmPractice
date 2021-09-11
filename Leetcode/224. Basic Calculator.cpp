class Solution {
public:
    struct Node {
        bool isOperator;
        char ops;
        int val;
        Node(char ops):ops(ops), isOperator(true), val(0){};
        Node(int val):val(val), isOperator(false), ops(' '){};
    };

    Node cal(vector<Node> expr) {
        if(!expr[0].isOperator) {
            expr.insert(expr.begin(), Node('+'));
        }
        int num=0;
        for(int i=0;i<expr.size();++i) {
            if(expr[i].ops=='+') {
                i++;
                num+=expr[i].val;
            } else if(expr[i].ops=='-') {
                i++;
                num-=expr[i].val;
            }
        }
        return Node(num);
    }

    int calculate(string s) {
        stack<Node> sta;
        int num=0;
        bool numflag=false;
        for(int i=0;i<s.length();++i) {
            if(s[i]==' ') {
                continue;
            } else if(s[i]>='0' && s[i]<='9') {
                numflag=true;
                num=num*10+(s[i]-'0');
            } else {
                if(numflag) {
                    sta.push(Node(num));
                    num=0;    
                    numflag=false;
                }
                
                if(s[i]==')') {
                    vector<Node> expression;
                    while(sta.top().ops!='(') {
                        expression.push_back(sta.top());
                        sta.pop();
                    }
                    sta.pop();
                    reverse(expression.begin(), expression.end());
                    sta.push(cal(expression));
                } else {
                    sta.push(Node(s[i]));
                }
            }
        }
        if(numflag) {
            sta.push(Node(num));
        }
        vector<Node> expression;
        while(!sta.empty()) {
            expression.push_back(sta.top());
            sta.pop();
        }
        reverse(expression.begin(), expression.end());
        return cal(expression).val;
    }
};
