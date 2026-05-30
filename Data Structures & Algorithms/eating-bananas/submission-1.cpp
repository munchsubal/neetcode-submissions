class Solution {
public:
    int maxElem(vector<int>& nums) {
        int max = -1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }

        return max;
    }  

    int finishTime(vector<int>& piles, int k) {
        int time = 0;
        for (int i=0; i<piles.size(); i++) {
            time += ceil((double)piles[i]/k);
        }

        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxElem(piles);

        while (low <= high) {
            int mid = (low + high) / 2;
            cout << mid << endl;
        
            if (finishTime(piles, mid) > h) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};
