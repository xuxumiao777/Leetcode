class MyHashMap {
private:
    struct Node {
        int key;
        int value;
        Node *next;
        Node(int key, int value) : key(key), value(value), next(nullptr) {}
    };

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        bucket.resize(keyRange);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = hash(key);
        if (bucket[index] == nullptr) {
            bucket[index] = new Node(key, value);
            return;
        }
        auto node = bucket[index];
        if (node->key == key) {
            node->value = value;
            return;
        }
        while (node->next) {
            if (node->next->key == key) {
                node->next->value = value;
                return;
            }
            node = node->next;
        }
        node->next = new Node(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = hash(key);
        if (bucket[index] == nullptr) {
            return -1;
        }
        auto node = bucket[index];
        if (node->key == key) {
            return node->value;
        }
        while (node->next) {
            if (node->next->key == key) {
                return node->next->value;
            }
            node = node->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = hash(key);
        if (bucket[index] == nullptr) {
            return;
        }
        auto node = bucket[index];
        if (node->key == key) {
            bucket[index] = node->next;
            delete node;
            return;
        }
        auto next = node->next;
        while (next) {
            if (next->key == key) {
                node->next = next->next;
                delete next;
                return;
            }
            node = next;
            next = next->next;
        }
    }

private:
    int hash(int key) {
        return (key % keyRange);
    }

    int keyRange = 31;
    vector<Node *> bucket;
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */