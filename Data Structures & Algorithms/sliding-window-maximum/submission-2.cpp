class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        vector<int> ans;

        int l = 0;
        int r = k - 1;

        for (int i=l; i<=r; i++) {
            while (!dq.empty() && dq.back().first < nums[i]) {
                dq.pop_back();
            }
            dq.push_back({nums[i], i});
        }

        ans.push_back(dq.front().first);

        while (r < nums.size() - 1) {
            l++;
            r++;

            while (!dq.empty() && dq.back().first < nums[r]) {
                dq.pop_back();
            }
            dq.push_back({nums[r], r});

            while (dq.front().second < l) {
                dq.pop_front();
            }
            ans.push_back(dq.front().first);
        }

        return ans;
    }
};
