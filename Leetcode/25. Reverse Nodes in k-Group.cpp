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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) {
            return head;
        }
        ListNode* it=head;
        int len=0;
        while(it!=nullptr) {
            it=it->next;
            len++;
        }
        len/=k;

        ListNode *last=nullptr, *ret=head;
        ListNode *pre=head, *now=head->next, *sta=head, *tmp;

        while(len--) {
            int cnt=k-1;
            while(cnt--) {
                tmp=now->next;
                now->next=pre;
                pre=now;
                now=tmp;
            }
            sta->next=now;
            if(last==nullptr) {
                ret=pre;
            } else {
                last->next=pre;
            }
            last=sta;
            sta=now;
            pre=now;
            if(now!=nullptr) {
                now=now->next;
            }
            cnt=0;
        }
        

        return ret;
    }
};
