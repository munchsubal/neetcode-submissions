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
    pair<int, int> getMinValAndIdx(const vector<ListNode*>& v) {
        int minVal = INT_MAX;
        int minIdx = -1;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] != nullptr && v[i]->val < minVal) {
                minVal = v[i]->val;
                minIdx = i;
            }
        }

        if (minIdx == -1) {
            return {-1, -1}; // all entries were nullptr
        }

        return {minVal, minIdx};
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = nullptr;
        ListNode* tail = dummyNode;

        if (k == 0) {
            return nullptr;
        }
        if (k == 1) {
            return lists[0];
        }

        int cnt_null = 0;
        for (int i=0; i<k; i++) {
            if (lists[i] == nullptr) {
                cnt_null++;
            }
        }

        if (cnt_null == k) {
            return nullptr;
        }

        while (true) {
            auto [minVal, minIdx] = getMinValAndIdx(lists);
            ListNode* newNode = new ListNode(minVal);
            tail->next = newNode;
            tail = newNode;

            lists[minIdx] = lists[minIdx]->next;
            if (lists[minIdx] == nullptr) {
                cnt_null++;
            }

            if (cnt_null == k) {
                break;
            }
        }

        return dummyNode->next;
    }
};
