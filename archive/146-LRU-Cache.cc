class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = max(capacity, 1);
        this->size = 0;
        this->head = new LRUNode(0, 0);
        this->rear = new LRUNode(0, 0, this->head);
        this->head->next = this->rear;
    }
    
    int get(int key) {
        if (key2node.count(key) == 0)
            return -1;
        LRUNode *node = key2node[key];
        touch(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (key2node.count(key) > 0) {
            LRUNode *node = key2node[key];
            node->val = value;
            touch(node);
        } else {
            if (size < capacity) {
                LRUNode *node = new LRUNode(key, value, rear->prev, rear);
                node->next->prev = node;
                node->prev->next = node;
                key2node[key] = node;
                size++;
            } else {
                LRUNode *victim = head->next;
                key2node.erase(victim->key);
                victim->key = key;
                victim->val = value;
                key2node[key] = victim;
                touch(victim);
            }
        }
    }
    
private:
    struct LRUNode {
        int key, val;
        LRUNode *prev, *next;
        LRUNode(int k, int v, LRUNode *p=nullptr, LRUNode *n=nullptr)
            : key(k), val(v), prev(p), next(n) {}
    };
    
    int capacity, size;
    LRUNode *head, *rear;      // head->LRU -> ... -> MRU -> rear
    unordered_map<int, LRUNode*> key2node;
    
    void touch(LRUNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        node->next = rear;
        node->prev = rear->prev;
        node->prev->next = node;
        node->next->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
