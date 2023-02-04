/*
    Time: O(n*m);
    Space: O(n*m)
*/

class Solution {
public:
    int dp[20][30];

    bool dfs(string& s, string& p, int l, int r, int n, int m) {
        if (r == m) {
            return l == n;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        bool res = false;
        if (r+1<m && p[r+1] == '*') {
            if (l < n && (s[l] == p[r] || p[r] == '.')) {
                res |= dfs(s, p, l+1, r+2, n, m);
                res |= dfs(s, p, l+1, r, n, m);
            }
            res |= dfs(s, p, l, r+2, n, m);
        }
        else if (l < n && (s[l] == p[r] || p[r] == '.')) {
            res |= dfs(s, p, l+1, r+1, n, m);
        }

        return dp[l][r] = res;
    }
  
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof dp);
        return dfs(s, p, 0, 0, s.size(), p.size());
    }
};
