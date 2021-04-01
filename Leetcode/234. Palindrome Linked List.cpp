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
    bool isPalindrome(ListNode* head) {
        ListNode *one=head, *two=head;
        
        if(one->next==nullptr) {
            return true;
        }

        while(two!=nullptr) {
            one = one->next;
            if(two->next==nullptr) {
                break;
            }
            two=two->next->next;
        }

        two = reverse(one);
        
        while(two!=nullptr) {
            if(head->val!=two->val) {
                return false;
            }
            head=head->next;
            two=two->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* last=nullptr, *tmp;
        
        while(head!=nullptr) {
            tmp = head->next;
            head->next=last;
            last = head;
            head = tmp;
        }
        return last;
    }
};
