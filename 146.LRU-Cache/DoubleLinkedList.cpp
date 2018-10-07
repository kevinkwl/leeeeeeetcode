class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new LNode(0, 0);
        head->prev = head;
        head->next = head;
    }
    
    int get(int key) {
        if (ele.find(key) == ele.end())
            return -1;
        LNode *node = ele[key];
        touch(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (ele.find(key) != ele.end()) {
            ele[key]->val = value;
            touch(ele[key]);
            return;
        }
        if (size == cap) {
            LNode *evict = head->next;
            head->next = evict->next;
            head->next->prev = head;
            ele.erase(evict->key);
            delete(evict);
            size--;
        }
        LNode *node = new LNode(key, value, head->prev, head);
        head->prev->next = node;
        head->prev = node;
        ele[key] = node;
        size++;
    }
private:
    struct LNode {
        int key, val;
        LNode *prev, *next;
        LNode(int k, int v, LNode *p=NULL, LNode *n=NULL): key(k), val(v), prev(p), next(n) {}
    };
    unordered_map<int, LNode*> ele;
    int cur, size, cap;
    LNode *head;
    void touch(LNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head;
        node->prev = head->prev;
        head->prev->next = node;
        head->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
