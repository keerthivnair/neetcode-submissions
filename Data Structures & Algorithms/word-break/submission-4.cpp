class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n+1);
        dp[n] = 1;

        for(int i=n-1;i>=0;i--) {
            for(auto& word:wordDict) {
               if(i+word.size()<=s.size()  && 
               s.substr(i,word.size())==word
               )
               {
                dp[i] |= dp[i+word.size()];
               }
            }
        }
        return dp[0]==1;
    }
};