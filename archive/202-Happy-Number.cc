class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> occur;
        bool happy = false;
        int cur = n;
        while (cur != 1) {
            if (occur.count(cur) > 0)
                return false;
            occur.insert(cur);
            n = cur;
            int next = 0;
            while (n > 0) {
                int c = n % 10;
                next += c * c;
                n /= 10;
            }
            cur = next;
        }
        return true;
    }
};
