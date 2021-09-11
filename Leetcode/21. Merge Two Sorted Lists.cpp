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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*now=new ListNode();
        ListNode* ans=now;

        while(l1!=nullptr && l2!=nullptr) {
            if(l1->val<=l2->val) {
                now->next=l1;
                l1=l1->next;
                now=now->next;
            } else {
                now->next=l2;
                l2=l2->next;
                now=now->next;
            }
        }
        
        now->next=l1==nullptr?l2:l1;
        
        return ans->next;
    }
};
