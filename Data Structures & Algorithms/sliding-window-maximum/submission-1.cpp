class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> ans;

        int l = 0;
        int r = k - 1;
        for (int i = l; i <= r; i++) {
            ms.insert(nums[i]);
        }

        ans.push_back(*ms.rbegin());
        while (r < nums.size() - 1) {
            ms.erase(ms.find(nums[l]));
            l++;
            r++;
            ms.insert(nums[r]);

            ans.push_back(*ms.rbegin());
        }

        return ans;
    }
};
