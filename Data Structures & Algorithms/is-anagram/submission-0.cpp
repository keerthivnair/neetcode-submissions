class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        string y = t;
        sort(y.begin(),y.end());
        if(s==y) return true; return false;
    }
};
