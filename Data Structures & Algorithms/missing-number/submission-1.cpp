class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xore = 0;
        for(int i=0;i<=n;i++) {
           nums.push_back(i);
        }
        for(int i=0;i<nums.size();i++) xore^=nums[i];
        return xore;
    }
};
