class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (data.empty()) {
            data.push(x);
            data.push(x);
            minVal = x;
        } else {
            if (x <= minVal) {
                data.push(minVal);
                data.push(x);
                minVal = x;
            } else {
                data.push(x);
            }
        }
    }
    
    void pop() {
        if (data.empty())
            return;
        int top = data.top();
        data.pop();
        if (top == minVal) {
            minVal = data.top();
            data.pop();
        }
    }
    
    int top() {
        if (data.empty())
            return 0;
        return data.top();
    }
    
    int getMin() {
        return minVal;
    }
private:
    stack<int> data;
    int minVal;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
