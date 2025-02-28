class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    heapSort(nums);
    return nums;
  }

 private:
  void heapSort(vector<int>& nums) {
    buildMaxHeap(nums);
    int heapSize = nums.size();
    for (int i = nums.size() - 1; i > 0; --i) {
      swap(nums[i], nums[0]);
      --heapSize;
      maxHeapify(nums, 0, heapSize);
    }
  }

  void buildMaxHeap(vector<int>& nums) {
    for (int i = nums.size() / 2; i >= 0; --i)
      maxHeapify(nums, i, nums.size());
  }

  void maxHeapify(vector<int>& nums, int i, int heapSize) {
    const int l = 2 * i + 1;
    const int r = 2 * i + 2;
    int largest = i;
    if (l < heapSize && nums[largest] < nums[l])
      largest = l;
    if (r < heapSize && nums[largest] < nums[r])
      largest = r;
    if (largest != i) {
      swap(nums[largest], nums[i]);
      maxHeapify(nums, largest, heapSize);
    }
  }
};
