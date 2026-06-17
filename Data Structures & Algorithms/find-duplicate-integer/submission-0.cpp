class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> visited(nums.size(), 0);

        for (int i=0; i<nums.size(); i++) {
            if (visited[nums[i]]) {
                return nums[i];
            }
            visited[nums[i]] = 1;
        }
    }
};
