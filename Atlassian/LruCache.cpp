class LRUCache {

    private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    // Helper function to remove a node from the doubly linked list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Helper function to add a node right after the head (most recently used)
    void add(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Helper function to remove the last node (least recently used)
    Node* removeLast() {
        Node* node = tail->prev;
        remove(node);
        return node;
    }

public:
    LRUCache(int capacity) {
        
       this->capacity = capacity; 
        head = new Node(0, 0); // Dummy head
        tail = new Node(0, 0); // Dummy tail
        head->next = tail;
        tail->prev = head;

    }
    
    int get(int key) {
        
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            add(node);
            return node->value;
        }
        return -1;

    }
    
    void put(int key, int value) {
        
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            remove(node);
            add(node);
        } else {
            if (cache.size() >= capacity) {
                Node* lastNode = removeLast();
                cache.erase(lastNode->key);
                delete lastNode;
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            add(newNode);
        }

    }
};
