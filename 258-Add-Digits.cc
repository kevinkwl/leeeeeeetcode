// iterative way
class Solution {
public:
    int addDigits(int num) {
        int next = 0;
        while (num >= 10) {
            next = 0;
            while (num > 0) {
                next += num % 10;
                num /= 10;
            }
            num = next;
        }
        return num;
    }
};

// O(1)
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};
