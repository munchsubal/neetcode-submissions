class Solution {
public:
    bool matches(char b1, char b2) {
        if (b1 == '(' && b2 == ')') {
            return true;
        }
        else if (b1 == '{' && b2 == '}') {
            return true;
        }
        else if (b1 == '[' && b2 == ']') {
            return true;
        }
        return false;
    }

    bool isValid(string s) {
        stack<char> st;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                else if (!matches(st.top(), s[i])) {
                    return false;
                }
                st.pop();
            }
        }

        if (!st.empty()) {
            return false;
        }
        return true;
    }
};
