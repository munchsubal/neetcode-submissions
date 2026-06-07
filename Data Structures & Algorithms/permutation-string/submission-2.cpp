class Solution {
public:
    bool matches(vector<int>& hash1, vector<int>& hash2) {
        for (int i=0; i<26; i++) {
            if (hash1[i] != hash2[i]) {
                return false;
            }
        }
        return true;
    }

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

        if (matches(hash_s1, hash_substr)) {
            return true;
        }

        while (r < s2.size() - 1) {
            hash_substr[s2[l] - 'a']--;
            l++;
            r++;
            hash_substr[s2[r] - 'a']++;

            if (matches(hash_s1, hash_substr)) {
                return true;
            }
        }   

        return false;
    }
};
