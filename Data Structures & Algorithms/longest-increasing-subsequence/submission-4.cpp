class Solution {
private:
    int lowerBound(vector<int>& arr, int l, int r, int target) {
        int low = l;
        int high = r;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }   

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int last = -1;
        for (int i=0; i<nums.size(); i++) {
            int len = ans.size();
            if (len == 0) {
                ans.push_back(nums[i]);
                last = 0;
                continue;
            }

            if (ans[last] < nums[i]) {
                ans.push_back(nums[i]);
                last++;
            }
            else {
                int idx = lowerBound(ans, 0, last, nums[i]);
                ans[idx] = nums[i];
            }
        }

        return ans.size();
    }
};
