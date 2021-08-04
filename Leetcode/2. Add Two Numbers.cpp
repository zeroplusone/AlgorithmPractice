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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);
        ListNode* now=ans;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr || carry!=0) {
            int v1=0, v2=0;
            if(l1!=nullptr) {
                v1=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr) {
                v2=l2->val;
                l2=l2->next;
            }
            
            now->next=new ListNode((v1+v2+carry)%10, nullptr);
            now=now->next;
            carry=(v1+v2+carry)/10;
        }
        
        return ans->next;
    }
};
