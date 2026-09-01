#include <string>
#include <string_view>
#include <ranges>
#include <algorithm>
class Solution {
   public:
    string simplifyPath(string path) {
        using std::operator""sv;
        string_view delim = "/"sv;
        string res{};
        vector<string_view> s{};  // stack-like addition, but vector-like access
        for (const auto word : std::views::split(path, delim)) {
            auto strv{string_view(word)};
            cout << "strv: " << strv << '\n';
            if (strv == "." || strv == "/" || strv == "") {
                continue;
            } else if (strv == "..") {
                if (!s.empty()) {
                    s.pop_back();
                }
            } else {  // meaning we have some word, name etc.
                s.push_back(strv);
            }
        }
        res = "/";
        for (int i{0}; i < s.size(); ++i) {
            res.append(s[i]);
            if (i != s.size() - 1) {  // s.size is guaranteed to be >0
                // because of loop condition
                res.push_back('/');
            }
        }

        return res;
    }
};