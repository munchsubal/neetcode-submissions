class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }

        vector<int> hash_s1(26, 0);
        for (int i=0; i<s1.size(); i++) {
            hash_s1[s1[i] - 'a']++;
        }

        int l = 0;
        int r = s1.size() - 1;
        vector<int> hash_substr(26, 0);
        for (int i=l; i<=r; i++) {
            hash_substr[s2[i] - 'a']++;
        }
        
        int matches = 0;
        for (int i=0; i<26; i++) {
            if (hash_s1[i] == hash_substr[i]) {
                matches++;
            }
        }
        if (matches == 26) {
            return true;
        }
        
        while (r < s2.size() - 1) {
            hash_substr[s2[l] - 'a']--;
            if (hash_substr[s2[l] - 'a'] == hash_s1[s2[l] - 'a']) {
                matches++;
            }
            else if (hash_substr[s2[l] - 'a'] == hash_s1[s2[l] - 'a'] - 1) {
                matches--;
            }
            l++;

            r++;
            hash_substr[s2[r] - 'a']++;
            if (hash_substr[s2[r] - 'a'] == hash_s1[s2[r] - 'a']) {
                matches++;
            }
            else if (hash_substr[s2[r] - 'a'] == hash_s1[s2[r] - 'a'] + 1) {
                matches--;
            }

            if (matches == 26) {
                return true;
            }
        }   

        return false;
    }
};
