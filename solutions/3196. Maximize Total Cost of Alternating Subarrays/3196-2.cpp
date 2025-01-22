class Solution {
 public:
  long long maximumTotalCost(vector<int>& nums) {
    // A small trick so that we don't need to handle the edge case and can use
    // ranged-based for loop.
    long keep = LONG_MIN / 2;  // the maximum cost if the last number is kept
    long flip = 0;             // the maximum cost if the last number is flipped

    for (const int num : nums) {
      const long keepCurr = max(keep, flip) + num;
      const long flipCurr = keep - num;
      keep = keepCurr;
      flip = flipCurr;
    }

    return max(keep, flip);
  }
};
