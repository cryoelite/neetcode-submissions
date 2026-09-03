#include <unordered_map>
class FreqStack {
    unordered_map<int,int> counts{};
    unordered_map<int,vector<int>> stacks{};
    int maxCount{0};

   public:
    FreqStack() {}

    void push(int val) {
        auto f{counts.find(val)};
        int count{1};
        if (f != counts.end()) {
            count = f->second + 1;
        }
        if(count>maxCount){
            maxCount=count; //Which is just +1
            stacks[maxCount]=vector<int>();
        }
        counts[val]+=1;
        stacks[count].push_back(val);
    }

    int pop() {
        int res{stacks[maxCount].back()};
        stacks[maxCount].pop_back();
        --counts[res];
        if(stacks[maxCount].empty()) {
            --maxCount;
        }

        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */