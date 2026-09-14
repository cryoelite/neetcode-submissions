#include <unordered_map>
#include <vector>
#include <string>
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> tm;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { tm[key].push_back({timestamp, value}); }

    string get(string key, int timestamp) {
        auto f{tm.find(key)};

        if (f == tm.end()) {
            return "";
        }

        int l{0};
        int r = f->second.size() - 1;  // There will at-least be a single value
        // for each key

        if (f->second[0].first > timestamp) {
            return "";

        } else if (f->second[r].first <= timestamp) {
            return f->second[r].second;
        }
        int d{0};
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (f->second[m].first > timestamp) {
                r = m - 1;
                d = m;
            } else {
                l = m + 1;
            }
        }

        return f->second[d - 1].second;
    }
};
