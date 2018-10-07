class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TNode;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        insert_trie(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_trie(word, 0, root);
    }
private:
    struct TNode {
        vector<TNode*> ch;
        bool isWord;
        TNode(bool isW=false)
            : ch(vector<TNode*>(26, NULL)), isWord(isW) {}
    };
    
    TNode* root;
    /** Inserts a word into the trie. */
    void insert_trie(string word) {
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
    bool search_trie(string& word, int pos, TNode* node) {
        if (word.size() == pos)   return node->isWord;
        char c = word[pos];
        if (c != '.') {
            if (node->ch[c-'a'] == NULL)
                return false;
            else
                return search_trie(word, pos+1, node->ch[c-'a']);
        } else {
            bool found = false;
            for (TNode* next : node->ch) {
                if (next != NULL && search_trie(word, pos+1, next)) {
                    found = true;
                    break;
                }                    
            }
            return found;
        }
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
