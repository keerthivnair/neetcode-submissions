class Solution {
    vector<vector<int>> dp;

public:
    int longestCommonSubsequence(string text1, string text2) {

        int n=text1.size();
        int m=text2.size();

        dp.assign(n,vector<int>(m,-1));

        return maxlen(0,0,text1,text2);
    }

private:

    int maxlen(int i,int j,string &s1,string &s2){

        if(i>=s1.size() || j>=s2.size())
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        if(s1[i]==s2[j])
            return dp[i][j]=1+maxlen(i+1,j+1,s1,s2);

        return dp[i][j]=max(
            maxlen(i+1,j,s1,s2),
            maxlen(i,j+1,s1,s2)
        );
    }
};