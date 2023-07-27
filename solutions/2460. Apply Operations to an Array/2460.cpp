class Solution {
 public:
  vector<int> applyOperations(vector<int>& nums) {
    vector<int> ans(nums.size());

    for (int i = 0; i + 1 < nums.size(); ++i)
      if (nums[i] == nums[i + 1]) {
        nums[i] *= 2;
        nums[i + 1] = 0;
      }

    int i = 0;
    for (const int num : nums)
      if (num > 0)
        ans[i++] = num;

    return ans;
  }
};
