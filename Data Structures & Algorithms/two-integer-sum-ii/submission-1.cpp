class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto p1{numbers.begin()};
        auto p2{numbers.end()-1};
        vector<int> res(2,0);

        while(p1<p2)
        {
            int sum{*p1+*p2};
            if(sum == target) {
                res[0]=distance(numbers.begin(),p1)+1;
                res[1]=distance(numbers.begin(),p2)+1;
                break;
            } else if(sum< target){
                ++p1;
            } else { //sum>target
                --p2;
            }
        }
        return res;
    }
};
