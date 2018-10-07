class Solution {
public:
    void reverseWords(string &s) {
        int next = 0, cur = 0, len = 0, start = 0;
        int N = s.size();
        while (cur != N) {
            while (cur != N && s[cur] == ' ')
                cur++;
            if (cur == N)
                break;
            if (next != 0)
                s[next++] = ' ';
            start = cur;
            len = 0;
            while (cur != N && s[cur] != ' ') {
                cur++;
                len++;
            }
            for (int i = 0; i < len; i++)
                s[next+i] = s[start+i];
            for (int i = 0; i * 2 < len; i++)
                swap(s[next+i], s[next+len-1-i]);
            next = next + len;
        }
        for (int i = 0; i * 2 < next; i++)
            swap(s[i], s[next-1-i]);
        s.resize(next);
    }
};
