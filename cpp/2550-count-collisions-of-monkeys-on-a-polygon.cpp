/*
    Time: O(log(n))
    Space: O(1);
*/

#define mod 1000000007

class Solution {
public:
    long long pow(int b, int e) {
        if (e == 0) {   
            return 1;
        }
        long long a = pow(b, e/2) % mod;
        if (e % 2) {
            return (((a * a) % mod) * b) % mod; 
        }
        return (a * a) % mod; 
    }
    
    int monkeyMove(int n) {
        return (pow(2, n)-2+mod) % mod;  
    }
};
