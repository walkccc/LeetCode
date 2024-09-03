class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    const int maxNum = ranges::max(nums);
    if (maxNum == 0)
      return 0;
    const int maxBit = static_cast<int>(log2(maxNum));
    int ans = 0;
    int prefixMask = 0;  // Grows like: 10000 -> 11000 -> ... -> 11111.

    // If ans is 11100 when i = 2, it means that before we reach the last two
    // bits, 11100 is the maximum XOR we have, and we're going to explore if we
    // can get another two 1s and put them into `ans`.
    for (int i = maxBit; i >= 0; --i) {
      prefixMask |= 1 << i;
      unordered_set<int> prefixes;
      // We only care about the left parts,
      // If i = 2, nums = {1110, 1011, 0111}
      //    -> prefixes = {1100, 1000, 0100}
      for (const int num : nums)
        prefixes.insert(num & prefixMask);
      // If i = 1 and before this iteration, the ans is 10100, it means that we
      // want to grow the ans to 10100 | 1 << 1 = 10110 and we're looking for
      // XOR of two prefixes = candidate.
      const int candidate = ans | 1 << i;
      for (const int prefix : prefixes)
        if (prefixes.contains(prefix ^ candidate)) {
          ans = candidate;
          break;
        }
    }

    return ans;
  }
};
