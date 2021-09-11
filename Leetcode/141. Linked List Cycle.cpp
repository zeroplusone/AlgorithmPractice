/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr) {
            return false;
        }
        ListNode* one=head, *two=head->next;
        while(two!=nullptr) {
            if(one==two) {
                return true;
            }
            one=one->next;
            if(two->next==nullptr) {
                break;
            }
            two=two->next->next;
        }
        return false;
    }
};
