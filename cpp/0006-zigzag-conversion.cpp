/**
    Time: O(n)
    Space: O(1)
**/

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int n = s.size();
        int a = 2*(numRows-1);
        for (int i = 0; i < numRows; i++) {
            int b = a-2*i;
            int j = i;
            while (j < n) {
                if (b == 0) {
                    b = a;
                }
                res += s[j];
                if (b == 0) {
                    j++;
                }
                else {
                    j += b;
                }
                b = a - b;
            }
        }
        return res;
    }
};
