class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int c = 0;
        int ia = a.size() - 1, ib = b.size() - 1;
        while (c > 0 || ia >= 0 || ib >= 0) {
            c += (ia >= 0 ? a[ia--] - '0' : 0);
            c += (ib >= 0 ? b[ib--] - '0' : 0);
            s += '0' + (c % 2);
            c /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

/**
 *  c
 */

char* addBinary(char* a, char* b) {
    int la = strlen(a), lb = strlen(b);
    char *num1 = a, *num2 = b;
    int len1 = la, len2 = lb;
    if (la < lb) {
        num1 = b, num2 = a;
        len1 = lb, len2 = la;
    }
    if (len2 == 0)
        return num1;
    int carry = 0, i1, i2;
    for (i2 = len2 - 1, i1 = len1 - 1; i2 >= 0; i2--, i1--) {
        num1[i1] += num2[i2] - '0' + carry;
        carry = 0;
        if (num1[i1] > '1') {
            num1[i1] -= 2;
            carry = 1;
        }
    }
    for (; i1 >= 0 && carry != 0; i1--) {
        num1[i1] += carry;
        carry = 0;
        if (num1[i1] > '1') {
            num1[i1] -= 2;
            carry = 1;
        }
    }
    if (carry == 0)
        return num1;
    char *ans = (char *)malloc(sizeof(char) * (len1 + 2));
    ans[len1 + 1] = '\0';
    ans[0] = '1';
    memcpy(&ans[1], num1, len1);
    return ans;
}
/*
*/
