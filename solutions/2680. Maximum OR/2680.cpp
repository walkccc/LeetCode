class Solution {
 public:
  long long maximumOr(vector<int>& nums, int k) {
    const int n = nums.size();
    long ans = 0;
    // prefix[i] := nums[0] | nums[1] | ... | nums[i - 1]
    vector<long> prefix(n);
    // suffix[i] := nums[i + 1] | nums[i + 2] | ... nums[n - 1]
    vector<long> suffix(n);

    for (int i = 1; i < n; ++i)
      prefix[i] = prefix[i - 1] | nums[i - 1];

    for (int i = n - 2; i >= 0; --i)
      suffix[i] = suffix[i + 1] | nums[i + 1];

    // For each num, greedily shift it left by k bits.
    for (int i = 0; i < n; ++i)
      ans = max(ans, prefix[i] | static_cast<long>(nums[i]) << k | suffix[i]);

    return ans;
  }
};
