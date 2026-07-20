class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0] = 1;
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(i==0 && j==0) continue;
                if(check(i,j-1,m,n)) dp[i][j]+=dp[i][j-1];
                if(check(i-1,j,m,n)) dp[i][j]+=dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
private:
       bool check(int i,int j ,int n,int m) {
        if(i>=0 && i<n && j>=0 && j<m) return true;
        return false;
       }    
};
