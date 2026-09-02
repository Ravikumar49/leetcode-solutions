class Node{
public:
    int key,val;
    Node* next;
    Node* prev;
    Node(int key,int val){
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
    int size,capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mp;
public:
    LRUCache(int capacity) {
        size =0;
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    void insertNodeAtEnd(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        if(prevNode != NULL) prevNode->next = nextNode;
        if(nextNode != NULL) nextNode->prev = prevNode;
        Node* tailPrev = tail->prev;
        tailPrev->next = node;
        node->prev = tailPrev;
        node->next = tail;
        tail->prev = node;
    }
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        insertNodeAtEnd(node);
        return node->val;
    }
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->val = value;
            insertNodeAtEnd(node);
        }
        else{
            Node* node = NULL;
            if(size == capacity){
                node = head->next;
                mp.erase(node->key);
                node->key = key;
                node->val = value;
            }
            else{
                size++;
                node = new Node(key,value);
            }
            insertNodeAtEnd(node);
            mp[key] = node;
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */