class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i=0; i<nums.size(); i++) {
            if (freq.find(nums[i]) == freq.end()) {
                freq[nums[i]] = 1;
            }
            else { 
                freq[nums[i]]++;
            }
        }

        vector<vector<int>> buckets(nums.size()+1);
        for (auto &it : freq) {
            buckets[it.second].push_back(it.first);
        }

        vector<int> ans;
        int count = 0;
        for (int i=nums.size(); i>0; i--) {
            while (buckets[i].size() > 0 && count < k) {
                ans.push_back(buckets[i].back());
                buckets[i].pop_back();
                count++;
            }

            if (count == k) {
                break;
            }
        }

        return ans;
    }
};
