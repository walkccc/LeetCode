class Solution {
 public:
  int minBitFlips(unsigned start, unsigned goal) {
    return popcount(start ^ goal);
  }
};
