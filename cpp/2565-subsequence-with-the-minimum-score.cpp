/*
    Time: O(n+m)
    Space: O(n+m)
*/ 

class Solution {
public:
    int left, right;
    int n, m;

    int minimumScore(string s, string t) {
        n = s.size();
        m = t.size();
        vector<pair<int, int>> l, r;
        int i = 0, j = 0;
        l.emplace_back(-1, -1);
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                l.emplace_back(i, j);
                j++;
            }
            i++;
        }
        i = n-1, j=m-1;
        r.emplace_back(n, m);
        while (i >=0 && j >= 0) {
            if (s[i] == t[j]) {
                r.emplace_back(i, j);
                j--;
            }
            i--;
        }
        reverse(r.begin(), r.end());

        int res = m;
        i = 0, j = 0;
        while (i < l.size()) {
            while (!(r[j].first > l[i].first && r[j].second > l[i].second)) {
                j++;
            }
            res = min(res, r[j].second - l[i].second - 1);
            i++;
        }

        return res;
    }
};
