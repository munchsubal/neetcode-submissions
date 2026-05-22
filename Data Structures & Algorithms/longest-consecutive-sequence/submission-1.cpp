class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        for (int i=0; i<n; i++) {
            st.insert(nums[i]);
        }

        int maxCount = 1;
        for (auto& num : st) {
            if (st.count(num - 1) == 0) {
                int count = 1;
                int curr = num;

                while (st.count(curr + 1) > 0) {
                    count++;
                    curr++;
                }
                if (count > maxCount) {
                    maxCount = count;
                }
            }
        }

        return maxCount;
    }
};
