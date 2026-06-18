class Node {
public:
    int key;    
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;
    int sz;

    void insert_entry_at_front(Node* entry) {
        entry->next = head->next;
        head->next->prev = entry;
        entry->prev = head;
        head->next = entry;
    }

    void delete_entry(Node* lru) {
        lru->next->prev = lru->prev;
        lru->prev->next = lru->next;

        lru->next = nullptr;
        lru->prev = nullptr;
        delete lru;
    }

public:
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        sz = 0;

        head->next = tail;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* old_mru_entry = mpp[key];
        int val = old_mru_entry->val;
        delete_entry(old_mru_entry);
        mpp.erase(key);

        Node* mru_entry = new Node(key, val);
        insert_entry_at_front(mru_entry);
        mpp[key] = mru_entry;

        return mru_entry->val;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            delete_entry(mpp[key]);
            mpp.erase(key);
            sz--;
        }

        if (sz == capacity) {
            Node* victim = tail->prev;
            mpp.erase(victim->key);
            delete_entry(victim);
            sz--;
        }
        
        Node* entry = new Node(key, value);
        insert_entry_at_front(entry);
        mpp[key] = entry;
        sz++;
    }
};

