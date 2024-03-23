class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *prev = nullptr, *curr = list1;

        // Move to the node before 'a'
        for (int i = 0; i < a; ++i) {
            prev = curr;
            curr = curr->next;
        }

        // Save the remaining part of list1
        ListNode* remainingList = nullptr;
        ListNode* tempCurr = curr;
        for (int i = a; i <= b; ++i) {
            if (i == b) {
                remainingList = tempCurr->next;
                tempCurr->next = nullptr;
            } else {
                tempCurr = tempCurr->next;
            }
        }

        // Connect list2 to list1
        prev->next = list2;

        // Find the end of list2
        while (list2->next != nullptr) {
            list2 = list2->next;
        }

        // Connect end of list2 to the remaining part of list1
        list2->next = remainingList;

        return list1;
    }
};