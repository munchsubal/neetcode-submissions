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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int total = 0;
        while (temp != nullptr) {
            temp = temp->next;
            total++;
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* tail = dummyNode;

        ListNode* curr = head;
        while (total >= k) {
            ListNode* groupHead = curr;
            ListNode* prev = nullptr;

            for (int i = 0; i < k; i++) {
                ListNode* front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }

            tail->next = prev;

            tail = groupHead;
            total -= k;
        }

        tail->next = curr;

        return dummyNode->next;
    }
};
