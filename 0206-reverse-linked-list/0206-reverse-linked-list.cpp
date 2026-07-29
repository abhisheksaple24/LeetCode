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
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL) {

            // Store next node
            next = curr->next;

            // Reverse current node's pointer
            curr->next = prev;

            // Move prev and curr one step ahead
            prev = curr;
            curr = next;
        }

        // New head of reversed list
        return prev;
    }
};