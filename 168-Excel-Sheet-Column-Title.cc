class Solution {
public:
    string convertToTitle(int n) {
        string title = "";
        while (n > 0) {
            int col = (n-1) % 26;
            title.push_back('A' + col);
            n = (n-1) / 26;
        }
        reverse(title.begin(), title.end());
        return title;
    }
};
