class Solution {
 public:
  int minOperations(vector<int>& nums) {
    const int n = nums.size();
    const int ones = ranges::count(nums, 1);
    if (ones > 0)
      return n - ones;

    // the minimum operations to make the shortest subarray with a gcd == 1
    int minOps = INT_MAX;

    for (int i = 0; i < n; ++i) {
      int g = nums[i];
      for (int j = i + 1; j < n; ++j) {
        g = __gcd(g, nums[j]);
        if (g == 1) {  // gcd(nums[i..j]) == 1
          minOps = min(minOps, j - i);
          break;
        }
      }
    }

    // After making the shortest subarray with the `minOps`, need additional
    // n - 1 operations to make the other numbers to 1.
    return minOps == INT_MAX ? -1 : minOps + n - 1;
  }
};
