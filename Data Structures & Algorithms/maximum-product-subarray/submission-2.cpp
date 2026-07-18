class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pref = 0,suff = 0;
        int res = INT_MIN;
        for(int i=0;i<n;i++) {
            pref = nums[i] * (pref == 0 ? 1 : pref);
            suff = nums[n-i-1] * (suff == 0 ? 1 : suff);

            res = max(res,max(pref,suff));
        }
        return res;
    }
};