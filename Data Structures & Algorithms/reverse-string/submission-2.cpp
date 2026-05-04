class Solution {
public:
    void reverseString(vector<char>& s) {
        auto l{s.begin()};
        auto r{s.end()-1};
        while(l<r){
            iter_swap(l,r);
            ++l;
            --r;
        }
        return;
    }
};