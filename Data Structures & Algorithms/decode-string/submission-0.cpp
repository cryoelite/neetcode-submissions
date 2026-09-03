#include <stack>
#include <string>
#include <cctype>  //We could check if char is int, alphabetic or '[' or ']'
// normally, by checking within char range. Or we can use c helper functions
// for the same.
class Solution {
   public:
    string decodeString(string s) {
        stack<char> st{};
        for (const char letter : s) {
            if (isalnum(letter) || letter == '[') {
                st.push(letter);
            } else {  // Meaning the letter is ']'.
                // The real logic for the alg.
                string temp{};

                while (st.top() != '[') {  // if there's a ']', there'll be a '['
                                           // this is given
                    temp.push_back(st.top());
                    st.pop();
                }
                // st.top() is '['
                st.pop();
                // chars are in reverse order, but it's okay
                string count{};
                while (!st.empty() && isdigit(st.top())) {
                    count.push_back(st.top());
                    st.pop();
                }
                // all digits out
                reverse(count.begin(), count.end());
                int icount{stoi(count)};
                string res{};
                while (icount > 0) {
                    res.append(temp);
                    --icount;
                }
                // res has all the characters
                // Now to append them back to the stack
                while (!res.empty()) {  // since the temp, then res was made
                    // with reversed chars, it works in our favor to pop
                    // them from the string one at a time and add them to
                    // the main stack, without needing 2 reverses

                    st.push(res.back());
                    res.pop_back();
                }
                // done with a 'k[chars]' block.
            }
        }

        string res{};
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};