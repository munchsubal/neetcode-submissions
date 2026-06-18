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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = nullptr;
        ListNode* prev = dummyNode;

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i=0; i<k; i++) {
            if (lists[i] != nullptr) {
                pq.push({lists[i]->val, i});
            }
        }

        while (!pq.empty()) {
            int minIdx = pq.top().second;
            ListNode* minValNode = lists[pq.top().second];
            pq.pop();
            prev->next = minValNode;
            prev = minValNode;

            lists[minIdx] = lists[minIdx]->next;
            if (lists[minIdx] != nullptr) {
                pq.push({lists[minIdx]->val, minIdx});
            }
        }

        prev->next = nullptr;

        return dummyNode->next;
    }
};
