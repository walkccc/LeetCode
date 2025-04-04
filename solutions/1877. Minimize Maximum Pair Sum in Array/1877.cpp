class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    int ans = 0;

    ranges::sort(nums);

    for (int i = 0, j = nums.size() - 1; i < j;)
      ans = max(ans, nums[i++] + nums[j--]);

    return ans;
  }
};
