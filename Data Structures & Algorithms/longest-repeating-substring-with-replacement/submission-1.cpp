class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        
        int max_length = 0;
        int hash[26] = {0};
        int max_freq = 0;
        while (r < s.size()) {
            hash[s[r] - 'A']++;
            max_freq = max(max_freq, hash[s[r] - 'A']);

            if ((r-l+1) - max_freq > k) {
                hash[s[l] - 'A']--;

                l++;
            }
            
            if ((r-l+1) - max_freq <= k) {
                max_length = max(max_length, r-l+1);
            }
            r++;
        }

        return max_length;
    }
};
