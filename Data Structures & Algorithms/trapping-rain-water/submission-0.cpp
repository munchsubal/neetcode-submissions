class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);

        lmax[0] = -1;  
        for (int i=1; i<n; i++) {
            lmax[i]= height[i-1] > lmax[i-1] ? height[i-1] : lmax[i-1];
        }

        rmax[n-1] = -1;
        for (int i=n-2; i>=0; i--) {
            rmax[i] = height[i+1] > rmax[i+1] ? height[i+1] : rmax[i+1];
        }

        int trap = 0;
        for (int i=0; i<n; i++) {
            int amt = min(lmax[i], rmax[i]) - height[i];
            if (amt > 0) {
                trap += amt;
            }
        }

        return trap;
    }
};
