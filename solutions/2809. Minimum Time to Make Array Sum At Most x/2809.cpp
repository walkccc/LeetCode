class Solution {
 public:
  int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
    const int n = nums1.size();
    const int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    const int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
    // dp[i][j] := the maximum reduced value if we do j operations on the first
    // i numbers
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vector<pair<int, int>> sortedNums;

    for (int i = 0; i < n; ++i)
      sortedNums.emplace_back(nums2[i], nums1[i]);

    ranges::sort(sortedNums);

    for (int i = 1; i <= n; ++i) {
      const auto [num2, num1] = sortedNums[i - 1];
      for (int j = 1; j <= i; ++j)
        dp[i][j] = max(
            // the maximum reduced value if we do j operations on the first
            // i - 1 numbers
            dp[i - 1][j],
            // the maximum reduced value if we do j - 1 operations on the first
            // i - 1 numbers + making the i-th number of `nums1` to 0 at the
            // j-th operation
            dp[i - 1][j - 1] + num2 * j + num1);
    }

    for (int op = 0; op <= n; ++op)
      if (sum1 + sum2 * op - dp[n][op] <= x)
        return op;

    return -1;
  }
};
