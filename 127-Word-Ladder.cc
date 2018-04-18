class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> tried;
        int step = 0;
        queue<string> ladder;
        ladder.push(beginWord);
        while (!ladder.empty()) {
            step++;
            int size = ladder.size();
            for (int k = 0; k < size; k++) {
                string cur = ladder.front();
                ladder.pop();
                if (cur == endWord)
                    return step;
                tried.insert(cur);
                for (int i = 0; i < cur.size(); i++) {
                    char ch = cur[i];
                    for (int j = 0; j < 26; j++) {
                        cur[i] = 'a' + j;
                        if (tried.count(cur) == 0 && dict.count(cur) > 0) {
                            ladder.push(cur);
                            tried.insert(cur);
                        }
                    }
                    cur[i] = ch;
                }
            }
        }
        return 0;
    }
};
