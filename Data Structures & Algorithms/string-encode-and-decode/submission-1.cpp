#include<sstream>
#include<string>
#include<iostream>
using namespace std;

class Solution {
    static constexpr char delim{'#'};

public:
    static string encode(const vector<string> &strs) {
        stringstream ss{};

        for (const string &str: strs) {
            ss << to_string(str.length()) << delim << str;
        }
        return ss.str();
    }

    static vector<string> decode(const string s) {
        vector<string> res{};
        stringstream ss(s);

        for (string len_s{}; getline(ss, len_s, delim);) {
            int len{0};
            len = stoi(len_s);

            string str{};
            for (int i{0}; i < len; ++i) {
                char ch{};
                ss.get(ch);
                str += ch;
            }

            res.emplace_back(str);
        }

        return res;
    }
};