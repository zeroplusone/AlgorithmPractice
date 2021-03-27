// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem23.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(0);
        ListNode* now = ans;
        ListNode* minPtr = nullptr;
        
        while(now != nullptr) {
            int minVal = 500000;
            int minPtr = -1;
            for(int i=0;i<lists.size();++i) {
                ListNode* node = lists[i];
                if(node != nullptr && (node->val)<minVal) {
                    minVal = node->val;
                    minPtr = i;
                }
            }
            if(minPtr!=-1) {
                lists[minPtr] = lists[minPtr]->next;
            }
            now->next = new ListNode(minVal);
            now = now->next;
        }
        return ans->next;
    }
};
// @lc code=end

