class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> idx{1, numbers.size()};
        int p = 0, q = numbers.size() - 1;
        while (p < q) {
            if (numbers[p] + numbers[q] == target)
                break;
            else if (numbers[p] + numbers[q] < target)
                p++;
            else
                q--;
        }
        idx[0] = p + 1;
        idx[1] = q + 1;
        return idx;
    }
};
