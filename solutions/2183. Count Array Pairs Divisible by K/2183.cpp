class Solution {
 public:
  long long countPairs(vector<int>& nums, int k) {
    long ans = 0;
    unordered_map<int, int> gcds;

    for (const int num : nums) {
      const int gcd_i = gcd(num, k);
      for (const auto& [gcd_j, count] : gcds)
        if (static_cast<long>(gcd_i) * gcd_j % k == 0)
          ans += count;
      ++gcds[gcd_i];
    }

    return ans;
  }
};
