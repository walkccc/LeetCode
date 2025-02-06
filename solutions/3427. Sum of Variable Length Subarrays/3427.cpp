class Solution {
 public:
  int subarraySum(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    vector<int> prefix(n + 1);

    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);

    for (int i = 0; i < n; ++i)
      ans += prefix[i + 1] - prefix[max(0, i - nums[i])];

    return ans;
  }
};
