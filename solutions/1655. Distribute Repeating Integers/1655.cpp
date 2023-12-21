class Solution {
 public:
  bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    // validDistribution[i][j] := true if it's possible to distribute the i-th
    // freq into a subset of quantity represented by the bitmask j
    const vector<int> freqs = getFreqs(nums);
    const vector<vector<bool>> validDistribution =
        getValidDistribuition(freqs, quantity);
    const int n = freqs.size();
    const int m = quantity.size();
    const int maxMask = 1 << m;
    // dp[i][j] := true if it's possible to distribute freqs[i..n) with selected
    // quantity represented by the bitmask j
    vector<vector<bool>> dp(n + 1, vector<bool>(maxMask));
    dp[n][maxMask - 1] = true;

    for (int i = n - 1; i >= 0; --i)
      for (int mask = 0; mask < maxMask; ++mask) {
        dp[i][mask] = dp[i + 1][mask];
        const int availableMask = ~mask & (maxMask - 1);
        for (int submask = availableMask; submask > 0;
             submask = (submask - 1) & availableMask)
          if (validDistribution[i][submask])
            dp[i][mask] = dp[i][mask] || dp[i + 1][mask | submask];
      }

    return dp[0][0];
  }

 private:
  vector<int> getFreqs(const vector<int>& nums) {
    vector<int> freqs;
    unordered_map<int, int> count;
    for (const int num : nums)
      ++count[num];
    for (const auto& [_, freq] : count)
      freqs.push_back(freq);
    return freqs;
  }

  vector<vector<bool>> getValidDistribuition(const vector<int>& freqs,
                                             const vector<int>& quantity) {
    const int maxMask = 1 << quantity.size();
    vector<vector<bool>> validDistribution(freqs.size(), vector<bool>(maxMask));
    for (int i = 0; i < freqs.size(); ++i)
      for (int mask = 0; mask < maxMask; ++mask)
        if (freqs[i] >= getQuantitySum(quantity, mask))
          validDistribution[i][mask] = true;
    return validDistribution;
  }

  // Returns the sum of the selected quantity represented by the `mask`.
  int getQuantitySum(const vector<int>& quantity, int mask) {
    int sum = 0;
    for (int i = 0; i < quantity.size(); ++i)
      if (mask >> i & 1)
        sum += quantity[i];
    return sum;
  }
};
