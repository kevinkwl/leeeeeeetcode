// merge the two pass into one pass
// since each time we pop a bar from stack, the reach of that bar is
// [stack.top()+1, i-1]

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> lower;
        heights.push_back(0); // add sentinel node to simplify the code
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!lower.empty() && heights[lower.top()] >= heights[i]) {
                int cur = lower.top();
                lower.pop();
                int left = lower.empty() ? -1 : lower.top();
                int area = heights[cur] * (i - 1 - left);
                if (area > ans)
                    ans = area;
            }
            lower.push(i);
        }
        return ans;
    }
};



// two pass version
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> lower;
        vector<int> maxArea(heights.size(), 0);
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            int reach = i;
            while (!lower.empty() && heights[lower.top()] >= heights[i]) 
                lower.pop();
            // if the stack is empty, we can reach to the beginning
            reach = lower.empty() ? 0 : lower.top() + 1;
            maxArea[i] += heights[i] * (i - reach + 1);
            lower.push(i);
        }
        while (!lower.empty())
            lower.pop();
        // do it again from right to left
        for (int i = heights.size()-1; i >= 0; i--) {
            int reach = i;
            while (!lower.empty() && heights[lower.top()] >= heights[i]) 
                lower.pop();
            reach = lower.empty() ? heights.size() - 1 : lower.top() - 1;
            maxArea[i] += heights[i] * (reach - i + 1) - heights[i]; // minus heights[i] because we add the same rectangle twice
            if (maxArea[i] > ans)
                ans = maxArea[i];
            lower.push(i);
        }
        return ans;
    }
};
