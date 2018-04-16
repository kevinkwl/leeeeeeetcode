class Solution {
public:
    bool isNumber(string s) {
        bool seenDot = false, seenE = false, seenNumber = false, seenSign = false;
        bool leadingws = true, seenWS = false;
        for (char ch : s) {
            // skip leading whitespaces
            if (ch == ' ' && leadingws)
                continue;
            else
                leadingws = false;
            
            if (ch == ' ') {
                seenWS = true;  // whitespace after a valid num string, 
            } else if (seenWS) { // nothing should appear after whitespace
                return false;
            } else if (ch == '-' || ch == '+') {    // only allowed at beginning
                if (seenNumber || seenSign || (seenDot && !seenE))
                    return false;
                seenSign = true;
            } else if (ch >= '0' && ch <= '9') {
                seenNumber = true;
            } else if (ch == '.') {
                if (seenDot || seenE)
                    return false;
                seenDot = true;
            } else if (ch == 'e') {
                if (seenE || !seenNumber)
                    return false;
                seenE = true;
                seenNumber = false;
                seenSign = false;
            } else {
                return false;
            }
        }
        return seenNumber;
    }

};
