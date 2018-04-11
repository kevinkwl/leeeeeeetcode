// 1. find all valid parenthese pairs with their start-end indices, then try
//    merging and compare.
class Solution {
public:
    int longestValidParentheses(string s) {
        int pairs = 0, max_pairs = 0;
        stack<int> start;
        stack<pair<int, int>> valid;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                start.push(i);
            } else {
                if (!start.empty()) {
                    valid.push(make_pair(start.top(), i + 1));
                    start.pop();
                }
            }
        }
        int b, e, max_len = 0;
        b = e = s.size();
        while (!valid.empty()) {
            pair<int, int> span = valid.top();
            valid.pop();
            // inside current span
            if (span.first >= b && span.second <= e)
                continue;
            // can be concatenated
            else if (span.second == b) {
                b = span.first;
            }
            else {
                max_len = max(e - b, max_len);
                b = span.first;
                e = span.second;
            }
        }
        max_len = max(e - b, max_len);
        return max_len;
    }
};

// s2. find all invalid parenthese, try finding the max gap between them
// (include start and end)
//

// s3. dynamic programming
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> longest(s.size(), 0);
        int max_len = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    longest[i] = (i-2 >= 0 ? longest[i-2] + 2 : 2);
                    max_len = max(max_len, longest[i]);
                }
                else {
                    if (i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '(') {
                        longest[i] = longest[i-1] + 2 + (i-longest[i-1]-2 >= 0 ? longest[i-longest[i-1]-2] : 0);
                        max_len = max(max_len, longest[i]);
                    }
                }
            }
        }
        return max_len;
    }
};
