class Solution {
private:
    bool valid_code(string s) {
        if (s[0] == '0') return false;
        int num_code = stoi(s);
        if (num_code > 0 && num_code <= 26) {
            return true;
        }
        return false;
    }
public:
    int numDecodings(string s) {
        int n = s.size();

        if (n == 1) return valid_code(s.substr(0, 1)) ? 1 : 0;

        vector<int> dp(n, 0);   
        dp[0] = valid_code(s.substr(0, 1)) ? 1 : 0;

        for (int i=1; i<n; i++) {
            if (i == 1) {
                if (valid_code(s.substr(1, 1))) {
                    dp[1] = dp[0];
                }
                if (valid_code(s.substr(0, 2))) {
                    dp[1] += 1;
                }
                continue;
            }
            int take_two = 0;
            if (valid_code(s.substr(i-1, 2))) {
                take_two = dp[i-2];
            }
            int take_one = 0;
            if (valid_code(s.substr(i, 1))) {
                take_one = dp[i-1];
            }

            dp[i] = take_one + take_two;
        }

        return dp[n-1];
    }
};
