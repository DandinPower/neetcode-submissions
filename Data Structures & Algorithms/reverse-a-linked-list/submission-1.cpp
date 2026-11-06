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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* curr = head;
        ListNode* curr_reverse_next = head;
        ListNode* original_next = curr->next;
        curr->next = nullptr;
        while(original_next != nullptr) {
            curr = original_next;
            original_next = curr->next;
            curr->next = curr_reverse_next;
            curr_reverse_next = curr;
        }
        return curr;
    }
};
