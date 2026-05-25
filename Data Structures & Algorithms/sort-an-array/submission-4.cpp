#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

class Solution {
public:
    // https://visualgo.net/en/sorting?slide=1 for visualizations
    // https://www.programiz.com/dsa/sorting-algorithm for reference
    vector<int> bubbleSort(vector<int> &nums) {
        // the sort is 'bubbled up', i.e., 2 adjacent elements are compared and swapped if unsorted,
        // and this is done for entire array, and as many times as it takes to sort the whole array,
        // at worst n times. The alg looks like it bubbles the sorts up, like carrying the biggest
        // element to the end at each sort.
        for (int n{static_cast<int>(nums.size() - 1)}, swaps{0}; n >= 0; --n, swaps = 0) {
            for (size_t i{0}; i < nums.size() - 1; ++i) {
                if (nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                    ++swaps;
                }
            }
            if (!swaps) {
                break; // if the array is sorted early, break
            }
        }
        return nums;
    }

    vector<int> insertionSort(vector<int> &nums) {
        // As the name implies, insertion sort just takes each element and then 'inserts' it in the
        // correct position in a sorted array.
        //  For this, we can use 2 arrays, or we can use the source array itself.
        // In the latter case, we 'insert' the element from the left side of the array making the
        // left side sorted and we bring 1 element from the right at each iteration.

        for (size_t i{1}; i < nums.size(); ++i) {
            int cur{nums[i]};
            int j{static_cast<int>(i - 1)};
            for (; j >= 0 && nums[j] > cur; --j) {
                nums[j + 1] = nums[j];
            }

            nums[j + 1] = cur;
        }
        return nums;
    }

    vector<int> selectionSort(vector<int> &nums) {
        // Selection sort is very simple, in that, it selects the min. element from the entire
        // array in each iteration, and then swaps it from an increasing position in the left
        for (size_t i{0}; i < nums.size(); ++i) {
            size_t min_index{
                i
            }; // we initialize the min index with the start elem of each iteration
            for (size_t j{i}; j < nums.size(); ++j) {
                if (nums[j] < nums[min_index]) {
                    min_index = j;
                }
            }
            swap(nums[i], nums[min_index]);
        }
        return nums;
    }

    vector<int> quickSort(vector<int> &nums, int start, int end, int size) {
        if (start < 0 || end >= size || end - start <1) {
            return nums;
        }
        int p1{start};
        int pivot{end};

        while (nums[p1] < nums[pivot] && p1 < pivot) {
            ++p1;
        }
        int p2{p1 + 1};

        while (p2 < pivot) {
            if (nums[p2] < nums[pivot]) {
                swap(nums[p2], nums[p1]);
                ++p1;
                ++p2;
            } else {
                ++p2;
            }
        }
        swap(nums[p1], nums[pivot]);

        quickSort(nums, start, p1 - 1, size);
        quickSort(nums, p1 + 1, end, size);

        return nums;
    }

    vector<int> radixSort(vector<int> &nums) { return nums; }
    vector<int> heapSort(vector<int> &nums) { return nums; }
    vector<int> mergeSort(vector<int> &nums) { return nums; }
    vector<int> bucketSort(vector<int> &nums) { return nums; }
    vector<int> shellSort(vector<int> &nums) { return nums; }

    vector<int> countingSort(vector<int> &nums) {
        // The logic for counting sort is very simple. We simply store the counts of elements in
        // a separate array, where the index represents an element in array, then we simply
        // iterate over the count array and fill the original array back.
        // https://www.interviewcake.com/concept/java/counting-sort
        // Generally only works with +ves, if any elem is -ve I've made it to exit.

        int max_elem{nums[0]}; // calculating the size of the count array
        for (size_t i{0}; i < nums.size(); ++i) {
            max_elem = max(nums[i], max_elem);
        }
        vector count(max_elem + 1, 0);

        for (size_t i{0}; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                cerr << "-ves not supported in this implementation of counting sort \n";
                return nums;
            }
            ++count[nums[i]];
        }

        // now we simply fill the array back
        for (size_t i{0}, j{0}; i < count.size(); ++i) {
            while (count[i] != 0) {
                nums[j] = i;
                ++j;
                --count[i];
            }
        }
        return nums;
    }

    vector<int> sortArray(vector<int> &nums) {
        // return bubbleSort(nums);
        // return insertionSort(nums);
        // return selectionSort(nums);
        // return countingSort(nums);
        const int size{static_cast<int>(nums.size())};
        return quickSort(nums, 0, size - 1, size);
    }
};


