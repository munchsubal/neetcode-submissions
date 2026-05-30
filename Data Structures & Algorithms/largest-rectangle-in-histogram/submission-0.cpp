class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> pse(n);
        stack<int> st;
        for (int i=0; i<n; i++) {
            if (st.empty()) {
                st.push(i);
                pse[i] = -1;
                continue;
            }

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                pse[i] = -1;
            }
            else {
                pse[i] = st.top();
            }
            st.push(i);
        }

        vector<int> nse(n);
        st = stack<int>();
        for (int i=n-1; i>=0; i--) {
            if (st.empty()) {
                st.push(i);
                nse[i] = -1;
                continue;
            }

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                nse[i] = -1;
            }
            else {
                nse[i] = st.top();
            }
            st.push(i);
        }

        int maxArea = -1;
        for (int i=0; i<n; i++) {
            int l;
            int r;

            if (pse[i] == -1) {
                l = 0;
            }
            else {
                l = pse[i] + 1;
            }

            if (nse[i] == -1) {
                r = n - 1;
            }
            else {
                r = nse[i] - 1;
            }

            int width = (r - l + 1);
            int height = heights[i];
            int area = width*height;

            if (area > maxArea) {
                maxArea = area;
            }
        }

        return maxArea;
    }
};
