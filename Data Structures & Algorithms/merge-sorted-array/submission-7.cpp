class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto end1{nums1.begin() + m - 1};  // m elements are valid, hence non-zero, hence the
                                           // elements of nums1 end at m+begin()
        if (nums2.size() ==
            0) {  // m+n will be >=1, and m has to have the element of n, so m can't be smaller than
                  // n and hence m>=n, and hence if there is 1 element, it will be in m.
            return;
        }
        auto end2{nums2.end() - 1};

        auto r{nums1.end() - 1};  // The last element of nums1
        while (end1 >= nums1.begin() && end2 >= nums2.begin()) {
            if (*end1 > *end2) {
                *r = *end1;
                --end1;
            } else {
                *r = *end2;
                --end2;
            }
            --r;
        }

        while(end2>=nums2.begin()) { 
            *r=*end2;
            --end2;
            --r;
        }

        return;
    }
};