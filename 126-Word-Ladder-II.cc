class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (dict.count(endWord) == 0)
            return res;
        queue<vector<string>> ladders;
        ladders.push(vector<string>{beginWord});
        bool found = false;
        while (!found && !ladders.empty()) {
            int numOfLadders = ladders.size();
            unordered_set<string> newDict(dict);
            for (int i = 0; i < numOfLadders; i++) {
                vector<string> ladder = ladders.front();
                ladders.pop();
                string last = ladder.back();
                for (int j = 0; j < last.size(); j++) {
                    char tmp = last[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        last[j] = c;
                        if (dict.count(last) > 0) {
                            vector<string> newLadder(ladder.begin(), ladder.end());
                            newLadder.push_back(last);
                            if (last == endWord) {
                                found = true;
                                res.push_back(newLadder);
                                break;
                            }
                            newDict.erase(last);
                            ladders.push(newLadder);
                        }
                    }
                    last[j] = tmp;
                }
            }
            dict = newDict;
        }
        return res;
    }
};
