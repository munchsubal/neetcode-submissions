class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        
        // Odd length substrings
        for (int mid = 0; mid < s.size(); mid++) {
            for (int x = 0; mid - x >= 0 && mid + x < s.size(); x++) {
                if (s[mid-x] == s[mid+x]) {
                    count++;
                }
                else{
                    break;
                }
            }
        }

        // Even length substrings
        for (int mid = 0; mid < s.size(); mid++) {
            for (int x = 0; mid - x >= 0 && mid + x + 1 < s.size(); x++) {
                if (s[mid-x] == s[mid+x+1]) {
                    count++;
                }
                else{
                    break;
                }
            }
        }

        return count;
    }
};
