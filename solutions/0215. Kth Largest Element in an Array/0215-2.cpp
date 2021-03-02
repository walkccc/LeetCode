class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, k);
  }

 private:
  int quickSelect(vector<int>& nums, int l, int r, int k) {
    const int pivot = nums[r];

    int nextSwapped = l;
    for (int i = l; i < r; ++i)
      if (nums[i] >= pivot)
        swap(nums[nextSwapped++], nums[i]);
    swap(nums[nextSwapped], nums[r]);

    const int count = nextSwapped - l + 1;  // # of nums >= pivot
    if (count == k)
      return nums[nextSwapped];
    if (count > k)
      return quickSelect(nums, l, nextSwapped - 1, k);
    return quickSelect(nums, nextSwapped + 1, r, k - count);
  }
};
