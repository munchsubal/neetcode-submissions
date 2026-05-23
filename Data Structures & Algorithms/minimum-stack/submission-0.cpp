class MinStack {
public:
    stack<int> st;
    vector<int> mins;
    
    void push(int val) {
        st.push(val);

        if (mins.empty() || val < mins.back()) {
            mins.push_back(val);
        } else {
            mins.push_back(mins.back());
        }
    }
    
    void pop() {
        st.pop();
        mins.pop_back();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.back();
    }
};