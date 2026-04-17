#include<iterator>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       auto p1{nums.begin()};
       auto p2{nums.begin()+1};
       int k{1};
       size_t n{nums.size()};
       while(p2<nums.end()) {
        if(*p1 == *p2) {
            ++p2;
        } else {
            ++p1;
            *p1=*p2;            
        }
       }
       k=distance(nums.begin(), p1)+1;
       return k; 
    }
};