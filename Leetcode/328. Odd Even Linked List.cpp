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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) {
            return head;
        }
        ListNode* even=head->next;
        
        ListNode* oit=head;
        ListNode* eit=head->next;
        while(eit!=nullptr && eit->next!=nullptr) {
            oit->next=eit->next;
            eit->next=eit->next->next;
            
            oit=oit->next;
            eit=eit->next;
        }
        
        oit->next=even;
        return head;
        
    }
};
