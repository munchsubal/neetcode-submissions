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

        ListNode* prev = nullptr;
        ListNode* curr = head;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* tail = dummyNode;
        int cnt = 0;
        while (true) {
            if (cnt != 0 && cnt % k == 0) {
                tail->next = prev;
                tail = head;
                head = curr;
                prev = nullptr;
                
                if (total - cnt < k) {
                    tail->next = head;
                    break;
                }
                else {
                    ListNode* front = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = front;
                    cnt++;
                }
            }
            else {
                ListNode* front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
                cnt++;
            }
        }

        return dummyNode->next;
    }
};
