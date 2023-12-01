class Solution {
 public:
  int squareFreeSubsets(vector<int>& nums) {
    dp.resize(nums.size(), vector<int>(1 << (kPrimesCount + 1), -1));
    vector<int> masks;

    for (const int num : nums)
      masks.push_back(getMask(num));

    // -1 means that we take no number.
    // `usedMask` is initialized to 1 so that -1 & 1 = 1 instead of 0.
    return squareFreeSubsets(masks, 0, /*usedMask=*/1) - 1;
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  static constexpr int kPrimesCount = 10;
  const vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  vector<vector<int>> dp;

  int squareFreeSubsets(const vector<int>& masks, int i, int usedMask) {
    if (i == masks.size())
      return 1;
    if (dp[i][usedMask] != -1)
      return dp[i][usedMask];
    const int pick = masks[i] & usedMask == 0
                         ? squareFreeSubsets(masks, i + 1, usedMask | masks[i])
                         : 0;
    const int skip = squareFreeSubsets(masks, i + 1, usedMask);
    return dp[i][usedMask] = (pick + skip) % kMod;
  }

  // e.g. num = 10 = 2 * 5, so mask = 0b101 -> 0b1010 (append a 0)
  //      num = 15 = 3 * 5, so mask = 0b110 -> 0b1100 (append a 0)
  //      num = 25 = 5 * 5, so mask =  0b-1 -> 0b1..1 (invalid)
  int getMask(int num) {
    int mask = 0;
    for (int i = 0; i < primes.size(); ++i) {
      int rootCount = 0;
      while (num % primes[i] == 0) {
        num /= primes[i];
        ++rootCount;
      }
      if (rootCount >= 2)
        return -1;
      if (rootCount == 1)
        mask |= 1 << i;
    }
    return mask << 1;
  }
};
