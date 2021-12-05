/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        return solve(head, insertVal, head);
    }
    
    Node* solve(Node* head, int insertVal, Node* originHead) {
        Node* node=new Node(insertVal);
        if(head==nullptr) {
            node->next=node;
            return node;
        } else if(head->next==originHead) {
            head->next=node;
            node->next=originHead;
        } else {
            if(head->val<=head->next->val) {
                if(insertVal>=head->val && insertVal<=head->next->val) {
                    Node* tmp=head->next;
                    head->next=node;
                    node->next=tmp;
                } else {
                    solve(head->next, insertVal, originHead);
                }
            } else {
                if(insertVal>= head->val || insertVal<=head->next->val) {
                    Node* tmp=head->next;
                    head->next=node;
                    node->next=tmp;
                } else {
                    solve(head->next, insertVal, originHead);
                }
            }
        }
        return head;
    }
};
