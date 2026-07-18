class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        s.insert(s.begin(), '0');

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = (s[1] != '0');

        for (int i = 2; i <= n; i++) {
            if (s[i] != '0')
                dp[i] += dp[i - 1];

            int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (num >= 10 && num <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};