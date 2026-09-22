#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
public: 
    int key, value;
    Node *next, *prev;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    Node* head, *tail;
    unordered_map<int,Node*> cache;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node){
        Node* prev = node->prev, *nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
        node->prev = NULL;
        node->next = NULL;
    }

    void insert(Node* node){
        Node* prev = tail->prev, *nxt = tail;
        prev->next = node, node->prev = prev;
        nxt->prev = node, node->next = nxt;
    }
    
    int get(int key) {
        if (!cache.count(key))
        return -1;
        remove(cache[key]);
        insert(cache[key]);
        return cache[key]->value;
    }
    
    void put(int key, int value) {
        if (cache.count(key)){
            remove(cache[key]);
            delete cache[key];
        }
        cache[key] = new Node(key,value);
        insert(cache[key]);
        if(cache.size()>capacity){
            Node* LRU = head->next;
            cache.erase(LRU->key);
            remove(LRU);
            delete LRU;
        }
    }
};

int main() {

    // Test Case 1
    cout << "Test Case 1:" << endl;

    LRUCache cache1(2);

    cache1.put(1, 1);
    cache1.put(2, 2);

    cout << cache1.get(1) << endl;
    // Expected: 1

    cache1.put(3, 3);

    cout << cache1.get(2) << endl;
    // Expected: -1

    cache1.put(4, 4);

    cout << cache1.get(1) << endl;
    // Expected: -1

    cout << cache1.get(3) << endl;
    // Expected: 3

    cout << cache1.get(4) << endl;
    // Expected: 4


    // Test Case 2
    cout << "\nTest Case 2:" << endl;

    LRUCache cache2(2);

    cache2.put(1, 10);
    cache2.put(2, 20);

    cout << cache2.get(1) << endl;
    // Expected: 10

    cache2.put(3, 30);

    cout << cache2.get(2) << endl;
    // Expected: -1

    cout << cache2.get(1) << endl;
    // Expected: 10

    cout << cache2.get(3) << endl;
    // Expected: 30


    // Test Case 3
    cout << "\nTest Case 3:" << endl;

    LRUCache cache3(1);

    cache3.put(1, 100);

    cout << cache3.get(1) << endl;
    // Expected: 100

    cache3.put(2, 200);

    cout << cache3.get(1) << endl;
    // Expected: -1

    cout << cache3.get(2) << endl;
    // Expected: 200


    // Test Case 4
    cout << "\nTest Case 4:" << endl;

    LRUCache cache4(2);

    cache4.put(1, 10);
    cache4.put(2, 20);

    // Access key 1, making key 2 the LRU
    cout << cache4.get(1) << endl;
    // Expected: 10

    cache4.put(3, 30);

    cout << cache4.get(2) << endl;
    // Expected: -1

    cout << cache4.get(1) << endl;
    // Expected: 10

    cout << cache4.get(3) << endl;
    // Expected: 30


    // Test Case 5
    cout << "\nTest Case 5:" << endl;

    LRUCache cache5(2);

    cache5.put(1, 1);
    cache5.put(2, 2);

    // Updating existing key
    cache5.put(1, 100);

    cout << cache5.get(1) << endl;
    // Expected: 100

    cache5.put(3, 3);

    cout << cache5.get(2) << endl;
    // Expected: -1

    cout << cache5.get(1) << endl;
    // Expected: 100

    cout << cache5.get(3) << endl;
    // Expected: 3


    // Test Case 6
    cout << "\nTest Case 6:" << endl;

    LRUCache cache6(3);

    cache6.put(1, 10);
    cache6.put(2, 20);
    cache6.put(3, 30);

    cout << cache6.get(1) << endl;
    // Expected: 10

    cache6.put(4, 40);

    cout << cache6.get(2) << endl;
    // Expected: -1

    cout << cache6.get(3) << endl;
    // Expected: 30

    cout << cache6.get(4) << endl;
    // Expected: 40


    // Test Case 7
    cout << "\nTest Case 7:" << endl;

    LRUCache cache7(2);

    cout << cache7.get(1) << endl;
    // Expected: -1

    cache7.put(1, 1);

    cout << cache7.get(1) << endl;
    // Expected: 1

    cout << cache7.get(2) << endl;
    // Expected: -1

    return 0;
}