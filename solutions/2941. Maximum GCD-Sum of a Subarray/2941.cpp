class Solution {
 public:
  long long maxGcdSum(vector<int>& nums, int k) {
    long long ans = 0;
    // [(startIndex, gcd of subarray starting at startIndex)]
    vector<pair<int, int>> startIndexAndGcds;
    vector<long long> prefix = {0};

    for (const int num : nums)
      prefix.push_back(prefix.back() + num);

    for (int i = 0; i < nums.size(); ++i) {
      vector<pair<int, int>> nextStartIndexAndGcds;
      for (const auto& [startIndex, gcd] : startIndexAndGcds) {
        const int nextGcd = __gcd(gcd, nums[i]);
        if (nextStartIndexAndGcds.empty() ||
            nextStartIndexAndGcds.back().second != nextGcd)  // Skip duplicates.
          nextStartIndexAndGcds.emplace_back(startIndex, nextGcd);
      }
      startIndexAndGcds = move(nextStartIndexAndGcds);
      startIndexAndGcds.emplace_back(i, nums[i]);
      for (const auto& [startIndex, gcd] : startIndexAndGcds)
        if (i - startIndex + 1 >= k)
          ans = max(ans, (prefix[i + 1] - prefix[startIndex]) * gcd);
    }

    return ans;
  }
};
