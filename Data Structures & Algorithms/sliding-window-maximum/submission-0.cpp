class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        int l = 0;
        int r = k - 1;
        for (int i = l; i <= r; i++) {
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);
        while (r < nums.size() - 1) {
            l++;
            r++;
            pq.push({nums[r], r});
            
            while (pq.top().second < l) {
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};
