class Solution {
 public:
  long long countExcellentPairs(vector<int>& nums, int k) {
    constexpr int kMaxBit = 30;
    // bits(num1 | num2) + bits(num1 & num2) = bits(num1) + bits(num2)
    long ans = 0;
    vector<long> count(kMaxBit);

    for (const unsigned num : unordered_set<int>(nums.begin(), nums.end()))
      ++count[popcount(num)];

    for (int i = 0; i < kMaxBit; ++i)
      for (int j = 0; j < kMaxBit; ++j)
        if (i + j >= k)
          ans += count[i] * count[j];

    return ans;
  }
};
