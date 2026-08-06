#include <unordered_set>
#include <unordered_map>
class Solution {
   public:
    /*  int lengthOfLongestSubstring(string s) {
         // Sliding window, nd keeping track of the current substring (and window) with a
         // set

         unordered_set<char> st{};
         int res{0};
         int l{0}, r{0};
         while (r < s.size()) {
             while (st.find(s[r]) != st.end()) {
                 st.erase(s[l]);
                 ++l;
             }
             // The logic is, we can obviously just erase s[r], but there would only be one
             // of s[r], so we don't need a loop. However, s[r] is in a window, the sequence
             // matters. So if we just remove it, we won't know what elements between l
             // and r are in the window and have to be removed. Like in pwwkew
             // pw is added, then the next w has to be added but this one removed
             // If we just remove s[r] which is the next w, we will get the set as
             // p, but we know in the window, to remove w, p has to be removed too
             // so we use l and remove s[l] which is at p at first, then at w,
             // and then the set is empty and that's what we want.
             // So we start removing s[l], and the logic is that this l is tracking
             // the current window so it will remove all elements from l till the point it
             // removes the element that is repeating, from the left side

             st.insert(s[r]);

             // res = max(res, static_cast<int>(st.size())); //can't use this because the
             // set can contain elements that are not in sequence, as they just didn't
             // appear
             // twice to cancel out like in pwwkew, the set at the end is wekp, and size 4
             // but p is at the beginning and there's no sequence with ekwp without repeats
             // in the middle
             // Instead, look at the fact that l and r are being updated to keep the
             // current substring size in the window, use that

             res = max(res, r - l + 1);

             ++r;
         }
         return res;
     } */
    int lengthOfLongestSubstring(string s) {
        // Sliding window, but with a map which keeps the key and the index,
        // Removal doesn't need the map to be modified, we simply jump l to the next valid
        // index. This is more optimal than the previous approach
        unordered_map<char,int> mp{};
        int l{0}, r{0};
        int res{0};
        while(r<s.size()) {
            if(mp.find(s[r])!=mp.end()) {
                //l=mp[s[r]]+1; //We don't do this because t can make l move backwards
                //That is, say we have abba, whilst it works well till we get to abb, at 
                //last a, l is at 2 (as we moved it past first b's index), but at 
                //duplicate a it becomes 1 as a was at index 0, now it has shifted from
                //2 to 1 and window size is 3. Which is a bug. And we have moved behind
                //our window with l. So to fix this we take the max value of l between
                //what it is currently and what it will be after moving
                //This way, the bigger of the 2 values go in l and it doesn't move 
                //backwards, conceptually we just remove the element from left from the
                //cache(set/map etc.) but we don't update the l
                l=max(mp[s[r]]+1,l);
            }
            mp[s[r]]=r;
            res=max(res,r-l+1);
            ++r;
        }
        return res;
    }
};
