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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr) {
            return nullptr;
        } 
        
        ListNode *before=head, *after=head;
        int cnt=n;
        while(cnt--) {
            before=before->next;
        }
        
        if(before==nullptr) {
            return head->next;
        } else {
            while(before->next!=nullptr) {
                before=before->next;
                after=after->next;
            }

            after->next=after->next->next;
            return head;
        }
    }
};
