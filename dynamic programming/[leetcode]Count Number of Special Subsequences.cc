class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int MOD = 1e9 + 7;
        vector<long long> dp(4);
        dp[0] = 1LL;
        for (int num : nums) {
            int nextNum = num + 1;
            dp[nextNum] += (dp[nextNum] + dp[nextNum - 1]);
            dp[nextNum] = dp[nextNum] % MOD;
        }
        return dp[3];
    }
};