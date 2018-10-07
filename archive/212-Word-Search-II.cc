class Solution {
public:
    struct TNode {
        string word;
        bool isWord;
        TNode* next[26];
        TNode(bool w=false) 
        : isWord(w) {
            fill_n(next, 26, nullptr);
        }
    };
    
    TNode* root;
    
    void insert(string& word) {
        TNode* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (cur->next[idx] == NULL)
                cur->next[idx] = new TNode;
            cur = cur->next[idx];
        }
        cur->isWord = true;
        cur->word = word;
    }
    
    void dfs(int r, int c, TNode* node, vector<string>& res, vector<vector<char>>& bd) {
        char ch = bd[r][c];
        if (ch == '#')
            return;
        if (node->next[ch-'a'] == nullptr)
            return;
        TNode* next = node->next[ch-'a'];
        if (next->isWord) {
            res.push_back(next->word);
            next->isWord = false;
        }
        bd[r][c] = '#'; // mark visited
        if (r > 0)
            dfs(r-1, c, next, res, bd);
        if (r < bd.size() - 1)
            dfs(r+1, c, next, res, bd);
        if (c > 0)
            dfs(r, c-1, next, res, bd);
        if (c < bd[r].size() - 1)
            dfs(r, c+1, next, res, bd);
        bd[r][c] = ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.size() == 0 || board[0].size() == 0) 
            return vector<string>{};
        vector<string> res;
        root = new TNode;
        for (string& w : words)
            insert(w);
        
        int R = board.size(), C = board[0].size();
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                dfs(r, c, root, res, board);
            }
        return res;
    }
};
