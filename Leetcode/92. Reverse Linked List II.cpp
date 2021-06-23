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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) {
            return head;
        }

        int i=1;
        ListNode* l=head, *before=nullptr;
        while(i!=left) {
            before=l;
            l=l->next;
            i++;
        }
        
        ListNode *last=l, *r=l->next, *after=r->next;
        i++;

        while(i!=right) {
            r->next=last;
            last=r;
            r=after;
            after=after->next;
            i++;
        }

        r->next=last;
        l->next=after;
        if(left==1) {
            return r;
        } else {
            before->next=r;
            return head;
        }
        
    }
};
