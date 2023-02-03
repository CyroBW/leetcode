/*
    Time: O(log(min(n, m)))
    Space: O(1)
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0;
        int r = nums1.size();
        while (l <= r) {
            int p1 = (l+r)/2;
            int p2 = (nums1.size()+nums2.size())/2-p1;
            int l1 = p1 <= 0            ? INT_MIN : nums1[p1-1];
            int r1 = p1 >= nums1.size() ? INT_MAX : nums1[p1];
            int l2 = p2 <= 0            ? INT_MIN : nums2[p2-1];
            int r2 = p2 >= nums2.size() ? INT_MAX : nums2[p2];
            if (l1 > r2) {
                r = p1-1;
            }
            else if (l2 > r1) {
                l = p1+1;
            }
            else {
                if ((nums1.size()+nums2.size())%2) {
                    return min(r1, r2);
                }
                return (min(r1, r2)+max(l1, l2))/2.0;
            }
        }
        return 0;
    }
};
