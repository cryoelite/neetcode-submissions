class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        size_t n1s{nums1.size()};
        size_t n2s{nums2.size()};
        auto pm{nums1.begin()+m-1};
        if(n2s==0){
            return;
        }
        auto pn{nums2.end()-1};
        auto pmn{nums1.end()-1};
        while (pn >= nums2.begin() && pm >= nums1.begin()) {
            if(*pn > *pm) {
                *pmn=*pn;
                --pmn;
                --pn;
            }
            else {
                *pmn=*pm;
                --pmn;
                --pm;
            }
            
        }
        while (pn >= nums2.begin()) {
            
            *pmn=*pn;
            --pmn;
            --pn;
        }
        
    }
};