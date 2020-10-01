class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, k);
  }

 private:
  int quickSelect(vector<int>& nums, int left, int right, int k) {
    const int randIndex = rand() % (right - left + 1) + left;
    swap(nums[right], nums[randIndex]);

    int l = left;  // next swapped index

    for (int i = left; i < right; ++i)
      if (nums[i] >= nums[right])  // nums[right] := the pivot
        swap(nums[l++], nums[i]);
    swap(nums[l], nums[right]);

    const int count = l - left + 1;  // # of nums >= pivot
    if (count == k) return nums[l];
    if (count > k) return quickSelect(nums, left, l - 1, k);
    return quickSelect(nums, l + 1, right, k - count);
  }
};