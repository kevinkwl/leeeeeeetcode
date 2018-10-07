class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<bool>> intlv(s1.size()+1, vector<bool>(s2.size()+1, false));

        intlv[0][0] = true;        
        for (int i1 = 1; i1 <= s1.size(); i1++)
            intlv[i1][0] = (s1.compare(0, i1, s3, 0, i1) == 0 ? true : false);
        for (int i2 = 1; i2 <= s2.size(); i2++)
            intlv[0][i2] = (s2.compare(0, i2, s3, 0, i2) == 0 ? true : false);
        
        for (int i1 = 1; i1 <= s1.size(); i1++)
            for (int i2 = 1; i2 <= s2.size(); i2++) {
                if (s3[i1+i2-1] == s2[i2-1] && intlv[i1][i2-1])
                    intlv[i1][i2] = true;
                else if (s3[i1+i2-1] == s1[i1-1] && intlv[i1-1][i2])
                    intlv[i1][i2] = true;
            }
        return intlv[s1.size()][s2.size()];
    }
};
