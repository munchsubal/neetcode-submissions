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

        ListNode* dummyNode = new ListNode(-1, nullptr);
        ListNode* prev = dummyNode;

        while (l != nullptr && r != nullptr) {
            if (l->val <= r->val) {
                prev->next = l;
                prev = l;
                l = l->next;
            }
            else {
                prev->next = r;
                prev = r;
                r = r->next;
            }
        }

        if (l != nullptr) {
            prev->next = l;
        }

        if (r != nullptr) {
            prev->next = r;
        } 

        return dummyNode->next;
    }
};
