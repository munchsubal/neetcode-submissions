class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars(n);

        for (int i=0; i<n; i++) {
            cars[i].first = position[i];
            cars[i].second = speed[i];
        }

        sort(cars.begin(), cars.end());

        stack<pair<int, int>> st;
        for (int i=n-1; i>=0; i--) {
            if (st.empty()) {
                st.push(cars[i]);
                continue;
            }

            pair<int, int> next_fleet = st.top();
            pair<int, int> curr = cars[i];

            double t_next_fleet = (double)(target - next_fleet.first) / next_fleet.second;
            double t_curr = (double)(target - curr.first) / curr.second;

            if (t_curr > t_next_fleet) {
                st.push(curr);
            }
        }

        return st.size();
    }
};
