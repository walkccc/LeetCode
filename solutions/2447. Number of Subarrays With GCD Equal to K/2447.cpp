class Solution {
 public:
  int subarrayGCD(vector<int>& nums, int k) {
    int ans = 0;
    unordered_map<int, int> gcds;

    for (const int num : nums)
      if (num % k == 0) {
        unordered_map<int, int> nextGcds{{num, 1}};
        for (const auto& [prevGcd, count] : gcds)
          nextGcds[gcd(prevGcd, num)] += count;
        ans += nextGcds[k];
        gcds = std::move(nextGcds);
      } else {
        // The GCD streak stops, so fresh start from the next number.
        gcds.clear();
      }

    return ans;
  }
};
