class Solution {
private:
    int hash_idx(char c) {
        if (c >= 'a' && c <= 'z') {
            return c - 'a';
        }
        return c - 'A' + 26;
    }

public:
    string minWindow(string s, string t) {
        vector<int> hash_t(52, 0);
        int count_distinct = 0;
        for (int i=0; i<t.size(); i++) {
            if (hash_t[hash_idx(t[i])] == 0) {
                count_distinct++;
            }
            hash_t[hash_idx(t[i])]++;
        }

        cout << count_distinct << endl;

        int l = 0;
        int r = -1;
        int cnt = 0;

        int start = -1;
        int len = INT_MAX;
        int size = s.size();
        vector<int> hash_substr(52, 0);
        while (r < size - 1 || cnt == count_distinct) {
            if (cnt != count_distinct) {
                r++;
                hash_substr[hash_idx(s[r])]++;
                if (hash_substr[hash_idx(s[r])] == hash_t[hash_idx(s[r])]) {
                    cnt++;
                }

                cout << "Hello" << endl;
            }
            else {
                if (len > r - l + 1) {
                    start = l;
                    len = r - l + 1;
                }
                hash_substr[hash_idx(s[l])]--;
                if (hash_t[hash_idx(s[l])] - 1 == hash_substr[hash_idx(s[l])]) {
                    cnt--;
                }
                l++;
            }
        }

        return start == -1 ? "" : s.substr(start, len);
    }
};
