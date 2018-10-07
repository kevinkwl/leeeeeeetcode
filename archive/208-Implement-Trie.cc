class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->ch[i] == NULL) {
                cur->ch[i] = new TNode;
            }
            cur = cur->ch[i];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->ch[i] == NULL)
                return false;
            cur = cur->ch[i];
        }
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TNode* cur = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (cur->ch[i] == NULL)
                return false;
            cur = cur->ch[i];
        }
        return true;
    }
private:
    struct TNode {
        vector<TNode*> ch;
        bool isWord;
        TNode(bool isW=false)
            : ch(vector<TNode*>(26, NULL)), isWord(isW) {}
    };
    
    TNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
