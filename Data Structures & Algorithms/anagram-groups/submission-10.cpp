class Solution {
    static constexpr int N{26};
    array<int,N> f{};

    string get_unique_key(string elem) {
        fill(f.begin(),f.end(),0);
        for(char c:elem) {
            ++f[static_cast<int>(c)%N];
        }

        string res{};
        for(size_t i{0}; i<N;++i){
            res+=to_string(i)+":"+to_string(f[i])+";";
        }
        return res;
    }
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res{};
        unordered_map<string,size_t> temp{}; //the int/size_t is the index in res
        for(string& s: strs){
            string key{get_unique_key(s)};
            auto val{temp.find(key)};
            if(val!=temp.end()){
                size_t index{val->second};
                res[index].emplace_back(s);
            } else{
                size_t index{res.size()};
                temp.insert({key,index});
                res.emplace_back(vector<string>({s}));
            }
        }

        return res;
    }
};
