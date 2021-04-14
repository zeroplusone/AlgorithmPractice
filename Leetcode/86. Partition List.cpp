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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less=nullptr, * more=nullptr;
        ListNode* lessNow, * moreNow;
        while(head!=nullptr) {
            if(head->val<x) {
                if(less==nullptr) {
                    less=head;
                    lessNow=less;
                } else {
                    lessNow->next=head;
                    lessNow=lessNow->next;
                }
            } else {
                if(more==nullptr) {
                    more=head;
                    moreNow=more;
                } else {
                    moreNow->next=head;
                    moreNow=moreNow->next;
                }
            }
            head=head->next;
        }
        
        if(less==nullptr && more==nullptr) {
            return nullptr;
        } if(less==nullptr) {
            moreNow->next=nullptr;
            return more;
        } else if(more==nullptr){
            lessNow->next=nullptr;
            return less;
        } else {
            lessNow->next=more;    
            moreNow->next=nullptr;
            return less;
        }
    }
};
