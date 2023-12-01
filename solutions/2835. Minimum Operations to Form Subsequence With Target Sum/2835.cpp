class Solution {
 public:
  int minOperations(vector<int>& nums, int target) {
    constexpr int kNoMissingBit = 31;
    constexpr int maxBit = 31;
    int ans = 0;
    int minMissingBit = kNoMissingBit;
    // count[i] := the number of occurrences of 2^i
    vector<int> count(maxBit + 1);

    for (const int num : nums)
      ++count[static_cast<int>(log2(num))];

    for (int bit = 0; bit < maxBit; ++bit) {
      // Check if the `bit` is in the target.
      if (target >> bit & 1) {
        // If there are available bits, use one bit.
        if (count[bit] > 0)
          --count[bit];
        else
          minMissingBit = min(minMissingBit, bit);
      }
      // If we previously missed a bit and there are available bits.
      if (minMissingBit != kNoMissingBit && count[bit] > 0) {
        --count[bit];
        // Count the operations to break the `bit` into the `minMissingBit`.
        ans += bit - minMissingBit;
        minMissingBit = kNoMissingBit;
      }
      // Combining smaller numbers costs nothing.
      count[bit + 1] += count[bit] / 2;
    }

    // Check if all target bits have been covered, otherwise return -1.
    return minMissingBit == kNoMissingBit ? ans : -1;
  }
};
