/*
    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (idx.find(target-num) != idx.end()) {
                return {idx[target-num], i};
            }
            idx[num] = i;
        }
        return {};
    }
};
