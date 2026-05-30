class Solution {
public:
    int findRow(vector<vector<int>>& matrix, int target, int m, int low, int high) {
        if (low > high) {
            return -1;
        }

        int mid = low + (high - low) / 2;

        if (matrix[mid][0] <= target && target <= matrix[mid][m - 1]) {
            return mid;
        }

        if (target < matrix[mid][0]) {
            return findRow(matrix, target, m, low, mid-1);
        }
        else {
            return findRow(matrix, target, m, mid+1, high);
        }

        return -1;
    }

    bool findNum(vector<int>& nums, int target, int low, int high) {
        if (low > high) {
            return false; 
        }

        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return true;
        }
        
        if (nums[mid] > target) {
            return findNum(nums, target, low, mid - 1);
        }
        else {
            return findNum(nums, target, mid + 1, high);
        }
    
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = findRow(matrix, target, n, 0, m-1);
        cout << row << endl;

        if (row == -1) {
            return false;
        }
        return findNum(matrix[row], target, 0, n-1);
    }
};
