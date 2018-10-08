class Solution {
public:
    bool isValid(string s) {
        stack<char> ps;
        for (char c: s) {
            if (c == '[' || c == '(' || c == '{')
                ps.push(c);
            else {
                if (ps.empty())
                    return false;
                if (c == ']' && ps.top() != '[')
                    return false;
                if (c == ')' && ps.top() != '(')
                    return false;
                if (c == '}' && ps.top() != '{')
                    return false;
                ps.pop();
            }
        }
        return ps.empty();
    }
};
