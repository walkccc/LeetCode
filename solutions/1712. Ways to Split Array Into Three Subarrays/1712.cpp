class Solution {
 public:
  int waysToSplit(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    int ans = 0;
    vector<int> prefix(n);

    partial_sum(nums.begin(), nums.end(), prefix.begin());

    // Finds the first index j s.t.
    // mid = prefix[j] - prefix[i] >= left = prefix[i].
    auto firstGreaterEqual = [&](int i) {
      int l = i + 1;
      int r = n - 1;
      while (l < r) {
        const int m = (l + r) / 2;
        if (prefix[m] - prefix[i] >= prefix[i])
          r = m;
        else
          l = m + 1;
      }
      return l;
    };

    // Finds the first index k s.t.
    // mid = prefix[k] - prefix[i] > right = prefix[-1] - prefix[k].
    auto firstGreater = [&](int i) {
      int l = i + 1;
      int r = n - 1;
      while (l < r) {
        const int m = (l + r) / 2;
        if (prefix[m] - prefix[i] > prefix.back() - prefix[m])
          r = m;
        else
          l = m + 1;
      }
      return l;
    };

    for (int i = 0; i < n - 2; ++i) {
      const int j = firstGreaterEqual(i);
      if (j == n - 1)
        break;
      const int mid = prefix[j] - prefix[i];
      const int right = prefix.back() - prefix[j];
      if (mid > right)
        continue;
      const int k = firstGreater(i);
      ans = (ans + k - j) % kMod;
    }

    return ans;
  }
};
