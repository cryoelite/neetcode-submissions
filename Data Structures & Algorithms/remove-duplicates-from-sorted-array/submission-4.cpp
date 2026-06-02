class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        // The logic is basically just that when we say we want a de-duplicated array
        // we are seeing that first we have a unique element, then the next position is the next
        // unique element and so on for k positions. What this tells us is that if we simply make
        // sure that the next position is different from the current and current starts from the
        // start of the array, then we have a unique array. We use sim to get the next unique
        // element, cur for the positions from the start and just see if sim is same as cur, if yes
        // then we just bump sim. And when we do come across a unique elem, we just replace cur+1
        // with it and move cur ahead. And just like this we have cur and cur+1 keeping unique
        // elements and sim scanning the array. Loop ends when sim reaches the end. And k tracks the
        // no. of unique elements we got. We cover all the unique elements with this approach. You
        // can think why and reinforce the solution in head.
        auto cur{nums.begin()};
        auto sim{nums.begin() + 1};  // similarityPointer
        int k{1};
        while (sim < nums.end()) {
            if (*sim != *cur) {
                *(cur + 1) = *sim;
                ++cur;
                ++k;
            }
            ++sim;
        }

        return k;
    }
};