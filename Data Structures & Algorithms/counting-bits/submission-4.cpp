class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        
        for(int i{1}, pw{0}; i<=n;++i)
        {
            if(i==static_cast<int>(pow(2,pw+1))) {
                ++pw;
            }
            
            result[i]= 1 + result[i-static_cast<int>(pow(2,pw))];            
        }
        return result;
    }
};
