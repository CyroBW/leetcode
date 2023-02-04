/*
    Time: O(n^2)
    Space: O(n)
*/ 

class Solution {
public:
    int dp[1001]; 

    int dfs(vector<int>& nums, int k, int i, int n) {
        if (i == n) {
            return 0; 
        }
        if (dp[i] != -1) {
            return dp[i]; 
        }
        
        int res = INT_MAX;
        int cost = 0; 
        vector<int> cnt(n);
        for (int j = i; j < n; j++) {
            cnt[nums[j]]++; 
            if (cnt[nums[j]] == 2) {
                cost += 2; 
            }
            else if (cnt[nums[j]] > 2) {
                cost++; 
            }
            res = min(res, cost + k + dfs(nums, k, j+1, n)); 
        }
        
        return dp[i] = res;  
    }

    int minCost(vector<int>& nums, int k) {
        memset(dp, -1, sizeof dp); 
        return dfs(nums, k, 0, nums.size()); 
    }
};
