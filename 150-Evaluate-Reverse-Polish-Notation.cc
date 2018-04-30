class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> opd;
        for (string & s : tokens) {
            if (s.length() == 1 && !isdigit(s[0])) {
                int opd2 = opd.top();
                opd.pop();
                int opd1 = opd.top();
                opd.pop();
                switch (s[0]) {
                    case '+': opd.push(opd1 + opd2); break;
                    case '-': opd.push(opd1 - opd2); break;
                    case '*': opd.push(opd1 * opd2); break;
                    case '/': opd.push(opd1 / opd2); break;
                }
            }
            else
                opd.push(stoi(s));
        }
        return opd.top();
    }
};
