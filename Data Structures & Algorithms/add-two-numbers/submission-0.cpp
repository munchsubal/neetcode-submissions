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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;

        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int cin = 0;
        while (p1 != nullptr && p2 != nullptr) {
            int sum = p1->val + p2->val + cin;
            ListNode* newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = newNode;
            
            cin = sum / 10;
            p1 = p1->next;
            p2 = p2->next;
        }

        while (p1 != nullptr) {
            int sum = p1->val + cin;
            ListNode* newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = newNode;
            
            cin = sum / 10;
            p1 = p1->next;
        }

        while (p2 != nullptr) {
            int sum = p2->val + cin;
            ListNode* newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = newNode;
            
            cin = sum / 10;
            p2 = p2->next;
        }

        if (cin != 0) {
            ListNode* newNode = new ListNode(cin);
            curr->next = newNode;
            curr = newNode;
        }

        return dummyNode->next;
    }
};
