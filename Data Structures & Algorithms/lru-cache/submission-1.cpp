#include <unordered_map>
#include <iostream>

struct DataNode {
    DataNode* next;
    DataNode* prev;
    int key;
    int val;

    DataNode() : next(nullptr), prev(nullptr), key(0), val(0) {}

    DataNode(int key, int val) : next(nullptr), prev(nullptr), key(key), val(val) {}
};

using DN = DataNode;
using UM = std::unordered_map<int, DN*>;

class LRUCache {
    DN left;
    DN right;
    int capacity;
    int count;
    UM hmap;
    /// Promote to MRU value
    void promote(DN* node) {
        // basically put this at the right end

        // if it's already at the right do nothing, optimization
        if (right.prev->key == node->key) {
            return;
        }

        // pop the element out
        DN* node_next{node->next};
        DN* node_prev{node->prev};
        node_prev->next = node_next;
        node_next->prev = node_prev;

        // and then insert it at the right end
        DN* prev{right.prev};
        right.prev = node;
        node->next = &right;
        node->prev = prev;
        prev->next = node;
    }

    void check_and_evict() {
        if (capacity == count) {
            DN* next{left.next};
            left.next = next->next;
            left.next->prev = &left;
            hmap.erase(next->key);
            delete next;
            --count;
        }
    }

   public:
    LRUCache(int capacity) : capacity(capacity), count(0), left(DN()), right(DN()), hmap(UM()) {
        left.next = &right;
        right.prev = &left;
    }

    int get(int key) {
        if (count == 0) {
            return -1;
        } else {
            auto f{hmap.find(key)};
            if (f == hmap.end()) {
                return -1;
            }
            DN* node{f->second};
            promote(node);  // promoting node to MRU element

            return node->val;
        }
    }

    void put(int key, int value) {
        auto f{hmap.find(key)};
        if (f != hmap.end()) {
            f->second->val = value;
            promote(f->second);
            return;
        }

        check_and_evict();  // handles deletion and subtracting count if needed

        DN* node{new DN(key, value)};  // also becomes the MRU element

        DN* prev{right.prev};
        right.prev = node;
        node->next = &right;
        node->prev = prev;
        prev->next = node;
        hmap[key] = node;

        ++count;
    }
};