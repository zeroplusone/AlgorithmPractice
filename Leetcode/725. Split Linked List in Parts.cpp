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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode* now=head;
        while(now!=nullptr) {
            len++;
            now=now->next;
        }

        vector<ListNode*> ans(k);
        now=head;
        for(int i=0;i<k && now!=nullptr;++i) {
            int l=len/k+(i<len%k?1:0);
            ans[i]=now;

            while(l>1) {
                now=now->next;
                l--;
            }
            
            if(now!=nullptr) {
                ListNode* tmp=now->next;
                now->next=nullptr;
                now=tmp;    
            }
            
        }
        return ans;
    }
};
