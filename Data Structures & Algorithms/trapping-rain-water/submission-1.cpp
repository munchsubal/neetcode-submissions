class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int trap = 0;
        int l = 1;
        int r = n - 2;
        
        int leftMax = height[0];
        int rightMax = height[n-1];
        while (l <= r) {
            if (leftMax <= rightMax) {
                trap += (leftMax - height[l]) > 0 ? leftMax - height[l] : 0;
                if (leftMax < height[l]) {
                    leftMax = height[l];
                }
                l++;
            }
            else {
                trap += (rightMax - height[r]) > 0 ? rightMax - height[r] : 0;
                if (rightMax < height[r]) {
                    rightMax = height[r];
                }
                r--;
            }
        }

        return trap;
    }
};
