class TimeMap {
private: 
    map<string, vector<pair<string, int>>> mpp;

    string findValue(vector<pair<string, int>>& vals, int target) {
        int n = vals.size();

        int low = 0;
        int high = n - 1;

        string ans;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (vals[mid].second == target) {
                return vals[mid].first;
            }
            else if (vals[mid].second < target) {
                ans = vals[mid].first;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        return findValue(mpp[key], timestamp);
    }
};
