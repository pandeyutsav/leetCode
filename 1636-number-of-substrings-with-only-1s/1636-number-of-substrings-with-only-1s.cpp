class Solution {
public:
    int numSub(string s) {
        long long MOD = 1e9 + 7;
        long long count = 0; 
        long long ans = 0;

        for (char c : s) {
            if (c == '1') {
                count++;
            } else {
                ans = (ans + (count * (count + 1) / 2) % MOD) % MOD;
                count = 0;
            }
        }
        ans = (ans + (count * (count + 1) / 2) % MOD) % MOD;

        return ans;

    }
};