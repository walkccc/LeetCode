class Solution {
 public:
  long long numberOfSubsequences(vector<int>& nums) {
    const int n = nums.size();
    const int mx = ranges::max(nums);
    long ans = 0;
    vector<vector<int>> count(mx + 1, vector<int>(mx + 1));

    // nums[p] * nums[r] == nums[q] * nums[s]
    // nums[p] / nums[q] == nums[s] / nums[r]
    for (int r = 4; r <= n - 1 - 2; ++r) {
      const int q = r - 2;
      for (int p = 0; p <= q - 2; ++p) {
        const int g = gcd(nums[p], nums[q]);
        ++count[nums[p] / g][nums[q] / g];
      }
      for (int s = r + 2; s < n; ++s) {
        const int g = gcd(nums[s], nums[r]);
        ans += count[nums[s] / g][nums[r] / g];
      }
    }

    return ans;
  }
};
