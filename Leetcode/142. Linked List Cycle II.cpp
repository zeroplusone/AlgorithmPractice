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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr) {
            return nullptr;
        }
        ListNode* tur=head;
        ListNode* hare=head;
        
        do {
            tur=tur->next;
            if(hare->next==nullptr || hare->next->next==nullptr) {
                return nullptr;
            }
            hare=hare->next->next;
            
        } while(tur!=hare);
        
        ListNode* fish=head;
        
        while(fish!=tur) {
            fish=fish->next;
            tur=tur->next;
        }
        return fish;
    }
};
