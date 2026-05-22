class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> sorted;
        for (int i=0; i<nums.size(); i++) {
            sorted.push_back({nums[i], i});
        }
        sort(sorted.begin(), sorted.end(), [](pair<int,int> a, pair<int,int> b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int sum = sorted[l].first + sorted[r].first;
            if (sum == target) {
                if (sorted[l].second < sorted[r].second)
                    return {sorted[l].second, sorted[r].second};
                else
                    return {sorted[r].second, sorted[l].second};
            }
            else if (sum > target) {
                r--;
            }
            else {
                l++;
            }
        }

        return {};
    }
};
