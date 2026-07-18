class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int x = 1;x <= amount; x++) {
            for(int j = 0;j < n; j++) {
                if(x>=coins[j] && dp[x-coins[j]]!=INT_MAX) {
                    dp[x] = min(dp[x],dp[x-coins[j]]+1);
                }
            }
        }
        if(dp[amount]==INT_MAX) return -1;
        else return dp[amount];
    }
};
