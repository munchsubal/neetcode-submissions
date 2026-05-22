class Solution {
public:
    string encode(vector<string>& strs) {
        string s = "";
        for (int i=0; i<strs.size(); i++) {
            s += to_string(strs[i].size());
            s += 'e';
            s += strs[i];
        }

        cout << s << endl;

        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        for (int i=0; i<s.size();) {
            int size = 0;
            int idx = i;
            int count_digits = 0;
            while (s[idx] != 'e') {
                count_digits++;
                size = size * 10 + (s[idx] - '0');
                idx++;
            }

            cout << "Hello" << endl;

            string str = "";
            for (int j=i+count_digits+1; j<=i+size+count_digits; j++) {
                str += s[j];
            }

            strs.push_back(str);
            i = i + size + count_digits + 1;
        }

        return strs;
    }
};
