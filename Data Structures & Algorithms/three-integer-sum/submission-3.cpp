class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t n{nums.size()};
        vector<vector<int>> res{};
                    for(int elem: nums) {
                cout<<elem<<" ";
            }
            cout<<'\n';
        for(size_t i{0}; i<n; ++i) {
            int& a{nums[i]};
            if(i>0 && a == nums[i-1]) {
                continue;
            }
            auto l{nums.begin()+i+1};
            auto r{nums.end()-1};

            while(l<r) {
                
                if(!(*l+*r+a)){
                    res.emplace_back(vector<int>({a,*l,*r}));
                    ++l;
                    while(l<r && *l == *(l-1)){
                        ++l;
                    }
                } else if (*l+*r+a > 0) {
                    --r;
                } else {
                    ++l;
                }
            }
            
        }
        return res;
    }
};
