class Solution {
    bool is_palindrome(string::iterator l, string::iterator r) {
        while(l<r) {
            if(*l == *r) {
                ++l;
                --r;
            } else {
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int mods{1};
        auto it{s.begin()};
        auto it_end{s.end()-1};

        while (it < it_end) {
            if(*it == *it_end) {
                ++it;
                --it_end;
            } else {
                if (!is_palindrome(it+1,it_end) && !(is_palindrome(it, it_end-1))) {
                    return false;
                } 
                break;
            }
        }
        return true;
    }
};