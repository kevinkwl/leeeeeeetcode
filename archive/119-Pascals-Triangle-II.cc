class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> num(rowIndex+1, 1);
        for (int i = 1; i < rowIndex; i++)
            for (int j = i; j > 0; j--)
                num[j] = num[j] + num[j-1];
        return num;
    }
};
