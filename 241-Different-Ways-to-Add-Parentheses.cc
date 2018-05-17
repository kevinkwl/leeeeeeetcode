class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        calc(stack<int>(), stack<char>(), input, 0, ans);
        return ans;
    }
    
    void calc(stack<int> nums, stack<char> ops, string& input, int pos, vector<int>& ans) {
        if (pos == input.size())
            return;
        
        // find a number
        while (!isdigit(input[pos]))
            pos++;
        int cur = 0;
        while (isdigit(input[pos])) {
            cur = cur * 10 + input[pos] - '0';
            pos++;
        }

        nums.push(cur);
        char op = 0;
        
        // 1. does not add parentheses immediately after current number
        // still nums & ops remaining in the string
        if (pos < input.size() - 1) {
            op = input[input.find_first_of("+-*", pos)];
            ops.push(op);
            calc(nums, ops, input, pos+1, ans);
            ops.pop();
        }
        
        // 2. add parentheses immediately after current number
        while (!ops.empty()) {
            int n2 = nums.top();
            nums.pop();
            int n1 = nums.top();
            nums.pop();
            char cop = ops.top();
            ops.pop();
            int res;
            if (cop == '+') res = n1 + n2;
            else if (cop == '-') res = n1 - n2;
            else res = n1 * n2;

            nums.push(res);
            if (op != 0) {
                ops.push(op);
                calc(nums, ops, input, pos+1, ans);
                ops.pop();
            }
        }
        // this is the last number
        if (op == 0)
            ans.push_back(nums.top());

    }
};


/*
In each recursive step, we got a stack for numbers and a stack for operators.
We try to find a new number cur in string and an operator op.
number stack:
x, y, z, cur <--- stack top
each of x, y, z are primitive numbers in the string or calculated value (inside parentheses)
There are two ways to go next.

cur will not be calculated with numbers previous to it (if cur is not the last number)
do calculations with cur, after each calculation, we issue a deeper recursive call
1. x, y, (z cur)
2. x, (y (z cur))
3. (x (y (z cur))
*/
