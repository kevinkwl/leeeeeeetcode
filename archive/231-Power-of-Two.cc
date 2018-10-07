class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n - (n & -n)) == 0;
    }
};

// n - (n & -n) : remove the least significant bit that is 1.
//  or n & (n - 1)  == 0 , this holds when n has only 1 bit on. 
