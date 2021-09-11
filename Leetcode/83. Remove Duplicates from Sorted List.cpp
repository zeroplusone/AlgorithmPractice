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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* now=head;
        while(now!=nullptr && now->next!=nullptr) {
            if(now->val==now->next->val) {
                now->next=now->next->next;
            } else {
                now=now->next;
            }
        }
        
        return head;
    }
};
