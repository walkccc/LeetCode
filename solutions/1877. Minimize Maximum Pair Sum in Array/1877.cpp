class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    int ans = 0;

    sort(nums.begin(), nums.end());

    for (int i = 0, j = nums.size() - 1; i < j;)
      ans = max(ans, nums[i++] + nums[j--]);

    return ans;
  }
};
