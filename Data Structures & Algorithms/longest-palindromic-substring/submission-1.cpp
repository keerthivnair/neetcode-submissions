class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 0;
        string res;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                int l = i,r = j;
                while(l<=r && s[l]==s[r]) {
                    l++;r--;
                }
                if(l>r){
                    maxlen = max(maxlen,j-i+1);
                    if(maxlen == j-i+1) res = s.substr(i,j-i+1);
                }
            }
        }
        return res;
    }
};
