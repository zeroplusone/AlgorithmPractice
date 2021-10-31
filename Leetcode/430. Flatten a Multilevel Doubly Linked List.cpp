/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==nullptr) {
            return head;
        }

        if(head->child!=nullptr) {
            Node* tmp=head->next;
            head->child->prev=head;
            head->next=flatten(head->child);    
            head->child=nullptr;
            
            if(tmp!=nullptr) {
                Node* i=head->next;
                while(i->next!=nullptr) {
                    i=i->next;
                }
            
                i->next=tmp;
                tmp->prev=i;
                flatten(i->next);
            }
                
            
        } else {
            flatten(head->next);
        }
        
        return head;
        
    }
};
