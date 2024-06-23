class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    // 1. If i is even, then nums[i] <= nums[i - 1].
    // 2. If i is odd, then nums[i] >= nums[i - 1].
    for (int i = 1; i < nums.size(); ++i)
      if ((!(i & 1) && nums[i] > nums[i - 1]) ||
          ((i & 1) && nums[i] < nums[i - 1]))
        swap(nums[i], nums[i - 1]);
  }
};
