class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& nums) {
    ranges::sort(nums);
    for (int i = 1; i < nums.size(); i += 2)
      swap(nums[i], nums[i - 1]);
    return nums;
  }
};
