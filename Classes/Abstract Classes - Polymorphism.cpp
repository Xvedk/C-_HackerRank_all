ostream &operator<<(ostream &o, const Node *n) {
    return o << '<' << n->key << ", " << n->value << '>';
        //<< ", me: " << (void *)n;
        //<< ", prev: " << n->prev << ", next: " << n->next;
}

// This is the double-linked list internally used by the LRUCache
class LRUCacheList {
    Node *head;
    Node *tail;
    int   size;
public:
    LRUCacheList() : head(NULL), tail(NULL), size(0) {}
    Node *getHead() const { return head; }
    Node *getTail() const { return tail; }
    int   getSize() const { return size; }
    bool  empty()   const { return head != NULL; }

    ~LRUCacheList() {
        //cout << "called destructor ~LRUCacheList()\n";
        Node *n = head, *np;
        while (n) {
            np = n->next;
            //cout << "freeing " << (void *)n << endl;
            delete n;
            n = np;
        }
        head = tail = NULL;
        size = 0;
    }

    /** Removes the last (tail) element of the cache-list */
    void removeTail() {
        if (tail != NULL) {
            if (tail->prev != NULL) tail->prev->next = NULL;
            Node *new_tail = tail->prev;

            if (head == tail) { head = NULL; }
            delete tail;
            tail = new_tail;
        }
        if (size > 0) --size;
    }
    /** Inserts a new element at the head of the cache-list */
    Node* insertFront(int key, int value) {
        /** Create a node (that will be the new head) with;
         *  - prev: NULL
         *  - next: former head
         */
        Node *new_head = new Node(NULL, head, key, value);
        // attach it as the head the list
        if (head != NULL) {
            head->prev = new_head;
            head = new_head;
        } else {    // empty list
            head = new_head;
            tail = new_head;
        }
        ++size;
        return head;
    }
    /** Moves a given node to the first position of the list. 
    */
    void promoteFront(Node *n) {
        if (head == n) return;
        
        if (n == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }

        // attach it as the head the list
        if (head != NULL) {
            head->prev = n;
        } else {    // empty list
            tail = n;
        }
        n->prev = NULL;
        n->next = head;
        head = n;
    }
    /** Prints out the content of the list */
    friend ostream &operator<<(ostream &o, const LRUCacheList &l) {
        Node *n = l.getHead();
        while (n) {
            if (n != l.getHead()) { o << ", "; }
            o << n;
            n = n->next;
        }
        o << ", size(" << l.size << ")";
        return o;
    }
};

class LRUCache: public Cache {
protected:
    int size_;
    LRUCacheList l_;
public:
    LRUCache(int capacity) : size_(0) { Cache::cp = capacity; }
    
    /**
     * set() - Set/insert the value of the key, if present, otherwise add the key 
     * as the most recently used key. If the cache has reached its capacity, 
     * it should replace the least recently used key with a new key.
     */
    virtual void set(int key, int val) { 
        // look at the key in the map
        pair<map<int,Node*>::iterator, bool> ret = mp.insert({key, NULL});
        //auto [it, found] = mp.insert({key, NULL});    // c++17
        map<int,Node*>::iterator it = ret.first;
        //cout << (ret.second ? "true: " : "false: ") << "it->first: " << it->first << endl;
        //<< ", " << (it->second ? it->second : "NULL") << endl;
        //exit(0);
        if (ret.second == true) {
            // inserts the new element
            if (l_.getSize() == cp) { 
                mp.erase(l_.getTail()->key);
                l_.removeTail();
            }
            it->second = l_.insertFront(key, val);
        } else {
            // element already existed: 
            //   (1) update value
            //   (2) promote it at the front of the list
            it->second->value = val;    
            l_.promoteFront(it->second);
        }
        // update members that refer to the underlying linked-list
        size_ = l_.getSize();
        head  = l_.getHead();
        tail  = l_.getTail();
#ifdef DEBUG
        cout << "set " << key << ' ' << val << endl;
        cout << "list is:\n  " << l_ << endl;
        cout << "map is:\n";
        for (auto &it: mp) {
            cout << "    " << it.first << ", " << it.second << endl;
        }
#endif
    }

    /**
     * get() - Get the value (will always be positive) of the key if the key exists 
     * in the cache, otherwise return -1.
     */
    virtual int  get(int key) { 
        map<int,Node*>::iterator it = mp.find(key);
        if (it != mp.end()) {
            // THIS SHOULDN'T BE THIS WAY
            // This method IS NOT intended to change the structure
            // BUT, as per the specifications, it must promote the element
            // as the first of the list, if found
            l_.promoteFront(it->second);
            it->second = l_.getHead();

#ifdef DEBUG
            cout << "get " << key << endl;
            cout << "list is:\n  " << l_ << endl;
            cout << "map is:\n";
            for (auto &it: mp) {
                cout << "    " << it.first << ", " << it.second << endl;
            }
#endif            
            return it->second->value;
        } else {
            return -1;
        }
    }
};

void testList() {
    LRUCacheList l;
    l.insertFront(1, 10);
    cout << "l:\n    " << l << endl;
    l.insertFront(2, 11);
    cout << "l:\n    " << l << endl;
    l.insertFront(3, 12);
    cout << "l:\n    " << l << endl;
    cout << "now, remove tail\n";
    l.removeTail();
    cout << "l:\n    " << l << endl;
    l.removeTail();
    cout << "l:\n    " << l << endl;
    l.removeTail();
    cout << "l:\n    " << l << endl;
    l.removeTail();
    cout << "l:\n    " << l << endl;

    l.insertFront(1, 10);
    cout << "l:\n    " << l << endl;
    l.insertFront(2, 11);
    cout << "l:\n    " << l << endl;
    l.insertFront(3, 12);
    cout << "l:\n    " << l << endl;

    cout << "Promote first\n";
    l.promoteFront(l.getHead());
    cout << "l:\n    " << l << endl;
    l.promoteFront(l.getHead()->next);
    cout << "l:\n    " << l << endl;
    l.promoteFront(l.getHead()->next->next);
    cout << "l:\n    " << l << endl;
}
