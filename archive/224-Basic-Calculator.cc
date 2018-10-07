class Solution {
public:
    int calculate(string s) {
        char ch;
        bool begin = true, calc = false;
        int num = 0, i = 0, sign = 1;
        stack<int> number;
        stack<char> ops;
        while (s[i] != '\0') {
            calc = false;
            while (s[i] == ' ')
                i++;
            if (s[i] == '\0')
                break;
            
            if (isdigit(s[i])) {
                num = s[i] - '0';
                while (s[i+1] != '\0' && isdigit(s[i+1])) {
                    num = num * 10 + s[i+1] - '0';
                    i++;
                }
                number.push(sign * num);
                sign = 1;
                begin = false;
                calc = true;

            } else if (s[i] == '(') {
                begin = true;
                ops.push('(');
            } else if (s[i] == ')') {
                while (ops.top() != '(')
                    ops.pop();
                ops.pop();
                calc = true;
            } else if (s[i] == '+') {
                ops.push('+');
            } else if (s[i] == '-') {
                if (begin)
                    sign = -1;
                else
                    ops.push('-');
            }
            // do calculations
            if (calc)
                while (number.size() > 1 && ops.size() > 0 && (ops.top() == '+' || ops.top() == '-'))  {
                    char op = ops.top();
                    ops.pop();
                    int n2 = number.top();
                    number.pop();
                    int n1 = number.top();
                    number.pop();
                    number.push((op == '+' ? n1 + n2 : n1 - n2));
                }
            i++;
        }
        return number.top();
    }
};


// cleaner version, using one stack only
class Solution {
public:
    int calculate(string s) {
        int num = 0, i = 0, sign = 1;
        int res = 0;
        stack<int> ns;
        while (s[i] != '\0') {
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
                while (s[i+1] != '\0' && isdigit(s[i+1]))
                    num = num * 10 + s[++i] - '0';
                res += sign * num;
                num = 0;
            } else if (s[i] == '(') {
                ns.push(res);
                ns.push(sign);
                res = 0;
                sign = 1;
            } else if (s[i] == ')') {
                res = res * ns.top();
                ns.pop();
                res += ns.top();
                ns.pop();
            } else if (s[i] == '+' || s[i] == '-') {
                sign = (s[i] == '-' ? -1 : 1);
            }
            i++;
        }
        return res;
    }
};
