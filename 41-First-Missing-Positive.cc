class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0; i < N; i++)
            if (nums[i] < 0)
                nums[i] = 0;        // clean up negative number

        int idx;
        for (int i = 0; i < N; i++) {
            idx = abs(nums[i]);
            
            // num[i] does not contain positive number at the beginning or the number is out-of-range[1,N], 
            // we only need to focus on integers 1 ... N
            if (idx == 0 || idx >= N + 1)   
                continue;
            
            // abs(nums[i]) > 0
            // either i+1 has been found, which makes num[i] negative
            // or , num[i] currently is a positive integer, we need to mark num[i] found (make num[num[i]-1] a negative number)
            else {                                      
                if (nums[idx-1] > 0)
                    nums[idx-1] = -nums[idx-1];   // we simply negate the number because the absolute value might be needed.
                else if (nums[idx-1] == 0)
                    nums[idx-1] = -N-1;     // no inf is needed, simply mark it with an out-of-range negative number
            }
        }
        
        // to this point, nums[i] is negative iff i+1 show up
        for (idx = 1; idx <= N; idx++)
            if (nums[idx-1] >= 0)
                return idx;
        return idx;
    }
};


// sol2. by swapping to correct place
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size(), i = 0;
        while (i < N) {
            if (nums[i] <= 0 || nums[i] > N)
                i++;
            else {
                if (nums[nums[i]-1] != nums[i])
                    swap(nums[nums[i]-1], nums[i]);
                else
                    i++;
            }
        }
        for (i = 1; i <= N; i++)
            if (nums[i-1] != i)
                return i;
        return i;
    }
};
