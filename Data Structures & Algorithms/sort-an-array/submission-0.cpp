class Solution {
   public:
    // https://visualgo.net/en/sorting?slide=1 for visualizations
    // https://www.programiz.com/dsa/sorting-algorithm for reference
    vector<int> bubbleSort(vector<int>& nums) {
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
                break;  // if the array is sorted early, break
            }
        }
        return nums;
    }
    vector<int> insertionSort(vector<int>& nums) {
        // As the name implies, insertion sort just takes each element and then 'inserts' it in the
        // correct position in a sorted array.
        //  For this, we can use 2 arrays, or we can use the source array itself.
        // In the latter case, we 'insert' the element from the left side of the array making the
        // left side sorted and we bring 1 element from the right at each iteration.

        for(size_t i{1}; i<nums.size(); ++i) {
            int cur{nums[i]};
            int j{static_cast<int>(i-1)};
            for(; j>=0 && nums[j]>cur; --j){
                nums[j+1]=nums[j];
            }
            
            nums[j+1]=cur;

        }
        return nums;
    }
    vector<int> selectionSort(vector<int>& nums) {}
    vector<int> quickSort(vector<int>& nums) {}
    vector<int> radixSort(vector<int>& nums) {}
    vector<int> heapSort(vector<int>& nums) {}
    vector<int> mergeSort(vector<int>& nums) {}
    vector<int> bucketSort(vector<int>& nums) {}
    vector<int> shellSort(vector<int>& nums) {}
    vector<int> countingSort(vector<int>& nums) {}
    vector<int> sortArray(vector<int>& nums) {
        // return bubbleSort(nums);
        return insertionSort(nums);
    }
};