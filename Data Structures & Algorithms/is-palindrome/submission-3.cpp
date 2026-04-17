#include <ctype.h>
class Solution {
public:
    bool isPalindrome(string s) {
        auto it{s.begin()};
        auto it_end{s.end()-1};
        while(it< it_end) {
            char a{*it};
            char b{*it_end};
            if(!isalnum(a)) {
                ++it;
                continue;
            }
            if(!isalnum(b)) {
                --it_end;
                continue;
            }
            a = tolower(a);
            b = tolower(b);
            if(a!=b){
                return false;
            }
            ++it;
            --it_end;
        }
        return true;
    }
};
