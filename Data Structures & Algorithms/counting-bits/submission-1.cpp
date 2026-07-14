class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1);
        for(int num = 0;num<=n;num++) {
            int i = num;
            while(i!=0) {
                res[num]++;
                i&=(i-1);
            }
        }
        return res;
    }
};
