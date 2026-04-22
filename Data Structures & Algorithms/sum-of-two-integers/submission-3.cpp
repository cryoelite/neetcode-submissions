struct AddResult {
    int value;
    int carry;
    AddResult(int value, int carry) : value(value), carry(carry) {}

    AddResult() : value(0), carry(0) {}
};
class Solution {
   public:
    void printBinary(int num) {
        size_t n{(sizeof(num) * 8) - 1};
        for (size_t i{0}; i <= n; ++i) {
            std::cout << ((num >> (n - i)) & 1);
        }
        std::cout << std::endl;
    }
    AddResult add(int a, int b, int carry) {
        int res_value{a ^ b ^ carry};
        int res_carry{(a & b) | (carry & (a ^ b))};

        return AddResult(res_value, res_carry);
    }
    int getSum(int a, int b) {
        size_t n{(sizeof(a) * 8) - 1};
        int carry{0};
        int res{0};
        // printBinary(a);
        // printBinary(b);
        for (size_t i{0}; i <= n; ++i) {
            int bit_a{(a >> i) & 1};
            int bit_b{(b >> i) & 1};
            // cout << "i: " << i << " a: " << bit_a << " b: " << bit_b << " carry: " << carry <<
            // '\n';
            auto add_res{add(bit_a, bit_b, carry)};
            carry = add_res.carry;
            res |= (add_res.value << i);
            // cout << "res: " << add_res.value << " carry: " << add_res.carry << " CulmRes " << res
            //      << '\n';
        }
        //        printBinary(res);
        return res;
    }
};
