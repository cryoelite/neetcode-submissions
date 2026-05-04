class MyHashMap {
    static constexpr int DEFAULT_CAPACITY{100};
    static constexpr double LOAD_FACTOR{0.75};
    static constexpr int CAPACITY_MULTIPLIER{5};
    int capacity;
    int active_keys;
    vector<vector<pair<int, int>>>
        bucket;  // In the pair, the first value is the key and the second is the value
    bool should_rehash() { return (active_keys / capacity) >= LOAD_FACTOR; }

    void rehash() {
        vector<vector<pair<int, int>>> old_bucket(std::move(bucket));
        capacity *= CAPACITY_MULTIPLIER;
        fill(bucket.begin(), bucket.end(), vector<pair<int, int>>());
        bucket.resize(capacity, vector<pair<int, int>>());
        for (auto& sub_bucket : old_bucket) {
            for (auto& elem : sub_bucket) {
                put(elem.first, elem.second);
            }
        }
    }
    size_t get_unique_index(int key) { return static_cast<size_t>(key % capacity); }

    vector<pair<int, int>>::iterator find(int key, size_t unique_index) {
        auto l{bucket[unique_index].begin()};

        while (l != bucket[unique_index].end()) {
            if (l->first == key) {
                break;
            }
            ++l;
        }

        return l;
    }

   public:
    MyHashMap() {
        bucket = vector<vector<pair<int, int>>>(DEFAULT_CAPACITY, vector<pair<int, int>>());
        capacity = DEFAULT_CAPACITY;
        active_keys = 0;
    }

    void put(int key, int value) {
        if (should_rehash()) {
            rehash();
        }
        size_t index{get_unique_index(key)};

        auto find_res{find(key, index)};
        if (find_res != bucket[index].end()) {
            find_res->second=value;
        } else {
            bucket[index].push_back({key,value});
            ++active_keys;
        }
        return;
    }

    int get(int key) {
        size_t index{get_unique_index(key)};
        auto find_res{find(key, index)};
        int res{-1};
        if (find_res != bucket[index].end()) {
            res = find_res->second;
        }

        return res;
    }

    void remove(int key) {
        size_t index{get_unique_index(key)};

        auto find_res{find(key, index)};
        if (find_res != bucket[index].end()) {
            bucket[index].erase(find_res);  // key erased successfully
            --active_keys;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */