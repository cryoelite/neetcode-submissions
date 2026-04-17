// Problem: https://neetcode.io/problems/single-number

#include <iostream>
#include <vector>
class Alg
{
public:
    int n{};
    std::vector<int> arr{};

    Alg()
    {
        std::cin >> n;
        arr = std::vector<int>(n, 0);

        for (size_t i = 0; i < n; i++)
        {
            std::cin >> arr[i];
        }
    }
    Alg(int n, std::vector<int> &arr) : n(n), arr(std::move(arr)) {}

    int compute()
    {
        int result{0};
        for (size_t i{0}; i < n; ++i)
        {
            result ^= arr[i];
        }
        return result;
    }

    void compute_and_output()
    {
        std::cout << compute();
        std::cout << std::endl;
    }
};

class Solution
{

public:
    int singleNumber(std::vector<int> &nums)
    {
        return Alg(nums.size(), nums).compute();
    }
};

