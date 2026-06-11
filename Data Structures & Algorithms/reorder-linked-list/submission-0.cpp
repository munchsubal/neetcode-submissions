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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* front = nullptr;
        while (curr != nullptr) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow;
        mid->next = reverseList(mid->next);

        ListNode* low = head;
        ListNode* nextLow = nullptr;
        ListNode* high = mid->next;
        ListNode* nextHigh = nullptr;

        while (high != nullptr) {
            nextLow = low->next;
            nextHigh = high->next;

            low->next = high;
            high->next = nextLow;

            low = nextLow;
            high = nextHigh;
        }

        if (low->next == mid) {
            mid->next = nullptr;
        }
        else {
            low->next = nullptr;
        }
    }
};
