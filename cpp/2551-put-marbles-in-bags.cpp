/*
    Time: O(nlog(n))
    Space: O(n)
*/

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long> a(n-1); 
        for (int i = 0; i < n-1; i++) { 
            a[i] = weights[i] + weights[i+1]; 
        }
        sort(a.begin(), a.end()); 
        
        long long minimal, maximal; 
        minimal = maximal = weights[0] + weights[n-1]; 
        for (int i = 0; i < k-1; i++) {
            minimal += a[i]; 
            maximal += a[n-2-i];
        }
        
        return maximal - minimal; 
    }
};
