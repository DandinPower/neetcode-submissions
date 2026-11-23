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
    ListNode* helper(ListNode* prev, ListNode* curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        if (next == nullptr) {
            return curr;
        }
        return helper(curr, next);
    }

public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        return helper(nullptr, head);
    }
};
