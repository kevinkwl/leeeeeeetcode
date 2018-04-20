class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        string digits(++S.begin(), --S.end());
        vector<string> res;
        
        for (int i = 1; i < digits.size(); i++) {
            string left = digits.substr(0, i);
            string right = digits.substr(i);
            if (!isValid(left) || !isValid(right))
                continue;
            vector<string> ls;
            vector<string> rs;
            genValid(left, ls);
            genValid(right, rs);

            for (string &sl : ls)
                for (string &sr : rs)
                    res.push_back('(' + sl + ", " + sr + ')');
        }
        return res;
    }
    
    bool isValid(string &s, bool checkLeadZero=false, bool checkEndZero=false) {
        if (s.size() > 1 && stoi(s) == 0)
            return false;
        if (checkLeadZero)
            if (s.size() > 1 && s[0] == '0')
                return false;
        if (checkEndZero)
            if (s.size() > 1 && s.back() == '0')
                return false;
        return true;
    }
    
    void genValid(string& s, vector<string>& vs) {
        for (int i = 1; i < s.size(); i++) {
            string intPart = s.substr(0, i);
            string decPart = s.substr(i);
            if (!isValid(intPart, true) || !isValid(decPart, false, true) || (decPart.size() == 1 && decPart[0] == '0'))
                continue;
            vs.push_back(intPart + '.' + decPart);
        }
        if (isValid(s, true))
            vs.push_back(s);
    }
};
