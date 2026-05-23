class Solution {
public:
    int applyOper(int a, int b, string oper) {
        if (oper == "+") {
            return a+b;
        } 
        else if (oper == "-") {
            return a-b;
        }
        else if (oper == "*") {
            return a*b;
        }
        else {
            return a/b;
        }
    }

    int evalRPN(vector<string>& tokens) {
        
        int n = tokens.size();
        stack<int> st;
        for (int i=0; i<n; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                st.push(applyOper(b, a, tokens[i]));
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};
