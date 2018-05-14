class Solution {
public:
    int prec(char ch) {
        if (ch == '*' || ch == '/')
            return 2;
        return 1;
    }
    int calc(stack<int>& ns, char op) {
        int n2 = ns.top(); 
        ns.pop();
        int n1 = ns.top(); 
        ns.pop();
        switch (op) {
            case '+':
                return n1 + n2;
            case '-':
                return n1 - n2;
            case '*':
                return n1 * n2;
            case '/':
                return n1 / n2;
        }
    }
    bool isOp(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }
    int calculate(string s) {
        int num = 0, i = 0, sign = 1;
        stack<int> ns;
        stack<char> ops;
        while (s[i] != '\0') {
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
                while (s[i+1] != '\0' && isdigit(s[i+1]))
                    num = num * 10 + s[++i] - '0';
                ns.push(sign * num);
                sign = 1;
                num = 0;
            } else if (isOp(s[i])) {
                char op = s[i];
                if (ns.empty() && op == '-') {
                    sign = -1;
                } else {
                    while (!ops.empty() && prec(ops.top()) >= prec(op)) {
                        ns.push(calc(ns, ops.top()));
                        ops.pop();
                    }
                    ops.push(op);
                }
            }
            i++;
        }
        while (!ops.empty()) {
            ns.push(calc(ns, ops.top()));
            ops.pop();
        }
        return ns.top();
    }
};
