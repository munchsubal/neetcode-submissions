class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int m = wordDict.size();
        vector<bool> dp(n, false);

        for (int j=0; j<m; j++) {
            if (wordDict[j] == s.substr(0, 1)) {
                dp[0] = true;
            }
        }

        for (int i=1; i<n; i++) {
            for (int j=0; j<m; j++) {
                string s1 = wordDict[j];
                int len = s1.size();
                
                if (i - len + 1 < 0) {
                    continue;
                }

                string s2 = s.substr(i - len + 1, len);

                if (s1 == s2) {
                    if (i - len + 1 == 0) {
                        dp[i] = true;
                    }
                    else if (dp[i - len]){
                        dp[i] = true;
                    }

                    if (dp[i]) {
                        break;
                    }
                }
            }
        }

        return dp[n-1];
    }
};
