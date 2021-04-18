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
        ListNode *now = head;
        int len=0;
        while(now!=nullptr) {
            len++;
            now=now->next;
        }
        
        if(n==len) {
            return head->next;
        }

        ListNode *before=head, *after=head->next->next;
        int cnt=len-n-1;
        while(cnt--) {
            before=before->next;
            after=after->next;
        }
        before->next=after;
        return head;
        
    }
};
