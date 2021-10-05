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
        stack<int> sta1, sta2;
        ListNode* it=l1;
        while(it!=nullptr) {
            sta1.push(it->val);
            it=it->next;
        }
        
        it=l2;
        while(it!=nullptr) {
            sta2.push(it->val);
            it=it->next;
        }
        
        ListNode* ans, *last=nullptr;
        int carry=0;
        while(!sta1.empty() || !sta2.empty() || carry!=0) {
            if(!sta1.empty()) {
                carry+=sta1.top();    
                sta1.pop();
            }
            if(!sta2.empty()) {
                carry+=sta2.top();    
                sta2.pop();
            }
            
            ans=new ListNode(carry%10, last);
            carry/=10;
            last=ans;
        }
        
        return ans;
    }
};
