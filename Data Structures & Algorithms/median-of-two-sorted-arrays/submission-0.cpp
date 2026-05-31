class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;

        vector<int> smaller;
        vector<int> larger;
        if (n < m) {
            smaller = nums1;
            larger = nums2;
        } else {
            smaller = nums2;
            larger = nums1;
        }

        int low = 0;
        int high = min(n, m);

        while (low <= high) {
            int mid = (low + high) / 2;

            int count_smaller = mid;
            int count_larger = (total + 1) / 2 - mid;

            int l1 = count_smaller == 0 ? INT_MIN : smaller[count_smaller - 1];
            int l2 = count_larger == 0 ? INT_MIN : larger[count_larger - 1];
            int r1 = count_smaller == min(n, m) ? INT_MAX : smaller[count_smaller];
            int r2 = count_larger == max(n, m) ? INT_MAX : larger[count_larger];

            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 == 0) {
                    return (double)(max(l1, l2) + min(r1, r2)) / 2;
                }
                return max(l1, l2);
            }
            else if (l1 > r2) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return -1;
    }
};
