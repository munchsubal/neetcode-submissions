class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        
        int l = 0;
        int r = 0;
        unordered_map<char, int> mpp;

        while (r < s.size()) {
            if (mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l) {
                l = mpp[s[r]] + 1;
            }

            
            max_length = max(max_length, r-l+1);
            mpp[s[r]] = r;
            r++;
            
        }

        return max_length;
    }
};
