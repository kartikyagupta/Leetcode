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
#include <unordered_map>

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        std::unordered_map<int, ListNode*> sumMap;
        int sum = 0;
        for (ListNode* current = dummy; current != nullptr; current = current->next) {
            sum += current->val;
            sumMap[sum] = current;
        }
        
        sum = 0;
        for (ListNode* current = dummy; current != nullptr; current = current->next) {
            sum += current->val;
            current->next = sumMap[sum]->next;
        }
        
        return dummy->next;
    }
};
