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
    ListNode* helper(ListNode* prev, ListNode* curr) {
        // 每一層要做的事情是:
        // 1. 先把 curr->next 存起來成 next
        // 2. 把 curr->next = prev
        // 3. recursive call curr, next (參數名 prev, 參數名 curr)
        // 一路把最底的 head 傳上來, 以 0->1->2->3 的 case 來說，重點就是要把 3 這個 node 回傳到最外層
        // 所以可以當作新的 head return 出去
        ListNode* next = curr->next;
        curr->next = prev;
        if (next == nullptr) {
            return curr;
        }
        return helper(curr, next);
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        return helper(nullptr, head);
    }
};
