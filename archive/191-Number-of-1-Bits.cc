class Solution {
public:
    int hammingWeight(uint32_t n) {
        int m = 0x11111111;
        int s = n & m;
        s += (n >> 1) & m;
        s += (n >> 2) & m;
        s += (n >> 3) & m;
        
        s = (s & 0xffff) + ((s >> 16) & 0xffff);
        s = (s & 0x0f0f) + ((s >> 4) & 0x0f0f);
        return (s & 0x3f) + ((s >> 8) & 0x3f);
    }
};
