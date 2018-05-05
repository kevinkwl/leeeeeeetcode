class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        bool sign = ((numerator < 0) != (denominator < 0));
        long n = abs((long)numerator), d = abs((long)denominator);
        long intp = n / d;
        n = (n - intp * d) * 10;
        unordered_map<long, int> seen;
        string decp = "";
        int i = 0; 
        long cur;
        while (n != 0) {
            if (seen.count(n) > 0) {
                int si = seen[n];
                decp = decp.substr(0, si) + "(" + decp.substr(si) + ")";
                break;
            }
            cur = n / d;
            decp.push_back('0' + cur);
            seen[n] = i;
            n -= cur * d;
            n *= 10;
            i++;
        }
        return (sign ? "-" : "") + to_string(intp) + (decp != "" ? "." + decp : "");
    }
};
