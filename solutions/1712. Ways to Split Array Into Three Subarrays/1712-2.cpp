class Solution {
 public:
  int waysToSplit(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    int ans = 0;
    vector<int> prefix(n);

    partial_sum(begin(nums), end(nums), begin(prefix));

    for (int i = 0, j = 0, k = 0; i < n - 2; ++i) {
      // find the first index j s.t.
      // left = prefix[i] <= mid = prefix[j] - prefix[i]
      j = max(j, i + 1);
      while (j < n - 1 && prefix[i] > prefix[j] - prefix[i])
        ++j;
      // find the first index k s.t.
      // mid = prefix[k] - prefix[i] > right = prefix[-1] - prefix[k]
      k = max(k, j);
      while (k < n - 1 && prefix[k] - prefix[i] <= prefix.back() - prefix[k])
        ++k;
      ans += k - j;
      ans %= kMod;
    }

    return ans;
  }
};
