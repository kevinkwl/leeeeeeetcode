class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)   return "Zero";
        string n2s[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                       "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", 
                       "Nineteen"};
        string t2s[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string offset[] = {"", " Thousand", " Million", " Billion"};
        string result = "";
        for (int i = 0; i < 4 && num > 0; i++, num /= 1000) {
            int cur = num % 1000;
            string curStr = "";
            int hundred = cur / 100;
            if (hundred)    curStr += n2s[hundred] + " Hundred";
            cur = cur % 100;
            if (cur > 0) {
                if (curStr.size() > 0)
                    curStr += " ";
                if (cur < 20)
                   curStr += n2s[cur];
                else {
                    curStr += t2s[cur/10];
                    cur = cur % 10;
                    if (cur > 0)
                        curStr += " " + n2s[cur];
                }
            }
            if (curStr.size() > 0)
                result = curStr + offset[i] + (result.size() > 0 ? " " : "") + result;
        }
        return result;
    }
};
