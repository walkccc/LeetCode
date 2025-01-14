class Solution {
 public:
  int maxFrequencyScore(vector<int>& nums, long long k) {
    int ans = 0;
    long cost = 0;

    ranges::sort(nums);

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      cost += nums[r] - nums[(l + r) / 2];
      while (cost > k)
        cost -= nums[(l + r + 1) / 2] - nums[l++];
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
