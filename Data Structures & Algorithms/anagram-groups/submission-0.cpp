class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> freq(strs.size(), vector<int>(26, 0));
        for (int i=0; i<strs.size(); i++) {
            for (int j=0; j<strs[i].size(); j++) {
                freq[i][strs[i][j] - 'a']++;
            }
        }

        map<vector<int>, int> mpp;
        vector<vector<string>> ans;
        int idx = 0;
        for (int i=0; i<strs.size(); i++) {
            if (mpp.find(freq[i]) == mpp.end()) {
                ans.push_back({strs[i]});
                mpp.insert({freq[i], idx});
                idx++;
                continue;
            }
            ans[mpp[freq[i]]].push_back(strs[i]);      
        }

        return ans;
    }
};
