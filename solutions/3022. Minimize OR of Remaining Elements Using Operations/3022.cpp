class Solution {
 public:
  int minOrAfterOperations(vector<int>& nums, int k) {
    constexpr int kMaxBit = 30;
    int ans = 0;
    int prefixMask = 0;  // Grows like: 10000 -> 11000 -> ... -> 11111.

    for (int i = kMaxBit; i >= 0; --i) {
      // Add the i-th bit to `prefixMask` and attempt to "turn off" the
      // currently added bit within k operations. If it's impossible, then we
      // add the i-th bit to the answer.
      prefixMask |= 1 << i;
      if (getMergeOps(nums, prefixMask, ans) > k)
        ans |= 1 << i;
    }

    return ans;
  }

 private:
  // Returns the number of merge operations to turn `prefixMask` to the target
  // by ANDing `nums`.
  int getMergeOps(const vector<int>& nums, int prefixMask, int target) {
    int mergeOps = 0;
    int ands = prefixMask;
    for (const int num : nums) {
      ands &= num;
      if ((ands | target) == target)
        ands = prefixMask;
      else
        ++mergeOps;  // Keep merging the next num.
    }
    return mergeOps;
  }
};
