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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }

        ListNode* l = list1;
        ListNode* r = list2;

        ListNode* merged_head = nullptr;
        ListNode* curr = nullptr;

        while (l != nullptr && r != nullptr) {
            if (l->val <= r->val) {
                ListNode* newNode = new ListNode(l->val, nullptr);
                if (curr == nullptr) {
                    merged_head = newNode;
                    curr = newNode;
                }
                else{
                    curr->next = newNode;
                    curr = newNode;
                }
                l = l->next;
            }
            else {
                ListNode* newNode = new ListNode(r->val, nullptr);
                if (curr == nullptr) {
                    merged_head = newNode;
                    curr = newNode;
                }
                else {
                    curr->next = newNode;
                    curr = newNode;
                }
                r = r->next;
            }
        }

        while (l != nullptr) {
            ListNode* newNode = new ListNode(l->val, nullptr);
            if (curr == nullptr) {
                merged_head = newNode;
                curr = newNode;
            }
            else {
                curr->next = newNode;
                curr = newNode;
            }
            l = l->next;
        }

        while (r != nullptr) {
            ListNode* newNode = new ListNode(r->val, nullptr);
            if (curr == nullptr) {
                merged_head = newNode;
                curr = newNode;
            }
            else {
                curr->next = newNode;
                curr = newNode;
            }
            r = r->next;
        }

        return merged_head;
    }
};
