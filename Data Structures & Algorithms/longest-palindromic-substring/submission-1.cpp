class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int bestStart = -1;

        // Odd length substrings
        for (int mid = 0; mid < s.size(); mid++) {
            for (int x = 0; mid - x >= 0 && mid + x < s.size(); x++) {
                if (s[mid - x] == s[mid + x]) {
                    int len = 2 * x + 1;

                    if (len > maxLen) {
                        bestStart = mid - x;
                        maxLen = len;
                    }
                }
                else {
                    break;
                }
            }
        }

        // Even length substrings
        for (int mid = 0; mid < s.size(); mid++) {
            for (int x = 0; mid - x >= 0 && mid + x + 1 < s.size(); x++) {
                if (s[mid-x] == s[mid+x+1]) {
                    int len = 2 * x + 2;

                    if (len > maxLen) {
                        bestStart = mid - x;
                        maxLen = len;
                    }
                }
                else {
                    break;
                }
            }
        }

        return s.substr(bestStart, maxLen);
    }
};
