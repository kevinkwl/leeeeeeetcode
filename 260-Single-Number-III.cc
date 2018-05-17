class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int n : nums)
            x ^= n;
        int diffbit = x & (-x); // get the least significant different bit
        vector<int> sg(2, 0);
        
        // sg[0] & diffbit != 0, sg[1] & diffbit == 0, we separate the two single number.
        for (int n : nums)
            if (n & diffbit)
                sg[0] ^= n;
        sg[1] = sg[0] ^ x;
        return sg;
    }
};
