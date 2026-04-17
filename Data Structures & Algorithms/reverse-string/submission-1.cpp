class Solution {
public:
    void reverseString(vector<char>& s) {
        auto it{s.begin()};
        auto it_end{s.end()-1}; //Check in question if s is atleast size 1, otherwise this would be an invalid address.
        while(it < it_end) {
            iter_swap(it,it_end);
            ++it;
            --it_end;
        }
    }
};