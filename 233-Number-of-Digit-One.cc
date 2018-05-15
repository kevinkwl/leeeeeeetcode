class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        int M = 1, ones_in_max = 0;
        int N = n;
        
        // in each iteration, we are calcuating number of digit 1 s from 0 ~ (n % 10M)
        // #[0, K] = number of digit 1 from 0 to K
        while (N > 0) {
            // get the current digit
            int d = N % 10;
            
            // suppose we're currently dealing with dxyz, where res = #[0, xyz]
            
            // if d == 0, then the #1s from 0 ~ dxyz is the same as #1s from 0 ~ xyz
            if (d > 0) {
                
                // add the contribution of current digit
                // if d == 1, #[d000, dxyz] = xyz + 1 + #[0, xyz]
                if (d == 1)
                    res += (n % M) + 1;
                
                // if d != 1, [1000, 1999] is in range [0, dxyz]
                else    
                    res += M;
                
                // remaining 1 s in digit lower than current digit
                // ones_in_max = #[0, 999]
                res += d * ones_in_max;
            }
            
            // update ones_in_max to denote #[0, 9999]
            ones_in_max = 10 * ones_in_max + M;
            M *= 10;
            N /= 10;
        }
        return res;
    }
};
