class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,INT_MIN));
        dp[0][1] = -prices[0];
        dp[0][0] = 0;
        
        if(n>1){
        dp[1][1] = max(dp[0][1],-prices[1]);
        dp[1][0] = max(0,prices[1]-prices[0]);
        }

        for(int i = 2;i<n;i++) {   
        dp[i][1] = max(dp[i-1][1],dp[i-2][0]-prices[i]);
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
        }
        return max(dp[n-1][1],dp[n-1][0]);
    }
};
