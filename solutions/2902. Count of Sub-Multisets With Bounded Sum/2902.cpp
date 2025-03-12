class Solution {
 public:
  int countSubMultisets(vector<int>& nums, int l, int r) {
    constexpr int kMod = 1'000'000'007;
    // dp[i] := the number of submultisets of `nums` with sum i
    vector<long> dp(r + 1);
    dp[0] = 1;
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num];

    const int zeros = count[0];
    count.erase(0);

    for (const auto& [num, freq] : count) {
      // stride[i] := dp[i] + dp[i - num] + dp[i - 2 * num] + ...
      vector<long> stride = dp;
      for (int i = num; i <= r; ++i)
        stride[i] += stride[i - num];
      for (int i = r; i > 0; --i)
        if (i >= num * (freq + 1))
          // dp[i] + dp[i - num] + dp[i - freq * num]
          dp[i] = (stride[i] - stride[i - num * (freq + 1)]) % kMod;
        else
          dp[i] = stride[i] % kMod;
    }

    long ans = 0;
    for (int i = l; i <= r; ++i)
      ans = (ans + dp[i]) % kMod;
    return ((zeros + 1) * ans) % kMod;
  }
};
