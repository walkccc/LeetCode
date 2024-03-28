class Solution {
 public:
  long long countExcellentPairs(vector<int>& nums, int k) {
    constexpr int kMaxBit = 30;
    // bits(num1 | num2) + bits(num1 & num2) = bits(num1) + bits(num2)
    long long ans = 0;
    vector<long long> count(kMaxBit);

    for (const int num : unordered_set<int>(nums.begin(), nums.end()))
      ++count[__builtin_popcount(num)];

    for (int i = 0; i < kMaxBit; ++i)
      for (int j = 0; j < kMaxBit; ++j)
        if (i + j >= k)
          ans += count[i] * count[j];

    return ans;
  }
};
