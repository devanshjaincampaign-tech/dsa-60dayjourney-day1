class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int range = r - l + 1;
        int MOD = 1e9 + 7;
        
        vector<long long> dp(range, 1);
        
        for (int i = 1; i < n; ++i) {
            vector<long long> next_dp(range, 0);
            long long prefix_sum = 0;
            
            if (i % 2 == 1) {
                for (int v = 0; v < range; ++v) {
                    next_dp[v] = prefix_sum;
                    prefix_sum = (prefix_sum + dp[v]) % MOD;
                }
            } else {
                for (int v = range - 1; v >= 0; --v) {
                    next_dp[v] = prefix_sum;
                    prefix_sum = (prefix_sum + dp[v]) % MOD;
                }
            }
            dp = move(next_dp);
        }
        
        long long total = 0;
        for (long long count : dp) {
            total = (total + count) % MOD;
        }
        
        return (total * 2) % MOD;
    }
};