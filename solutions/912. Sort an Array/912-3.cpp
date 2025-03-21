class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }

 private:
  void quickSort(vector<int>& nums, int l, int r) {
    if (l >= r)
      return;

    const int m = partition(nums, l, r);
    quickSort(nums, l, m - 1);
    quickSort(nums, m + 1, r);
  }

  int partition(vector<int>& nums, int l, int r) {
    const int randIndex = rand() % (r - l + 1) + l;
    swap(nums[randIndex], nums[r]);
    const int pivot = nums[r];
    int nextSwapped = l;
    for (int i = l; i < r; ++i)
      if (nums[i] <= pivot)
        swap(nums[nextSwapped++], nums[i]);
    swap(nums[nextSwapped], nums[r]);
    return nextSwapped;
  }
};
