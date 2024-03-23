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
private:
    // Helper function to find the middle of the linked list
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Helper function to reverse the linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

public:
    void reorderList(ListNode* head) {
        // Edge case: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // Find the middle of the linked list
        ListNode* middle = findMiddle(head);

        // Reverse the second half of the linked list
        ListNode* secondHalf = reverseList(middle->next);
        middle->next = nullptr; // Disconnect the two halves

        // Merge the first and second halves by alternating the nodes
        ListNode* first = head;
        ListNode* second = secondHalf;

        while (second != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};