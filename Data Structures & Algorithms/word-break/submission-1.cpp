class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>words(wordDict.begin(),wordDict.end());
        queue<int>q;
        set<int>seen;
        q.push(0);
        seen.insert(0);
        while(!q.empty()) {
            int start = q.front();
            q.pop();
            if(start == s.size()) return true;
            for(int end = start+1;end<=s.size();end++) {
                if(seen.find(end)!=seen.end()) continue;

                if(words.find(s.substr(start,end-start))!=words.end()) {
                    seen.insert(end);
                    q.push(end);
                }
            }
        }
        return false;
    }
};