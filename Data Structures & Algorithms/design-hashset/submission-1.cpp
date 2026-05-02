class MyHashSet {
    static constexpr int DEFAULT_CAPACITY{100};
    static constexpr double LOAD_FACTOR{0.75};
    int capacity;
    int active_keys;
    vector<vector<int>> bucket;

    bool should_rehash() {
        return (active_keys / capacity) >=
               LOAD_FACTOR;  // meaning the active keys are either more than a given number or
                             // capacity itself (which will mean active_keys/capacity is >1.0)
    }
    void rehash() {
        size_t cur_size{bucket.size()};
        vector<vector<int>> old_bucket(std::move(bucket));
        capacity = cur_size * 2;
        fill(bucket.begin(), bucket.end(), vector<int>());
        bucket.resize(capacity, vector<int>());
        for (auto& sub_bucket : old_bucket) {
            for (int elem : sub_bucket) {
                add(elem);
            }
        }
    }
    size_t get_internal_index(int key) { return static_cast<size_t>(key % capacity); }

   public:
    MyHashSet() {
        active_keys = 0;
        capacity = DEFAULT_CAPACITY;
        bucket = vector<vector<int>>(capacity, vector<int>());
    }

    void add(int key) {
        if (should_rehash()) {
            rehash();
        }
        size_t index{get_internal_index(key)};
        if (contains(key)) {
            return;  // key already exists, nothing to do
        }

        bucket[index].push_back(key);  // added the key
    }

    void remove(int key) {
        size_t index{get_internal_index(key)};
        // checking if key exists in the sub bucket
        auto it{bucket[index].begin()};
        while (it != bucket[index].end()) {
            if (*it == key) {
                bucket[index].erase(it);
                return;  // successfully removed the key
            }
            ++it;
        }
        // key doesn't exist, nothing to remove
        return;
    }

    bool contains(int key) {
        size_t index{get_internal_index(key)};
        // checking if key exists in the sub bucket
        auto it{bucket[index].begin()};
        while (it != bucket[index].end()) {
            if (*it == key) {
                return true;  // key exists
            }
            ++it;
        }
        // key doesn't exist
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */