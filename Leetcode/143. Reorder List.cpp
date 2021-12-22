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
    void reorderList(ListNode* head) {
        
        ListNode* slow=head, *fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr) {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* now=slow->next;
        slow->next=nullptr;
        
        // revert 
        ListNode* last=nullptr;
        while(now!=nullptr) {
            ListNode* tmp=now->next;
            now->next=last;
            last=now;
            now=tmp;
        }
        
        // concat
        ListNode* h=head, *e=last;
        while(h!=nullptr) {
            ListNode* hnext=h->next;
            ListNode* enext=e!=nullptr?e->next:nullptr;
            h->next=e;
            if(e!=nullptr) {
                e->next=hnext;    
            }
            
            h=hnext;
            e=enext;
        }
    }
    
    
};
