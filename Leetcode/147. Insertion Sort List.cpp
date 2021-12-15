/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ret=nullptr;
        ListNode* n=nullptr;
        for(ListNode* i=head;i!=nullptr;i=n) {
            n=i->next;
            ret=insert(ret, i);
        }
        return ret;
    }
    
    ListNode* insert(ListNode* ret, ListNode* node) {
        if(ret==nullptr) {
            node->next=nullptr;
            return node;
        } else if(node->val<ret->val) {
            node->next=ret;
            return node;
        }
        ListNode* now=ret;
        while(now->next!=nullptr && now->next->val<node->val) {
            now=now->next;
        }
        ListNode* tmp=now->next;
        now->next=node;
        node->next=tmp;
        return ret;
    }
};
