class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> a;

        // Store all 32 bits
        for (int i = 0; i < 32; i++) {
            a.push_back(n & 1);
            n >>= 1;
        }

        uint32_t ans = 0;

        for (int i = 0; i < 32; i++) {
            if (a[i]) {
                ans += (1u << (31 - i));
            }
        }

        return ans;
    }
};