#include <string>
struct AddResult {
    char value;
    char carry;
    AddResult(char value, char carry) : value(value), carry(carry) {}
    AddResult() : value('0'), carry('0') {}
};
class Solution {
   public:
    AddResult add(char a, char b, char carry) {
        int i_a{static_cast<int>(a) - 48};  //'0' is 48 in ASCII so we get a 0 or 1 here
        int i_b{static_cast<int>(b) - 48};
        int i_carry{static_cast<int>(carry) - 48};

        int res{i_a ^ i_b};  // 1^1 = 0, 0^0=0, anything else 1, just like addition
        res^=i_carry; //can do it in one line, but for better understanding multi lines
        int new_carry{(i_a & i_b) | (i_a & carry) | (i_b & carry)};  

        return AddResult(static_cast<char>(res + 48), static_cast<char>(new_carry + 48));
    }
    string addBinary(string a, string b) {
        auto p1{a.end() - 1};
        auto p2{b.end() - 1};
        string res{""};
        res.reserve(max(a.size(), b.size() + 1));
        char carry{'0'};
        while (p1 >= a.begin() || p2 >= b.begin()) {
            char t1{'0'};
            char t2{'0'};
            if (p1 >= a.begin()) {
                t1 = *p1;
                --p1;
            }
            if (p2 >= b.begin()) {
                t2 = *p2;
                --p2;
            }
            cout<<"a: "<<t1<<' '<<"b: "<<t2<<" "<<"carry: "<<carry<<'\n';
            auto add_res{add(t1, t2, carry)};
            
            carry=add_res.carry;
            res.push_back(add_res.value);
            cout<<"result: "<<add_res.value<<" carry: "<<add_res.carry<<" "<<"Main result: "<<res<<'\n';                        
        }
        if(carry!='0') {
            res.push_back(carry);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};