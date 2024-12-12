class Solution {
 public:
  vector<int> applyOperations(vector<int>& nums) {
    for (int i = 0, j = 0; i < nums.size(); ++i) {
      if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        nums[i] *= 2;
        nums[i + 1] = 0;
      }
      if (nums[i] > 0)
        swap(nums[i], nums[j++]);
    }
    return nums;
  }
};
