class Solution {
public:

    int find(vector<int>& nums, int target, int low, int high) {
        int mid = (low + high) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        while (low <= high) {
            if (nums[mid] > target) {
                return find(nums, target, low, mid - 1);
            }
            return find(nums, target, mid + 1, high);
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        return find(nums, target, 0, n-1);
    }
};
