class Solution {
    void findSubsets(int idx, vector<int>& nums, vector<int>& subset, vector<vector<int>>& subsets) {
        if (idx >= nums.size()) {
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        findSubsets(idx + 1, nums, subset, subsets);
        subset.pop_back();
        findSubsets(idx + 1, nums, subset, subsets);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<int> subset = {};
        findSubsets(0, nums, subset, ans);
        return ans;
    }
};
