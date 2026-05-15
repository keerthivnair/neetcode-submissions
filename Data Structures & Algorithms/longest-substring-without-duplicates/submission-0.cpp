class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int n = s.size();
        int maxlen = 0,start = 0;
        for(int i=0;i<n;i++) {
            if(mpp.find(s[i])!=mpp.end()) {
                start = max(start,mpp[s[i]]+1);
            }
            mpp[s[i]] = i;
            maxlen = max(maxlen,i-start+1);
        }
        return maxlen;
    }
};
