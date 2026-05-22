class Solution {
public:
    int min(int a, int b) {
        return a < b ? a : b;
    }

    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int max = 0;
        while (l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            if (area > max) {
                max = area;
            }

            if (heights[l] > heights[r]) {
                r--;
            }
            else if (heights[l] < heights[r]) {
                l++;
            }
            else {
                l++;
                r--;
            }
        }

        return max;
    }
};
