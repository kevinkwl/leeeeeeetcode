class Solution {
public:
    string getStr(int num) {
        static string n2s[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        static string nten2s[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                                 "Nineteen"};
        static string nt2s[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res;
        if (num >= 100)
            res += n2s[num/100] + " Hundred ";
        num = num % 100;
        if (num >= 10) {
            if (num < 20) {
                res += nten2s[num%10] + " ";
                num = 0;
            } else {
                res += nt2s[num/10] + " ";
            }
        }
        num = num % 10;
        if (num > 0)
            res += n2s[num] + " ";
        if (res.back() == ' ')
            res.pop_back();
        return res;
    }
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string base[] = {"", "Thousand", "Million", "Billion"};
        string res;
        int i = 0;
        while (num > 0) {
            if (num % 1000 > 0) {
                string space1 = base[i].empty() ? "" : " ";
                string space2 = (base[i].empty() || res.empty()) ? "" : " ";
                string cur = getStr(num % 1000);
                res = getStr(num % 1000) + space1 + base[i] + space2 + res;
            }
            num /= 1000;
            i++;
        }
        return res;
    }
};
