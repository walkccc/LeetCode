class Solution {
 public:
  int squareFreeSubsets(vector<int>& nums) {
    vector<vector<int>> mem(nums.size(),
                            vector<int>(1 << (kPrimesCount + 1), -1));
    vector<int> masks;

    for (const int num : nums)
      masks.push_back(getMask(num));

    // -1 means that we take no number.
    // `used` is initialized to 1 so that -1 & 1 = 1 instead of 0.
    return (squareFreeSubsets(masks, 0, /*used=*/1, mem) - 1 + kMod) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  static constexpr int kPrimesCount = 10;
  static constexpr int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

  int squareFreeSubsets(const vector<int>& masks, int i, int used,
                        vector<vector<int>>& mem) {
    if (i == masks.size())
      return 1;
    if (mem[i][used] != -1)
      return mem[i][used];
    const int pick = (masks[i] & used) == 0
                         ? squareFreeSubsets(masks, i + 1, used | masks[i], mem)
                         : 0;
    const int skip = squareFreeSubsets(masks, i + 1, used, mem);
    return mem[i][used] = (pick + skip) % kMod;
  }

  // e.g. num = 10 = 2 * 5, so mask = 0b101 -> 0b1010 (append a 0)
  //      num = 15 = 3 * 5, so mask = 0b110 -> 0b1100 (append a 0)
  //      num = 25 = 5 * 5, so mask =  0b-1 -> 0b1..1 (invalid)
  int getMask(int num) {
    int mask = 0;
    for (int i = 0; i < sizeof(primes) / sizeof(int); ++i) {
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
