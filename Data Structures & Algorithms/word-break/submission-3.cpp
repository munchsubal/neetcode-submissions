class Solution {
private:
    bool solve(int start, string& s, vector<string>& wordDict, vector<pair<bool,bool>>& dp) {
        if (start > s.size() - 1) {
            return true;
        }   

        if (dp[start].second == true) return dp[start].first;

        for (int i=0; i<wordDict.size(); i++) {
            string s1 = wordDict[i];
            string s2 = s.substr(start, s1.size());

            if (s1 == s2 && solve(start + s1.size(), s, wordDict, dp)) {
                dp[start].first = true;
                dp[start].second = true;
                return true;
            }
        }

        dp[start].first = false;
        dp[start].second = true;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<pair<bool,bool>> dp(n, {false, false});
        return solve(0, s, wordDict, dp);
    }
};
