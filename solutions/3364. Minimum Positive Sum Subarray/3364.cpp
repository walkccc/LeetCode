class Solution {
 public:
  int minimumSumSubarray(vector<int>& nums, int l, int r) {
    int ans = INT_MAX;

    for (int windowSize = l; windowSize <= r; ++windowSize) {
      int sum = accumulate(nums.begin(), nums.begin() + windowSize, 0);
      if (sum > 0)
        ans = min(ans, sum);
      for (int i = windowSize; i < nums.size(); ++i) {
        sum -= nums[i - windowSize];
        sum += nums[i];
        if (sum > 0)
          ans = min(ans, sum);
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
