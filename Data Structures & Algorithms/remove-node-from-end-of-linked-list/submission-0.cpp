
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            cnt++;
        }

        int pos = (cnt - n + 1);
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (pos > 1) {
            prev = curr;
            curr = curr->next;
            pos--;
        }

        if (prev == nullptr) {
            return curr->next;
        }
        else {
            prev->next = curr->next;
            curr->next = nullptr;
        }

        return head;
    }
};
